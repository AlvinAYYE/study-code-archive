# UVa Volume 110

本卷共收錄 3 題 C 題目檔，以下依題號排序。

<a id="uva-11005_cheapest-base"></a>
### UVa 11005 — Cheapest Base／最便宜的進位制

- 原始碼：[11005_cheapest-base.c](11005_cheapest-base.c)
- 演算法：進位轉換、成本枚舉（Base Conversion, Enumeration）

**English description:**

The input assigns a printing cost to each digit value from 0 to 35, followed by query integers. For every query, evaluate its representation in each base from 2 through 36 and output all bases having the minimum total digit cost.

**中文詳細描述：**

每組資料先給數值 0 到 35 各自的印刷成本，再給若干待查整數。對每個整數枚舉 2 到 36 進位，反覆取餘數以加總每一位的成本，找出最低成本並輸出所有同樣達到最低值的進位制。

<a id="uva-11059_maximum-product"></a>
### UVa 11059 — Maximum Product／最大乘積

- 原始碼：[11059_maximum-product.c](11059_maximum-product.c)
- 演算法：連續區間枚舉（Dynamic Programming, Brute Force）

**English description:**

For each sequence of integers, find the largest product among all non-empty contiguous subsequences. If no positive product is obtained, the reported result is zero; output it with the case number.

**中文詳細描述：**

每組輸入是一串整數，要在所有非空的連續子序列中找出最大乘積。實作從每個起點向右逐步累乘並更新最大值；若所有乘積皆不能使初始答案 0 變大，就輸出 0，並附上案例編號。

<a id="uva-11063_b2-sequence"></a>
### UVa 11063 — B2-Sequence／B2 數列

- 原始碼：[11063_b2-sequence.c](11063_b2-sequence.c)
- 演算法：序列檢查、雜湊標記（Array, Set）

**English description:**

A sequence is B2 when it begins with a positive value, is strictly increasing, and every sum `b[i] + b[j]` for `i ≤ j` is unique. Check each input sequence and output whether it satisfies these conditions.

**中文詳細描述：**

每組輸入給一個數列。B2 數列必須首項為正、整體嚴格遞增，而且所有 `i ≤ j` 的兩項和 `b[i]+b[j]` 皆不重複；逐項檢查順序並用標記集合記錄兩項和，最後依案例格式輸出是否為 B2 數列。
