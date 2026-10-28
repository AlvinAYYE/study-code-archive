"""Build the repository-wide Markdown problem catalog from local source files."""

from __future__ import annotations

import json
import re
from pathlib import Path
from urllib.parse import quote


ROOT = Path(__file__).resolve().parents[1]
CATALOG = ROOT / "題目目錄.md"


def read(path: Path) -> str:
    return path.read_text(encoding="utf-8-sig", errors="replace")


def clean(value: str) -> str:
    value = re.sub(r"<[^>]+>", " ", value)
    value = re.sub(r"\s+", " ", value).strip(" *:;—-")
    return value.replace("|", "\\|").replace("`", "'")


def excerpt(value: str, limit: int = 340) -> str:
    value = clean(value)
    return value if len(value) <= limit else value[:limit].rsplit(" ", 1)[0] + "…"


def c_section(source: str, marker: str) -> str:
    lines = source.splitlines()
    match = next(((i, line) for i, line in enumerate(lines) if marker in line), None)
    start = match[0] + 1 if match else None
    if start is None:
        return ""
    inline = match[1].split(marker, 1)[1].lstrip(" :（(").strip()
    if inline.lower().startswith(("official statement", "statement,", "source:", "翻譯自", "術語規則")):
        inline = ""
    result = [inline] if inline else []
    for line in lines[start:]:
        line = re.sub(r"^\s*\*\s?", "", line).strip()
        if not line:
            if result:
                break
            continue
        if line.startswith(("[EN]", "[中文]", "Example ", "Examples:", "Constraints:", "===", "*/")):
            break
        result.append(line)
    return " ".join(result)


def header(source: str, name: str) -> str:
    match = re.search(r"^\s*\*\s*" + re.escape(name) + r":\s*(.+)$", source, re.M)
    return match.group(1).strip() if match else ""


def row(en: str, en_desc: str, zh: str, zh_desc: str, tags: str, path: Path | list[Path]) -> str:
    paths = path if isinstance(path, list) else [path]
    assert all(item.is_file() for item in paths), paths
    links = []
    for item in paths:
        url = quote(item.relative_to(ROOT).as_posix(), safe="/.-_")
        language = {".c": "C", ".cs": "C#", ".vb": "VB"}.get(item.suffix.lower(), item.suffix[1:].upper())
        links.append(f"[{language}]({url})")
    fields = [excerpt(en, 130), excerpt(en_desc), excerpt(zh, 130), excerpt(zh_desc, 440), excerpt(tags, 180)]
    return "| " + " | ".join(fields) + " | " + "、".join(links) + " |"


def markdown_section(source: str, heading: str) -> str:
    match = re.search(r"^## " + re.escape(heading) + r"\s*$([\s\S]*?)(?=^## |\Z)", source, re.M)
    if not match:
        return ""
    paragraphs = [part.strip() for part in re.split(r"\n\s*\n", match.group(1)) if part.strip()]
    result = " ".join(paragraphs[:2])
    return "" if re.fullmatch(r"(?:Example\s*\d+:?\s*)*(?:Constraints:?)?", result) else result


