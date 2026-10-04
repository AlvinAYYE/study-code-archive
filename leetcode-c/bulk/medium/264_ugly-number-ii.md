# 0264. Ugly Number II《醜數 II》

- **Difficulty**: Medium
- **Tags**: hash-table, math, dynamic-programming, heap-(priority-queue
- **題目連結**: https://leetcode.com/problems/ugly-number-ii/
- **程式碼**: [`264_ugly-number-ii.c`](./264_ugly-number-ii.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

醜數是質因數只包含 2、3、5 的正整數。給定 n，回傳第 n 個醜數，並將 1 視為第一個醜數。

**思路**：以動態規劃陣列保存已生成的醜數，並用三個指標維護下一個乘以 2、3、5 的候選值。每次選最小候選，且所有產生該值的指標都前進以去除重複。

## Problem Statement (English)

An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.
Given an integer n, return the nth ugly number.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.

Input: n = 1
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
```

## 限制 Constraints

1 <= n <= 1690

## 官方 C 函式簽名 Signature

```c
int nthUglyNumber(int n) {
    
}
```
