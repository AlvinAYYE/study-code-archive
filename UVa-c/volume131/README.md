# UVa Volume 131

本卷共收錄 2 題 C 題目檔，以下依題號排序。

<a id="uva-13178_is-it-multiple-of-3"></a>
### UVa 13178 — Is it multiple of 3?／是 3 的倍數嗎？

- 原始碼：[13178_is-it-multiple-of-3.c](13178_is-it-multiple-of-3.c)
- 演算法：模運算、整除性（Number Theory）

**English description:**

For each input `N`, consider the huge decimal number formed by concatenating `1, 2, ..., N`. Determine whether that number is divisible by 3 and output the required answer without constructing the concatenation.

**中文詳細描述：**

每組輸入給 `N`，題目把 `1、2、…、N` 依序串接成一個可能非常大的十進位數，要求判斷它能否被 3 整除。利用十進位數各位和的整除規則，串接數的數字和等價於 `1` 到 `N` 的數字和，因此依 `N mod 3` 即可輸出答案，無需建立大數。

<a id="uva-13185_dpd-numbers"></a>
### UVa 13185 — DPD Numbers／不足數、完全數與過剩數

- 原始碼：[13185_dpd-numbers.c](13185_dpd-numbers.c)
- 演算法：因數枚舉（Number Theory）

**English description:**

For each positive integer `N`, sum all proper divisors smaller than `N`. Output `deficient`, `perfect`, or `abundant` according to whether that sum is less than, equal to, or greater than `N`.

**中文詳細描述：**

每組輸入一個正整數 `N`，找出所有小於 `N` 且能整除 `N` 的真因數並加總。若總和小於 `N`，輸出 `deficient`；等於 `N` 輸出 `perfect`；大於 `N` 則輸出 `abundant`。