def leetcode_rows() -> list[str]:
    base = ROOT / "leetcode-c"
    curated = {}
    for line in read(base / "INDEX.tsv").splitlines():
        parts = line.split("|")
        if len(parts) >= 6:
            curated[int(parts[0])] = parts
    bulk = {}
    for line in read(base / "BULK_INDEX.tsv").splitlines():
        parts = line.split("|")
        if len(parts) >= 7:
            bulk[int(parts[0])] = parts
    json_files = {}
    for candidate in (base / "problems").glob("*.json"):
        try:
            json_files[int(candidate.name.split("-", 1)[0])] = candidate
        except ValueError:
            continue
    numbers = sorted(set(curated) | set(bulk))
    rows = []
    for number in numbers:
        index = curated.get(number) or bulk[number]
        source_path = base / (index[5] if number in curated else index[6])
        if not source_path.is_file():
            continue
        source = read(source_path)
        data_path = json_files.get(number)
        data = json.loads(read(data_path)) if data_path else {}
        en = data.get("title") or index[1]
        en_desc = re.split(r"\bExample\s*1\s*:", data.get("description", ""))[0]
        if not en_desc:
            en_desc = c_section(source, "[EN] Problem")
        if not en_desc and source_path.with_suffix(".md").is_file():
            en_desc = markdown_section(read(source_path.with_suffix(".md")), "Problem Statement (English)")
        if not en_desc:
            en_desc = f"See the source file for the problem statement of {en}."
        if number == 539:
            en_desc = "Given 24-hour time strings, find the minimum difference in minutes between any two times, including across midnight."
        elif number == 637:
            en_desc = "Given a binary tree, return the average value of the nodes at each depth from top to bottom."
        zh = curated[number][2] if number in curated else bulk[number][5]
        if not zh:
            match = re.search(r"^\s*\*\s*\[中文]\s*題目\s*:\s*([^\n*]+)", source, re.M)
            zh = match.group(1).strip() if match else f"中文題名待補（{en}）"
        zh_desc = ""
        if number in curated:
            zh_desc = c_section(source, "[中文] 題目說明")
            if not zh_desc:
                match = re.search(r"題目（繁體中文）\s*\n([\s\S]*?)(?:\n\s*\*\s*\n|\n\s*\*\s*例子)", source)
                if match:
                    zh_desc = re.sub(r"\s*\*\s*", " ", match.group(1))
        else:
            notes = source_path.with_suffix(".md")
            if notes.is_file():
                zh_desc = markdown_section(read(notes), "題目說明（中文）")
            if not zh_desc:
                zh_desc = c_section(source, "[中文] 題目摘要") or c_section(source, "[中文] 題目說明")
        if not zh_desc:
            zh_desc = "原始檔未提供完整中文題意；請參閱連結中的英文題面。"
        tags = ", ".join(data.get("topics", [])) or (index[4] if number in curated else index[3])
        rows.append(row(f"LeetCode {number}. {en}", en_desc, zh, zh_desc, tags, source_path))
    return rows


def uva_rows() -> list[str]:
    rows = []
    for path in sorted((ROOT / "UVa-c").rglob("*.c"), key=lambda p: int(p.stem.split("_")[0])):
        source = read(path)
        title = re.search(r"UVa\s+\d+\s*[-–]\s*([^\n*]+)", source)
        number = path.stem.split("_")[0]
        en = title.group(1).strip() if title else path.stem.split("_", 1)[-1].replace("-", " ")
        en_desc = c_section(source, "[EN] Problem")
        zh_desc = c_section(source, "[中文] 題目說明")
        zh = header(source, "Title-CN") or en
        tags = header(source, "Tags")
        rows.append(row(f"UVa {number}. {en}", en_desc, zh, zh_desc, tags, path))
    return rows


def normalized(value: str) -> str:
    return re.sub(r"[^0-9a-z\u3400-\u9fff]", "", value.casefold())


def algorithm_project_sources(title: str, base: Path, projects: list[Path]) -> list[Path]:
    topic = title.rsplit("：", 1)[-1].rsplit(":", 1)[-1]
    key = normalized(topic)
    candidates = [p for p in projects if key and key in normalized("/".join(p.relative_to(base).parts[:-1]))]
    years = re.findall(r"(?<!\d)(?:96|101|102|104|106|107|108|109|110|111)(?!\d)", title)
    if len(candidates) > 1 and years:
        year_matches = [p for p in candidates if any(year in normalized(str(p.relative_to(base))) for year in years)]
        if year_matches:
            candidates = year_matches
    exact = [
        p for p in candidates
        if any(normalized(part) == key for part in p.relative_to(base).parts[:-1])
    ]
    if exact:
        candidates = exact
    sources = []
    ignored = {"properties", "my project"}
    for project in candidates:
        code_files = [p for p in project.parent.rglob("*") if p.is_file() and p.suffix.lower() in {".cs", ".vb"}]
        code_files = [
            p for p in code_files
            if "Designer" not in p.name and "AssemblyInfo" not in p.name
            and not any(part.casefold() in ignored for part in p.relative_to(project.parent).parts)
        ]
        sources.extend(sorted(code_files))
    return list(dict.fromkeys(sources))


