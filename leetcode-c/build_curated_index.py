"""Rebuild INDEX.md and INDEX.tsv from the curated C answer folders."""

from __future__ import annotations

import re
from pathlib import Path


ROOT = Path(__file__).resolve().parent
TITLE_PATTERN = re.compile(r"(?:Title-CN|繁中題名)[:：]\s*(.+?)\s*$")
BRACKETED_TITLE_PATTERN = re.compile(r"《([^》]+)》")
SLASH_TITLE_PATTERN = re.compile(r"LeetCode\s+\d+\..*／(.+?)\s*$")
NUMBERED_TITLE_PATTERN = re.compile(r"^\s*(?:LeetCode\s*)?\d+\.\s*(.+?)\s*$", re.IGNORECASE)
PARENTHETICAL_TITLE_PATTERN = re.compile(r"[（(]([^）)]+)[）)]")
LEVEL_CODES = {"Easy": "E", "Medium": "M", "Hard": "H"}


def main() -> None:
    database_rows = [
        line.split("|")
        for line in (ROOT / "DB_INDEX.tsv").read_text(encoding="utf-8-sig").splitlines()
    ]
    database = {int(row[0]): row for row in database_rows}
    existing_titles = {
        int(row[0]): row[2]
        for row in (
            line.split("|")
            for line in (ROOT / "INDEX.tsv").read_text(encoding="utf-8-sig").splitlines()
        )
        if len(row) >= 6
    }
    entries: list[tuple[int, str, str, str, str, str]] = []

    for folder in ("easy", "medium", "hard"):
        for path in (ROOT / folder).glob("*.c"):
            problem_id = int(path.name.split("_", 1)[0])
            row = database[problem_id]
            title_cn = None
            for line in path.read_text(encoding="utf-8").splitlines():
                match = TITLE_PATTERN.search(line)
                if not match:
                    match = BRACKETED_TITLE_PATTERN.search(line)
                if not match:
                    match = SLASH_TITLE_PATTERN.search(line)
                if match:
                    title_cn = match.group(1)
                    break
                numbered_title = NUMBERED_TITLE_PATTERN.search(line.strip().lstrip("/* "))
                if numbered_title:
                    title_text = numbered_title.group(1).strip()
                    parenthetical = PARENTHETICAL_TITLE_PATTERN.search(title_text)
                    if parenthetical and any(
                        0x4E00 <= ord(char) <= 0x9FFF for char in parenthetical.group(1)
                    ):
                        title_cn = parenthetical.group(1).strip()
                        break
                    if any(0x4E00 <= ord(char) <= 0x9FFF for char in title_text):
                        title_cn = title_text
                        break
            title_cn = title_cn or existing_titles.get(problem_id)
            if not title_cn:
                raise ValueError(f"Missing Title-CN comment and index title for {path}")
            entries.append(
                (
                    problem_id,
                    row[1],
                    title_cn,
                    row[2],
                    row[4],
                    path.relative_to(ROOT).as_posix(),
                )
            )

    entries.sort(key=lambda entry: entry[0])
    tsv = "".join(
        f"{problem_id:03d}|{title}|{title_cn}|{difficulty}|{tags}|{path}\n"
        for problem_id, title, title_cn, difficulty, tags, path in entries
    )
    markdown = ["# Problem List 題目總表", ""]
    markdown.extend(
        f"{problem_id:03d} | {LEVEL_CODES[difficulty]}  | {title} | {title_cn} | tags: {tags} | {path}"
        for problem_id, title, title_cn, difficulty, tags, path in entries
    )
    (ROOT / "INDEX.tsv").write_text(tsv, encoding="utf-8")
    (ROOT / "INDEX.md").write_text("\n".join(markdown) + "\n", encoding="utf-8")
    print(f"Indexed {len(entries)} curated C solutions.")


if __name__ == "__main__":
    main()
