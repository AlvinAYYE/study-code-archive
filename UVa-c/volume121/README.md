# UVa Volume 121

本卷共收錄 1 題 C 題目檔，以下依題號排序。

<a id="uva-12149_feynman"></a>
### UVa 12149 — Feynman／費曼

- 原始碼：[12149_feynman.c](12149_feynman.c)
- 演算法：平方和公式（Math）

**English description:**

For each positive `N` until the terminating zero, count all axis-aligned squares of every possible size in an `N × N` grid of unit squares. Output the total count.

**中文詳細描述：**

逐筆讀入正整數 `N` 直到 0。對一個由單位正方形組成的 `N × N` 方格，要計算其中所有不同大小、邊與網格平行的正方形總數；答案為 `1²+2²+…+N²`，輸出其公式計算結果。