def algorithm_rows() -> list[str]:
    base = ROOT / "演算法題目整理"
    projects = sorted([*base.rglob("*.csproj"), *base.rglob("*.vbproj")])
    rows = []
    for line in read(base / "搜尋索引.md").splitlines():
        if not line.startswith("| ["):
            continue
        parts = [part.strip() for part in line.strip().strip("|").split("|")]
        if len(parts) < 5:
            continue
        match = re.match(r"\[([^]]+)]\(<([^>]+)>\)", parts[0])
        if not match:
            continue
        zh, relative = match.groups()
        path = base / relative
        aliases = [item.strip() for item in parts[2].split("、")]
        english = next((item for item in aliases if re.search(r"[A-Za-z]{3}", item) and not re.search(r"[\u4e00-\u9fff]", item)), "")
        if not english:
            english = "Algorithm exercise: " + zh
        sources = [path, *algorithm_project_sources(zh, base, projects)]
        rows.append(row(english, parts[3], zh, parts[3] + " " + parts[4], ", ".join(aliases[1:5]), sources))
    return rows


CLASS_CN = {
    "C115PMIDQ01": ("列印沙漏圖案", "輸入上半部層數 L，按指定規則列印上下對稱的沙漏圖案。", "迴圈、字元圖案"),
    "C115PMIDQ02": ("判斷二的冪次", "輸入非負整數 n，判斷它是否為 2 的整數次冪並輸出 true 或 false。", "位元運算、數學"),
    "C115PMIDQ03": ("三維向量性質", "讀入多組三維向量，依題目要求計算並輸出兩向量的性質。", "向量、數學"),
    "C115PMIDQ04": ("費波那契數", "輸入 0 至 30 的整數 n，計算費波那契數列第 n 項。", "數列、動態規劃"),
    "C115PMIDQ05": ("字串編碼", "讀入多組大寫英文字串，依題目指定的編碼規則輸出轉換結果。", "字串、編碼"),
    "C1150921Q01": ("繪製菱形", "輸入菱形上半部層數，利用空白與符號列印上下對稱的菱形。", "迴圈、字元圖案"),
    "C1150921Q02": ("第 n 個費波那契數", "輸入 n，計算並輸出費波那契數列第 n 項。", "數列、動態規劃"),
    "C1150921Q03": ("位元運算子", "輸入整數並依題目要求顯示各種位元運算的結果。", "位元運算"),
    "C1150921Q04": ("階乘的質因數", "對輸入的每個 N，計算 N 階乘的各質因數及其指數，遇 0 結束。", "質數、質因數分解"),
    "C1150921Q05": ("繪製沙漏", "依輸入層數列印上下對稱的沙漏圖案。", "迴圈、字元圖案"),
    "C1150921Q06": ("數字頻率", "統計輸入資料中 0 至 9 各數字出現的次數。", "計數、字串"),
    "C1150921Q07": ("快樂數", "反覆將數字換成各位數平方和，判斷結果是否到達 1 或進入循環。", "模擬、循環偵測"),
    "C1150928Q01": ("氣泡排序", "讀入最多 100 個整數，以相鄰交換排序並輸出升序數列。", "排序、氣泡排序"),
    "C1150928Q02": ("矩陣乘法", "讀入兩個 N×N 整數矩陣，計算矩陣乘積並逐列輸出。", "矩陣、三層迴圈"),
    "C1150928Q03": ("右手法則走迷宮", "依右手沿牆規則在迷宮中移動，輸出題目要求的走訪結果。", "迷宮、模擬"),
    "C1150928Q04": ("最大正方形", "對矩陣中的指定位置，找出符合題目條件的最大正方形尺寸。", "矩陣、擴展搜尋"),
    "C1150928Q05": ("有效迴文", "忽略非英數字元與大小寫後，判斷輸入字串是否為迴文。", "字串、雙指標"),
    "C1150928Q06": ("CSV 資料解析", "讀取學生分數的 CSV 記錄，依欄位切分並處理資料。", "字串解析、CSV"),
    "C1150928Q07": ("平面點排序", "讀入多個平面座標點，依題目指定的順序排序並輸出。", "排序、座標"),
}


