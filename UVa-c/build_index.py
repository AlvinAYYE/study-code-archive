"""Build the offline UVa lookup files from the per-volume README files.

Run from any working directory with ``python UVa-c/build_index.py``.
The volume READMEs are the source of truth for bilingual descriptions.
"""

from __future__ import annotations

import csv
import re
from collections import defaultdict
from dataclasses import dataclass
from pathlib import Path


ROOT = Path(__file__).resolve().parent
HEADING = re.compile(r"^### UVa (\d+) — (.+?)／(.+?)\s*$", re.MULTILINE)
SOURCE = re.compile(r"^- 原始碼：\[[^]]+\]\(([^)]+)\)\s*$", re.MULTILINE)
ALGORITHMS = re.compile(r"^- 演算法：(.+?)\s*$", re.MULTILINE)
STATUS = re.compile(r"^- 狀態：(.+?)\s*$", re.MULTILINE)
ANCHOR = re.compile(r'<a id="(uva-[^"\n]+)"></a>')


@dataclass(frozen=True)
class Problem:
    number: int
    english_title: str
    chinese_title: str
    english_description: str
    chinese_description: str
    algorithms: str
    tags: tuple[str, ...]
    status: str
    source: str
    details: str


def paragraph(block: str, label: str, next_label: str | None = None) -> str:
    marker = f"**{label}**"
    if marker not in block:
        raise ValueError(f"missing {marker}")
    value = block.split(marker, 1)[1]
    if next_label is not None:
        value = value.split(f"**{next_label}**", 1)[0]
    value = value.strip().split("\n\n", 1)[0]
    # The catalog keeps each description in one searchable line.
    return " ".join(value.strip().split())


def source_tags(path: Path) -> tuple[str, ...]:
    header = path.read_text(encoding="utf-8-sig").split("*/", 1)[0]
    match = re.search(r"^\s*\*\s*Tags:\s*(.+?)\s*$", header, re.MULTILINE)
    if not match:
        raise ValueError(f"missing Tags in {path}")
    return tuple(tag.strip() for tag in match.group(1).split(",") if tag.strip())


def source_status(path: Path) -> str:
    """Recognize the existing tiny main-only files that always print PASS."""
    body = path.read_text(encoding="utf-8-sig").split("*/", 1)[-1]
    if "int ok = 1;" in body and len(body) < 300:
        return "僅固定 PASS 骨架"
    return ""


def read_problems() -> list[Problem]:
    problems: list[Problem] = []
    seen_sources: set[Path] = set()
    for volume in sorted(path for path in ROOT.iterdir() if path.is_dir() and path.name.startswith("volume")):
        readme = volume / "README.md"
        if not readme.is_file():
            raise ValueError(f"missing volume index: {readme}")
        contents = readme.read_text(encoding="utf-8-sig")
        headings = list(HEADING.finditer(contents))
        for index, heading in enumerate(headings):
            block = contents[heading.end() : headings[index + 1].start() if index + 1 < len(headings) else None]
            source_match = SOURCE.search(block)
            algorithm_match = ALGORITHMS.search(block)
            if not source_match or not algorithm_match:
                raise ValueError(f"missing source or algorithms after {heading.group(0)} in {readme}")
            filename = source_match.group(1)
            if Path(filename).name != filename:
                raise ValueError(f"source link must be local: {readme}: {filename}")
            source_path = volume / filename
            if not source_path.is_file() or source_path.suffix != ".c":
                raise ValueError(f"source link does not point to a C solution: {source_path}")
            if int(source_path.stem.split("_", 1)[0]) != int(heading.group(1)):
                raise ValueError(f"heading number differs from source: {source_path}")
            anchor_match = ANCHOR.search(contents[max(0, heading.start() - 160) : heading.start()])
            anchor = f"uva-{source_path.stem}"
            if not anchor_match or anchor_match.group(1) != anchor:
                raise ValueError(f"missing or mismatched anchor before {heading.group(0)} in {readme}")
            english_description = paragraph(block, "English description:", "中文詳細描述：")
            chinese_description = paragraph(block, "中文詳細描述：")
            status_match = STATUS.search(block)
            if status_match:
                status = "部分骨架／未完成" if "部分" in status_match.group(1) else "骨架／未完成"
            else:
                status = source_status(source_path)
            if len(english_description) < 35 or len(chinese_description) < 20:
                raise ValueError(f"description too short: {source_path}")
            if source_path in seen_sources:
                raise ValueError(f"duplicate source in catalog: {source_path}")
            seen_sources.add(source_path)
            problems.append(
                Problem(
                    number=int(heading.group(1)),
                    english_title=heading.group(2).strip(),
                    chinese_title=heading.group(3).strip(),
                    english_description=english_description,
                    chinese_description=chinese_description,
                    algorithms=algorithm_match.group(1).strip(),
                    tags=source_tags(source_path),
                    status=status,
                    source=source_path.relative_to(ROOT).as_posix(),
                    details=f"{readme.relative_to(ROOT).as_posix()}#{anchor}",
                )
            )
    uncatalogued = set(ROOT.rglob("*.c")) - seen_sources
    if uncatalogued:
        raise ValueError("uncatalogued C files: " + ", ".join(str(path) for path in sorted(uncatalogued)))
    return sorted(problems, key=lambda problem: (problem.number, problem.source))


