# 0371. Sum of Two Integers《兩整數之和》

- **Difficulty**: Medium
- **Tags**: math, bit-manipulation
- **題目連結**: https://leetcode.com/problems/sum-of-two-integers/
- **程式碼**: [`371_sum-of-two-integers.c`](./371_sum-of-two-integers.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定兩個整數 a 與 b，回傳它們的和。不得使用 + 或 - 運算子。

**思路**：以 XOR 求不含進位的和，以 AND 後左移取得進位，遞迴重複直到進位為 0。

## Problem Statement (English)

Given two integers a and b, return the sum of the two integers without using the operators + and -.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: a = 1, b = 2
Output: 3

Input: a = 2, b = 3
Output: 5
```

## 限制 Constraints

-1000 <= a, b <= 1000

## 官方 C 函式簽名 Signature

```c
int getSum(int a, int b) {
    
}
```
