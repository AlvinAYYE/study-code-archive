# UVa Volume 015

本卷收錄 1 個 C 題目檔，依 UVa 題號排序。

<a id="uva-1585_score"></a>

### UVa 1585 — Score／OX 答題連續得分計算

- 原始碼：[1585_score.c](1585_score.c)
- 演算法：線性掃描、連續計數（string, simulation）

**English description:** Each test case is an `O` and `X` result string. An `O` scores one more point than the immediately preceding consecutive `O`, starting at one, while an `X` resets the streak to zero. Sum the points and print the total score for each string.

**中文詳細描述：** 輸入先給測試筆數，每筆是一串 `O` 與 `X`。連續答對時，第 1 個 `O` 得 1 分、第 2 個得 2 分，依此遞增；遇到 `X` 就把連續次數歸零，下一個 `O` 重新從 1 分開始。線性掃描並累加每次得分，逐組輸出總分。
