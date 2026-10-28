# LeetCode 題庫與解答

這個資料夾保存 2,913 題題目資料，以及目前已寫好的解答。整理目標是：**每題都有完整繁體中文題意、容易照著做的解題步驟、可執行解答與測試**。演算法題使用 C；資料庫與 Shell 題使用題目指定的原語言。

## 目前進度

| 類別 | 數量 | 位置 |
|---|---:|---|
| 題目原始資料 | 2,913 題 | `problems/` |
| 精選 C 解答 | 174 份 | `easy/`、`medium/`、`hard/` |
| 既有批量 C 解答 | 935 份 | `bulk/` |
| 有 C 解答的不同題目 | 1,082 題 | 以上兩類有部分重複 |
| SQL 解答 | 94 題 | `sql/` |
| Shell 解答 | 4 題 | `shell/` |
| 已有任一語言解答 | 1,180 題 | C、SQL、Shell 合計 |
| 尚無解答 | 1,733 題 | 以 `inventory.py` 重新盤點 |

數字以目前檔案為準；執行 `python leetcode-c/inventory.py --missing` 可重新盤點，`--limit 0` 會列出全部缺題。批量檔案的繁體中文題意與解說仍在逐題校訂；不能因為存在解答檔就視為中文整理已完成。原始 `problems/*.json` 只有英文來源資料，部分敘述已缺少列表內容，寫新題解時須核對完整規則。

## 從哪裡開始看

| 想找的內容 | 檔案 |
|---|---|
| 精選題：題號、英文與中文題名、難度、C 檔路徑 | `INDEX.md` 或 `INDEX.tsv` |
| 既有批量 C 解答 | `BULK_INDEX.tsv` |
| SQL 與 Shell 解答 | `OTHER_INDEX.md` 或 `OTHER_INDEX.tsv` |
| 全部題目的題號、英文題名、難度與標籤 | `DB_INDEX.tsv` |
| 題面原始資料、範例、限制與官方函式簽名 | `problems/題號-slug.json` |

精選 `.c` 檔包含繁體中文題意、例子、限制、分步解法、LeetCode 的 C 函式，以及可在本機執行的 `main()` 測試。提交到 LeetCode 時，只複製檔案標示的「提交區」及其所需標頭；`main()` 是本地測試用。

## 本機驗證

在專案根目錄執行：

```powershell
python leetcode-c/verify.py
python leetcode-c/verify.py leetcode-c/medium/008_string-to-integer-atoi.c
python leetcode-c/verify_sql.py
python leetcode-c/verify_shell.py
python leetcode-c/inventory.py --missing --limit 20
python leetcode-c/build_curated_index.py
python leetcode-c/build_other_index.py
```

`verify.py` 會把每份 C 檔分開編譯並執行其中的 `main()`。不指定檔案時，會驗證 `easy/`、`medium/`、`hard/`；可指定批量解答的檔案路徑。支援 PATH 中的 GCC／Clang，Windows 上也能尋找 Visual Studio C 編譯器。編譯產物放在暫存目錄，不會留在題庫中。`verify_sql.py` 用 SQLite 測試 SQL；MySQL 專用語法以等價查詢驗證。`verify_shell.py` 用 Git Bash 執行 Shell 題的範例。兩個 `build_*_index.py` 腳本可依解答檔重建索引。

## 補題與校訂準則

1. 先讀 `problems/` 中對應的題目資料；若來源文字缺段落，查明完整題目規則後再撰寫。
2. 用繁體中文完整交代輸入、輸出、規則、例子與限制；解法以「每一步做什麼、為何可行」說明。
3. 用題目指定語言實作：演算法題為 C，資料庫題為 SQL，Shell 題為 Shell；保留線上判題需要的函式簽名或輸出格式。
4. 為新解答加入有代表性的本地測試；C 題可用 `verify.py`。更新對應索引後，再用 `inventory.py` 檢查是否漏列。

題庫原始英文資料取自 [mcaupybugs/leetcode-problems-db](https://github.com/mcaupybugs/leetcode-problems-db)；`bulk/` 的既有 C 程式收錄自公開社群解答，個別來源標在檔案開頭或索引中。
