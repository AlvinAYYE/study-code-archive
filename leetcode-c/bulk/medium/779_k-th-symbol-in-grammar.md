# 0779. K-th Symbol in Grammar《第 K 個文法符號》

- **Difficulty**: Medium
- **Tags**: math, bit-manipulation, recursion
- **題目連結**: https://leetcode.com/problems/k-th-symbol-in-grammar/
- **程式碼**: [`779_k-th-symbol-in-grammar.c`](./779_k-th-symbol-in-grammar.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

第 1 列為 0，之後每列將前一列的 0 替換成 01、1 替換成 10。給定 n 與 1 起算的 k，回傳第 n 列第 k 個符號；n 最多為 30。

**思路**：遞迴追到上一列的父位置 (K+1)/2；奇數位置沿用父符號，偶數位置則將父符號異或 1 反轉。

## Problem Statement (English)

We build a table of n rows (1-indexed). We start by writing 0 in the 1st row. Now in every subsequent row, we look at the previous row and replace each occurrence of 0 with 01, and each occurrence of 1 with 10.
Given two integer n and k, return the kth (1-indexed) symbol in the nth row of a table of n rows.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: n = 1, k = 1
Output: 0
Explanation: row 1: 0

Input: n = 2, k = 1
Output: 0
Explanation: 
row 1: 0
row 2: 01

Input: n = 2, k = 2
Output: 1
Explanation: 
row 1: 0
row 2: 01
```

## 限制 Constraints

1 <= n <= 30
1 <= k <= 2n - 1

## 官方 C 函式簽名 Signature

```c
int kthGrammar(int n, int k) {
    
}
```
