# LeetCode in C — 完整題庫 + 精選雙語解答（USB 随身版）

## 內容組成

1. **完整題庫 2914 題**（`problems\`，取自 <https://github.com/mcaupybugs/leetcode-problems-db>）
   每題一個 JSON：官方英文題面 description / examples / constraints / hints / topics / difficulty / **code_snippets.c（LeetCode 官方 C 函式簽名）**；部分題目另有英文官方題解 solution 欄。
   統計與標籤總覽見 `DB_STATS.md`；全題索引見 `DB_INDEX.tsv`（2914 列，可直接用 Excel 開）。
   難度分布：Easy 763 / Medium 1464 / Hard 686。

2. **精選 33 題完整 C 解答**（`easy\ medium\ hard\`，11 Easy / 14 Medium / 8 Hard，難度以官方為準），每題 .c 檔皆含：
   - **官方題目描述**（英文原文，抓取自資料源）
   - **中文題目說明 + 思路**（繁體中文，自官方英文題面翻譯；leetcode.cn 官方簡體被雲端防護擋下無法批量抓取）
   - **可編譯、可執行的 C 解答**（附 `main()` 本地測試，過關印 `PASS`）
   - **LeetCode 官方 C 函式簽名**（與線上 stub 一致，可直接貼回 LeetCode）
   全部 33 題已實際編譯+執行驗證 PASS。

3. **社群批量 C 解答**（`bulk\easy|medium|hard\`，共 **935 題**：500 Easy / 353 Medium / 82 Hard，見 BULK_INDEX.tsv）：
   自網路公開解答 repo（27 個 GitHub 專案：kenjin/vli02/lightmen/zeplios/DimitrisJim/Hearen/akib/SaulLawliet/Senthil455/tongtzeho/ourhouchmohamed97 等，共 3169 個候選檔），
   每題自動組上官方示例測試（examples 轉成 C assert），**全部經過「實際編譯 + 執行 + 示例比對 PASS」驗證**（2765 檔通過，每題取首個通過者）。
   檔頭附官方英文題面 + 來源出處 + **[中文] 題目說明與思路**（由 AI 逐題摘要、以繁體中文撰寫，思路基於該檔實際程式碼；少數缺漏者以術語規則翻譯補）。每題另附**同檔名的 .md 說明檔**（如 `bulk\easy\520_detect-capital.md`）：中英雙語題面、範例、限制、中文思路、官方 C 函式簽名、以及對應 .c 的連結，可直接用任何編輯器/閱讀器開啟，無需跑編譯。
   ※ 全庫 2914 題中，目前 **941 題有可執行解答**（33 精選 + 935 批量，重疊 27；其中 162 題為本專案自行撰寫、經編譯+官方示例執行驗證——補的是社群沒有 C 解的近年題，含鏈表/二叉樹/週賽 Easy）。其餘約 1970 題多為 Design 設計題/SQL/Shell 或社群僅有 C++/Python 的高難度題，可依 Hot-100 / Easy 優先繼續分批補。

---

## 目錄結構

```
leetcode-c\
  easy\    11 題 001_two-sum.c ...(精選: 中英題面+C解答+測試)
  medium\  14 題 015_3sum.c ...
  hard\     8 題 042_trapping-rain-water.c ...
  problems\        ← 完整題庫 2913 題 JSON(英文題面+官方C簽名) + merged_problems.json
  DB_INDEX.tsv     ← 全庫索引(題號|標題|難度|slug|tags)
  DB_STATS.md      ← 全庫統計+標籤計數
  search.ps1 / search.bat   ← 模糊搜尋+tag 查閱(同時搜精選33與全庫2913)
  run.ps1   / run.bat       ← 一鍵編譯執行精選題
  INDEX.tsv / INDEX.md      ← 精選 33 題清單
  TAGS.md                   ← 精選題標籤索引
  README.md
