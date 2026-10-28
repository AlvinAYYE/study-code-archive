"""Rebuild the SQL and Shell answer index from the answer files."""

from __future__ import annotations

import re
from pathlib import Path


ROOT = Path(__file__).resolve().parent
TITLE_SEPARATOR = re.compile(r"[／/](.+)$")
TITLE_LABEL = re.compile(r"(?:Title-CN|繁中題名)\s*[:：]\s*(.+)$", re.IGNORECASE)
NUMBERED_TITLE = re.compile(r"^\s*(?:LeetCode\s*)?\d+\.\s*(.+)$", re.IGNORECASE)


def extract_chinese_title(lines: list[str], comment_prefix: str) -> str | None:
    comments = [
        line.strip()[len(comment_prefix) :].strip()
        for line in lines
        if line.strip().startswith(comment_prefix)
        and line.strip() != "#!/bin/sh"
    ]
    for comment in comments:
        match = TITLE_LABEL.search(comment)
        if match:
            return match.group(1).strip()

    for comment in comments:
        match = NUMBERED_TITLE.search(comment)
        if not match:
            continue
        title_text = match.group(1).strip()
        separator_match = TITLE_SEPARATOR.search(title_text)
        if separator_match:
            return separator_match.group(1).strip().rstrip("）)")
        title = re.split(r"[（(]", title_text, maxsplit=1)[0].strip()
        if any(0x4E00 <= ord(char) <= 0x9FFF for char in title):
            return title
        parenthetical = re.search(r"[（(]([^）)]+)", title_text)
        if parenthetical and any(
            0x4E00 <= ord(char) <= 0x9FFF for char in parenthetical.group(1)
        ):
            return parenthetical.group(1).strip()
    return None


def main() -> None:
    database_rows = [
        line.split("|")
        for line in (ROOT / "DB_INDEX.tsv").read_text(encoding="utf-8-sig").splitlines()
    ]
    database = {int(row[0]): row for row in database_rows}
    entries: list[tuple[str, str, str, str, str, str]] = []

    for language, folder, suffix, comment_prefix in (
        ("SQL", "sql", ".sql", "--"),
        ("Shell", "shell", ".sh", "#"),
    ):
        for path in sorted((ROOT / folder).glob(f"*{suffix}")):
            problem_id = int(path.name.split("_", 1)[0])
            row = database[problem_id]
            lines = path.read_text(encoding="utf-8").splitlines()
            chinese_title = extract_chinese_title(lines, comment_prefix)
            if not chinese_title:
                raise ValueError(f"Missing Traditional Chinese title in {path}")
            entries.append(
                (
                    row[0],
                    row[1],
                    chinese_title,
                    row[2],
                    language,
                    path.relative_to(ROOT).as_posix(),
                )
            )

    entries.sort(key=lambda entry: int(entry[0]))
    tsv = "".join("|".join(entry) + "\n" for entry in entries)
    markdown = [
        "# SQL 與 Shell 題解索引",
        "",
        "| 題號 | 題目 | 繁體中文題名 | 難度 | 語言 | 題解檔案 |",
        "|---:|---|---|---|---|---|",
    ]
    markdown.extend(
        f"| {problem_id} | {title} | {chinese_title} | {difficulty} | {language} | `{path}` |"
        for problem_id, title, chinese_title, difficulty, language, path in entries
    )
    (ROOT / "OTHER_INDEX.tsv").write_text(tsv, encoding="utf-8")
    (ROOT / "OTHER_INDEX.md").write_text("\n".join(markdown) + "\n", encoding="utf-8")
    print(f"Indexed {len(entries)} SQL and Shell solutions.")


if __name__ == "__main__":
    main()
