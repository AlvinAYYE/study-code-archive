# 0507. Perfect Number《完美數》

- **Difficulty**: Easy
- **Tags**: math
- **題目連結**: https://leetcode.com/problems/perfect-number/
- **程式碼**: [`507_perfect-number.c`](./507_perfect-number.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

完美數是等於其所有正因數總和（不包含自身）的正整數。給定整數 num，若它是完美數則回傳 true，否則回傳 false。

**思路**：程式從因數和 1 開始，枚舉從 2 到平方根前的可整除因子，並將每對因子加入總和。最後比較因數和是否等於原數。

## Problem Statement (English)

A perfect number is a positive integer that is equal to the sum of its positive divisors, excluding the number itself. A divisor of an integer x is an integer that can divide x evenly.
Given an integer n, return true if n is a perfect number, otherwise return false.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: num = 28
Output: true
Explanation: 28 = 1 + 2 + 4 + 7 + 14
1, 2, 4, 7, and 14 are all divisors of 28.

Input: num = 7
Output: false
```

## 限制 Constraints

1 <= num <= 108

## 官方 C 函式簽名 Signature

```c
bool checkPerfectNumber(int num) {
    
}
```
