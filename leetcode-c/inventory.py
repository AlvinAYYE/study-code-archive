"""核對題庫、C 題解與索引，並列出尚未有 C 解答的題目。"""

from __future__ import annotations

import argparse
import sys
from pathlib import Path


ROOT = Path(__file__).resolve().parent


def rows(filename: str) -> list[list[str]]:
    return [line.split("|") for line in (ROOT / filename).read_text(encoding="utf-8-sig").splitlines()]


def main() -> int:
    sys.stdout.reconfigure(encoding="utf-8")
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--missing", action="store_true", help="列出沒有 C 解答的題目")
    parser.add_argument("--limit", type=int, default=30, help="最多列出幾道缺題；0 表示全部")
    args = parser.parse_args()

    database = rows("DB_INDEX.tsv")
    curated = rows("INDEX.tsv")
    bulk = rows("BULK_INDEX.tsv")
    other = rows("OTHER_INDEX.tsv")
    indexed = curated + bulk + other
    code_files = [
        *ROOT.glob("easy/*.c"), *ROOT.glob("medium/*.c"), *ROOT.glob("hard/*.c"),
        *ROOT.glob("bulk/*/*.c"),
    ]
    sql_files = list((ROOT / "sql").glob("*.sql"))
    shell_files = list((ROOT / "shell").glob("*.sh"))
    all_files = code_files + sql_files + shell_files
    code_ids = {int(path.name.split("_", 1)[0]) for path in code_files}
    sql_ids = {int(path.name.split("_", 1)[0]) for path in sql_files}
    shell_ids = {int(path.name.split("_", 1)[0]) for path in shell_files}
    solved_ids = code_ids | sql_ids | shell_ids
    database_ids = {int(row[0]) for row in database}
    indexed_files = {row[-1].replace("\\", "/") for row in indexed}
    actual_files = {path.relative_to(ROOT).as_posix() for path in all_files}
    missing = [row for row in database if int(row[0]) not in solved_ids]
    unindexed = sorted(actual_files - indexed_files)
    broken = sorted(indexed_files - actual_files)

    print(f"題庫 {len(database)} 題；C {len(code_ids)} 題、SQL {len(sql_ids)} 題、Shell {len(shell_ids)} 題")
    print(f"已有任一語言解答 {len(solved_ids)} 題；尚缺解答 {len(missing)} 題")
    print(f"精選索引 {len(curated)} 筆；批量索引 {len(bulk)} 筆；其他語言索引 {len(other)} 筆")
    print(f"未列入索引的解答檔 {len(unindexed)}；索引指向不存在的檔案 {len(broken)}")
    if len(database_ids) != len(database):
        raise AssertionError("題庫題號重複")
    if unindexed:
        print("未列入索引：", *unindexed[:10], sep="\n  ")
    if broken:
        print("索引檔案不存在：", *broken[:10], sep="\n  ")
    if args.missing:
        selected = missing if args.limit == 0 else missing[: args.limit]
        for row in selected:
            print(f"{row[0]} | {row[1]} | {row[2]}")
    return 1 if unindexed or broken else 0


if __name__ == "__main__":
    raise SystemExit(main())
