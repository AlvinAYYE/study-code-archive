# 0233. Number of Digit One《數字 1 的個數》

- **Difficulty**: Hard
- **Tags**: math, dynamic-programming, recursion
- **題目連結**: https://leetcode.com/problems/number-of-digit-one/
- **程式碼**: [`233_number-of-digit-one.c`](./233_number-of-digit-one.c) — 社群解答（repo lennylxx_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定非負整數 n，計算從 0 到 n（含）所有整數十進位表示中，數字 1 出現的總次數。n 為 0 時答案為 0。

**思路**：遞迴取出最高位及其位權，將 0 到 n 的計數拆為完整較小位數區間與剩餘尾數。最高位為 1 和大於 1 時分別套用不同的累加公式。

## Problem Statement (English)

Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: n = 13
Output: 6

Input: n = 0
Output: 0
```

## 限制 Constraints

0 <= n <= 109

## 官方 C 函式簽名 Signature

```c
int countDigitOne(int n) {
    
}
```
