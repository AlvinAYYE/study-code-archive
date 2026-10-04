# 0400. Nth Digit《第 N 位數字》

- **Difficulty**: Medium
- **Tags**: math, binary-search
- **題目連結**: https://leetcode.com/problems/nth-digit/
- **程式碼**: [`400_nth-digit.c`](./400_nth-digit.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

無限整數序列為 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...。給定正整數 n，回傳此序列的第 n 個數字。

**思路**：先扣除一位數、兩位數等各位數區段的總位元數，找出目標所在整數，再透過除法取得該整數中的指定數字。

## Problem Statement (English)

Given an integer n, return the nth digit of the infinite integer sequence [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...].
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: n = 3
Output: 3

Input: n = 11
Output: 0
Explanation: The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
```

## 限制 Constraints

1 <= n <= 231 - 1

## 官方 C 函式簽名 Signature

```c
int findNthDigit(int n) {
    
}
```
