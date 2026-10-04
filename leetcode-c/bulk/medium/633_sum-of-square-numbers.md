# 0633. Sum of Square Numbers《平方數之和》

- **Difficulty**: Medium
- **Tags**: math, two-pointers, binary-search
- **題目連結**: https://leetcode.com/problems/sum-of-square-numbers/
- **程式碼**: [`633_sum-of-square-numbers.c`](./633_sum-of-square-numbers.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定非負整數 c，判斷是否存在兩個整數 a、b，使 a² + b² = c。a 與 b 可以為 0，c 的範圍可達 32 位元帶符號整數的上限。

**思路**：依序枚舉 a，令剩餘值為 c-a²。對每個剩餘值以二分搜尋檢查是否存在整數 b 使 b² 等於該值。

## Problem Statement (English)

Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: c = 5
Output: true
Explanation: 1 * 1 + 2 * 2 = 5

Input: c = 3
Output: false
```

## 限制 Constraints

0 <= c <= 231 - 1

## 官方 C 函式簽名 Signature

```c
bool judgeSquareSum(int c) {
    
}
```