```

## 快速模糊搜尋（非網頁）

```bat
search.bat two sum          :: 模糊搜尋(英文/數字/中文/難度/tags 皆可)
search.bat 括號              :: 中文題名搜尋
search.bat 146              :: 題號
search.bat -tags            :: 列出所有標籤與題數
search.bat -tag dp          :: tag 查閱(支援部分比對, 如 -tag dynam)
search.bat -diff hard       :: 只列 Hard
search.bat cache -edit      :: 搜尋並用編輯器打開第一筆
```

模糊演算法：連續子字串 > 詞首前綴 > 子序列(+連續加分)，多關鍵字為 AND。
結果分兩區：【精選解答 C 可執行】(33) 與【完整題庫】(2913)；加 `-only cur` / `-only db` 只查其中一區。
搜尋不需重建索引——精選區直接解析每個 .c 頂部 metadata，全庫區讀 DB_INDEX.tsv。

用完整題庫寫新題解答的流程建議：
1. `search.bat -only db 題目關鍵字` 找到題號與 JSON 檔名
2. 開 `problems\NNNN-slug.json` 看 description / examples / constraints / **code_snippets.c 的官方簽名**
3. 依精選 33 題任一檔的格式複製一份，改寫解答與 `main()` 測試，`run.bat` 驗證後歸入 easy/medium/hard 資料夾

## 本地編譯執行（每題都能跑）

```bat
run.bat 001                 :: 編譯+執行 Two Sum → PASS: 001 two-sum
run.bat trapping            :: 名稱部分比對亦可
```

或手動（任一編譯器）：

```bat
gcc -std=c11 -O2 easy\001_two-sum.c -o two.exe && two.exe
:: MSVC:
cl /std:c17 /utf-8 easy\001_two-sum.c && 001_two-sum.exe
```

本題庫全部 33 題已以 MSVC 14.44 (`/std:c17 /utf-8`) 實際編譯+執行驗證，測試全 PASS。
程式碼一律使用標準 C11（無 MSVC/gcc 專屬擴充），可直接在 gcc/MinGW 與 LeetCode 線上編譯器編譯。
檔案編碼：UTF-8 (含 BOM)，中文註解不會亂碼。

## 每題檔案結構

```
/* 標題塊: 官方英文題目 + 中文說明 + 例子 + 限制 + 官方 C 簽名 + 雙語思路 */
#include ...
/* ---- LeetCode submission ---- */   ← 提交區(函式本體), 直接複製貼回 LeetCode 可用
/* ---- 本地測試 main ---- */          ← 一般 C 編譯器可執行的測試
```

LeetCode 提交時：複製「LeetCode submission」區段的 function（含其 static helper）即可；
`main()`/測試部分不要貼（LeetCode 會自己接 main 呼叫你的 function）。

## 題目清單

| # | 難度 | 題目 | tags |
|---|------|------|------|
| 001 Two Sum | Easy | 兩數之和 | array, hash-table |
| 007 Reverse Integer | **Medium** | 整數反轉 | math |
| 009 Palindrome Number | Easy | 迴文數 | math |
| 013 Roman to Integer | Easy | 羅馬轉整數 | string, hash-table |
| 014 Longest Common Prefix | Easy | 最長共同前綴 | string |
| 020 Valid Parentheses | Easy | 有效的括號 | stack, string |
| 021 Merge Two Sorted Lists | Easy | 合併兩個有序鏈表 | linked-list |
| 053 Maximum Subarray | **Medium** | 最大子陣列和 | dp, divide-conquer |
| 070 Climbing Stairs | Easy | 爬樓梯 | dp, math |
| 104 Max Depth of Binary Tree | Easy | 二叉樹最大深度 | tree, dfs |
| 121 Best Time to Buy/Sell Stock | Easy | 買賣股票最佳時機 | array, dp |
| 136 Single Number | Easy | 只出現一次的數字 | bit-manipulation |
| 169 Majority Element | Easy | 多數元素 | array, voting |
| 002 Add Two Numbers | Medium | 兩數相加 | linked-list, math |
| 003 Longest Substring W/O Repeat | Medium | 無重複字元最長子字串 | sliding-window |
| 005 Longest Palindromic Substring | Medium | 最長迴文子字串 | dp, two-pointers |
| 015 3Sum | Medium | 三數之和 | sorting, two-pointers |
| 022 Generate Parentheses | Medium | 括號生成 | backtracking |
| 046 Permutations | Medium | 全排列 | backtracking |
| 049 Group Anagrams | Medium | 字母異位詞分組 | hash-table, sorting |
| 056 Merge Intervals | Medium | 合併區間 | sorting, greedy |
| 102 Binary Tree Level Order | Medium | 二叉樹層序遍歷 | bfs, tree |
| 146 LRU Cache | Medium | LRU 快取 | design, linked-list |
| 200 Number of Islands | Medium | 島嶼數量 | dfs, bfs, matrix |
| 322 Coin Change | Medium | 硬幣找零 | dp |
| 004 Median of Two Sorted Arrays | Hard | 兩正序數組中位數 | binary-search |
| 010 Regular Expression Matching | Hard | 正則表達式匹配 | dp, recursion |
| 023 Merge K Sorted Lists | Hard | 合併K個升序鏈表 | heap, divide-conquer |
| 042 Trapping Rain Water | Hard | 接雨水 | two-pointers, stack |
| 051 N-Queens | Hard | N 皇后 | backtracking |
| 076 Minimum Window Substring | Hard | 最小覆蓋子串 | sliding-window |
| 084 Largest Rectangle in Histogram | Hard | 柱狀圖最大矩形 | monotonic-stack |
| 239 Sliding Window Maximum | Hard | 滑動視窗最大值 | deque, sliding-window |

（完整 machine-readable 清單見 `INDEX.tsv`；標籤索引見 `TAGS.md`。）

---

# English

Two layers on this USB:

- **Full LeetCode free problem DB (2913 problems)** in `problems\` — one JSON per problem with the official English statement, examples, constraints, hints, topics, difficulty, and the official C function signature (`code_snippets.c`). Plus `DB_INDEX.tsv` and `DB_STATS.md`. Source: the GitHub dataset above (statements only; it ships no C solutions).
- **33 curated fully-solved problems (11 Easy / 14 Medium / 8 Hard)**. Each `.c` file embeds the
official English statement (fetched from the dataset above), a
Traditional-Chinese explanation, the solution matching LeetCode's official C
signature, and a local `main()` test that prints `PASS`/`FAIL`.

- Every file compiled & run with MSVC `/std:c17 /utf-8`, all tests PASS; code is plain C11 (no compiler extensions) and also builds with gcc `-std=c11` / LeetCode.
- `search.bat` = fast fuzzy search + tag browsing (pure PowerShell, no web UI).
- `run.bat <num-or-name>` = compile & run any problem with auto-detected compiler.
- To submit on LeetCode: copy the "LeetCode submission" block only (drop the test `main`).