def class_rows() -> list[str]:
    rows = []
    for path in sorted((ROOT / "115_C_class").rglob("main.c")):
        code = path.parent.name
        source = read(path)
        match = re.search(r"Problem\s+\w+\s*:\s*([^\n*]+)", source)
        en = match.group(1).strip() if match else "Matrix Multiplication"
        comment = source.split("*/", 1)[0]
        summary = re.search(r"Input:\s*([\s\S]*?)\s*Output:\s*([\s\S]*)", comment)
        en_desc = "Input: " + clean(summary.group(1)) + "; Output: " + clean(summary.group(2)) if summary else "Read two square matrices and output their product."
        zh, zh_desc, tags = CLASS_CN[code]
        rows.append(row(f"{code}. {en}", en_desc, zh, zh_desc, tags, path))
    return rows


CONTEST = [
    ("Prime Check", "Determine whether each input integer is prime.", "質數判斷", "逐一讀入整數，判斷是否為質數並輸出 Y 或 N。", "質數、試除法"),
    ("Roman to Integer", "Convert a Roman numeral to an integer.", "羅馬數字轉整數", "讀入羅馬數字字串，依符號值與減法規則轉為整數。", "字串、模擬"),
    ("Fibonacci", "Compute a value in the Fibonacci sequence.", "費波那契數列", "依前兩項之和計算指定的費波那契數。", "數列、動態規劃"),
    ("Fixed Coin Change", "Compute change with the available fixed coin denominations.", "固定面額找零", "依固定硬幣面額拆分指定金額並計算所需硬幣。", "貪婪法、找零"),
    ("Parenthesis Pairs", "Process matching pairs of parentheses.", "括號配對", "處理輸入中的左右括號，依題目規則找出配對關係。", "字串、堆疊"),
    ("Integer Partitions", "Count or enumerate integer partitions.", "整數分拆", "將整數分拆為若干正整數之和，依題目規則計算結果。", "動態規劃、組合數"),
    ("Stair Ways 1 2 3", "Count ways to climb stairs using steps of one, two, or three.", "一次走一至三級的爬樓梯方法數", "每次可走一、二或三級，計算到達指定階數的不同走法數。", "動態規劃、遞迴"),
]


def contest_rows() -> list[str]:
    rows = []
    for path, fields in zip(sorted((ROOT / "以前比賽的code").glob("*/solution.c")), CONTEST, strict=True):
        rows.append(row(*fields, path))
    return rows


def main() -> None:
    groups = [
        ("LeetCode C 解答", leetcode_rows()),
        ("UVa C 解答", uva_rows()),
        ("演算法題目整理", algorithm_rows()),
        ("115 學年 C 課程練習", class_rows()),
        ("以前比賽的程式", contest_rows()),
    ]
    output = [
        "# 題目目錄",
        "",
        "依英文題名、英文描述、中文題名、中文詳細描述或演算法關鍵字按 `Ctrl+F` 搜尋。每列的檔案連結指向實際 C 解答；同題的多份解答優先列精選版本。",
        "",
        "本表列出已有 C 原始碼的題目；原始碼是否完成或通過評測，仍須依個別檔案確認。LeetCode 尚未寫解答的完整英文題庫另見 [DB_INDEX.tsv](leetcode-c/DB_INDEX.tsv)。部分舊題僅有原始檔內的中英混合摘要，表格保留來源文字，詳細題意請點開對應檔案核對。英文題名若原題只有中文，使用便於搜尋的英文別名。",
        "",
    ]
    for title, rows in groups:
        output.extend([
            f"## {title}（{len(rows)} 題）", "",
            "| 英文題目名 | 英文描述 | 中文題目名 | 中文詳細描述 | 涵蓋的演算法範圍 | 檔案位置 |",
            "|---|---|---|---|---|---|",
            *rows, "",
        ])
    CATALOG.write_text("\n".join(output), encoding="utf-8")
    print(f"Wrote {CATALOG.name}: " + ", ".join(f"{title} {len(rows)}" for title, rows in groups))


if __name__ == "__main__":
    main()
