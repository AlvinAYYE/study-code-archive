# 0509. Fibonacci Number《斐波那契數》

- **Difficulty**: Easy
- **Tags**: math, dynamic-programming, recursion, memoization
- **題目連結**: https://leetcode.com/problems/fibonacci-number/
- **程式碼**: [`509_fibonacci-number.c`](./509_fibonacci-number.c) — 社群解答（repo MainakRepositor_LeetCode-C），已通過編譯+官方示例執行驗證

## 題目說明（中文）

斐波那契數列定義為 F(0) = 0、F(1) = 1，且 n > 1 時 F(n) = F(n - 1) + F(n - 2)。給定 n，計算並回傳 F(n)。

**思路**：程式以遞迴直接實作定義，n 為 0 或 1 時回傳基底值，否則回傳前兩項遞迴結果的和。

## Problem Statement (English)

The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,
Given n, calculate F(n).
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.

Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.

Input: n = 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.

Input: n = 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
```

## 限制 Constraints

0 <= n <= 30

## 官方 C 函式簽名 Signature

```c
int fib(int n){

}
```
