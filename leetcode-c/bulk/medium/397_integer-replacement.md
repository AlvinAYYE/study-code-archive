# 0397. Integer Replacement《整數替換》

- **Difficulty**: Medium
- **Tags**: dynamic-programming, greedy, bit-manipulation, memoization
- **題目連結**: https://leetcode.com/problems/integer-replacement/
- **程式碼**: [`397_integer-replacement.c`](./397_integer-replacement.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定正整數 n，可在 n 為偶數時替換成 n / 2，或在 n 為奇數時替換成 n + 1 或 n - 1。回傳將 n 變成 1 所需的最少操作次數。

**思路**：貪心地將偶數右移；奇數若低兩位為 11 且 n 大於 3 就加一，否則減一，以盡量製造更多可連續除以 2 的位元。

## Problem Statement (English)

Given a positive integer n, you can apply one of the following operations:
Return the minimum number of operations needed for n to become 1.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: n = 8
Output: 3
Explanation: 8 -> 4 -> 2 -> 1

Input: n = 7
Output: 4
Explanation: 7 -> 8 -> 4 -> 2 -> 1
or 7 -> 6 -> 3 -> 2 -> 1

Input: n = 4
Output: 2
```

## 限制 Constraints

1 <= n <= 231 - 1

## 官方 C 函式簽名 Signature

```c
int integerReplacement(int n) {
    
}
```
