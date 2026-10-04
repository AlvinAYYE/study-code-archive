# 0263. Ugly Number《醜數》

- **Difficulty**: Easy
- **Tags**: math
- **題目連結**: https://leetcode.com/problems/ugly-number/
- **程式碼**: [`263_ugly-number.c`](./263_ugly-number.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

醜數是正整數，且其質因數只可為 2、3、5。給定整數 n，判斷 n 是否為醜數；1 視為醜數，非正數不是。

**思路**：依序持續除去 5、3、2 的所有因子。最後剩下 1 才回傳 true。

## Problem Statement (English)

An ugly number is a positive integer which does not have a prime factor other than 2, 3, and 5.
Given an integer n, return true if n is an ugly number.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: n = 6
Output: true
Explanation: 6 = 2 × 3

Input: n = 1
Output: true
Explanation: 1 has no prime factors.

Input: n = 14
Output: false
Explanation: 14 is not ugly since it includes the prime factor 7.
```

## 限制 Constraints

-231 <= n <= 231 - 1

## 官方 C 函式簽名 Signature

```c
bool isUgly(int n) {
    
}
```