def write_indexes(problems: list[Problem]) -> None:
    with (ROOT / "INDEX.tsv").open("w", encoding="utf-8", newline="") as stream:
        writer = csv.writer(stream, delimiter="\t", lineterminator="\n")
        writer.writerow(("題號", "英文題名", "中文題名", "演算法範圍", "Tags", "英文描述", "中文詳細描述", "檔案狀態", "原始碼", "詳細說明"))
        for problem in problems:
            writer.writerow(
                (
                    problem.number,
                    problem.english_title,
                    problem.chinese_title,
                    problem.algorithms,
                    ", ".join(problem.tags),
                    problem.english_description,
                    problem.chinese_description,
                    problem.status,
                    problem.source,
                    problem.details,
                )
            )

    lines = [
        "# UVa 題目索引",
        "",
        f"共 {len(problems)} 份 C 題目檔，依題號排序。使用編輯器搜尋題號、中英文題名或演算法；點選「詳細題意」可閱讀完整雙語描述。",
        "",
        "| 題號 | English title | 中文題名 | 演算法範圍 | 檔案狀態 | 詳細題意 | C 原始碼 |",
        "| ---: | --- | --- | --- | --- | --- | --- |",
    ]
    for problem in problems:
        lines.append(
            f"| {problem.number} | {problem.english_title} | {problem.chinese_title} | "
            f"{problem.algorithms} | {problem.status} | [閱讀]({problem.details}) | [程式碼]({problem.source}) |"
        )
    lines.extend(("", "需要同時搜尋英文與中文題意時，請使用 [INDEX.tsv](INDEX.tsv)。", ""))
    (ROOT / "INDEX.md").write_text("\n".join(lines), encoding="utf-8")

    by_tag: dict[str, list[Problem]] = defaultdict(list)
    for problem in problems:
        for tag in problem.tags:
            by_tag[tag].append(problem)
    tag_lines = [
        "# 依演算法搜尋",
        "",
        "標籤沿用 C 原始碼檔頭的 Tags；同一題可以出現在多個主題。按 `Ctrl+F` 搜尋演算法名稱或題號。",
        "",
        "## 標籤總覽",
        "",
        " | ".join(f"[{tag}](#{tag}) ({len(items)})" for tag, items in sorted(by_tag.items())),
        "",
    ]
    for tag, items in sorted(by_tag.items()):
        tag_lines.extend((f"## {tag}", "", "| 題號 | 題目 | 詳細題意 |", "| ---: | --- | --- |"))
        for problem in items:
            tag_lines.append(
                f"| {problem.number} | {problem.english_title}／{problem.chinese_title} | [閱讀]({problem.details}) |"
            )
        tag_lines.append("")
    (ROOT / "TOPICS.md").write_text("\n".join(tag_lines), encoding="utf-8")

    by_volume: dict[str, list[Problem]] = defaultdict(list)
    for problem in problems:
        by_volume[problem.source.split("/", 1)[0]].append(problem)
    readme_lines = [
        "# UVa Online Judge C 題庫",
        "",
        f"收錄 {len(problems)} 份 C 題目檔，分布於 {len(by_volume)} 個 `volume` 資料夾。每題的卷別 `README.md` 都有英文題名與描述、繁體中文題名與詳細描述、涵蓋的演算法，以及原始碼連結。",
        "",
        "## 如何找題目",
        "",
        "1. **知道題號或題名**：開啟 [題目總索引](INDEX.md)，搜尋英文或中文題名，並點選詳細題意或原始碼。",
        "2. **只記得題意片段**：開啟 [完整雙語索引](INDEX.tsv)，搜尋英文或中文描述。TSV 可用文字編輯器開啟，亦可用試算表依欄位篩選。",
        "3. **想依演算法練習**：開啟 [演算法主題索引](TOPICS.md)，尋找 `dynamic-programming`、`graph`、`string` 等標籤，再點選題目說明。",
        "4. **想依 UVa 分卷瀏覽**：使用下方卷別目錄；各卷 README 收錄每題完整介紹及相對路徑連結。",
        "",
        "所有連結均為相對路徑，可在本機離線瀏覽。",
        "",
        "## 卷別目錄",
        "",
        "| 分卷 | 題數 | 收錄題號 |",
        "| --- | ---: | --- |",
    ]
    for volume, items in sorted(by_volume.items()):
        numbers = sorted({item.number for item in items})
        span = str(numbers[0]) if len(numbers) == 1 else f"{numbers[0]}–{numbers[-1]}"
        readme_lines.append(f"| [{volume}]({volume}/README.md) | {len(items)} | {span} |")
    readme_lines.extend(
        (
            "",
            "## 索引說明",
            "",
            "- `volume100` 收錄 UVa 10069 的兩種 C 解法：二維 DP 與一維滾動 DP，可直接比較空間用量。",
            "- 索引建置會檢查每個 C 檔都有對應題目、英中描述、演算法範圍與有效連結。",
            "",
            "## 編譯範例",
            "",
            "在儲存庫根目錄使用 GCC 編譯單題，例如：",
            "",
            "```powershell",
            "gcc -std=c11 -O2 UVa-c/volume001/100_the-3n-plus-1-problem.c -o uva100.exe",
            ".\\uva100.exe",
            "```",
            "",
            "## 更新索引",
            "",
            "新增 C 題目檔後，先在對應卷別 README 補上雙語題意和演算法，再執行 `python UVa-c/build_index.py`。腳本會檢查每個 `.c` 是否都有對應條目，並更新本頁、`INDEX.md`、`INDEX.tsv`、`TOPICS.md`。",
            "",
        )
    )
    (ROOT / "README.md").write_text("\n".join(readme_lines), encoding="utf-8")


if __name__ == "__main__":
    entries = read_problems()
    write_indexes(entries)
    print(f"Indexed {len(entries)} C problem files in {len({problem.source.split('/')[0] for problem in entries})} volumes.")
