# 0357. Count Numbers with Unique Digits《計算各位數字不同的數字個數》

- **Difficulty**: Medium
- **Tags**: math, dynamic-programming, backtracking
- **題目連結**: https://leetcode.com/problems/count-numbers-with-unique-digits/
- **程式碼**: [`357_count-numbers-with-unique-digits.c`](./357_count-numbers-with-unique-digits.c) — 社群解答（repo ourhouchmohamed97_LeetCode_in_C），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數 n，計算所有滿足 0 <= x < 10^n 且十進位各位數字皆不重複的整數 x 數量。回傳該數量。

**思路**：以排列組合逐位計數：第一位有 9 種，後續每位可用數字數遞減，累加每種位數的數量。

## Problem Statement (English)

Given an integer n, return the count of all numbers with unique digits, x, where 0 <= x < 10n.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: n = 2
Output: 91
Explanation: The answer should be the total numbers in the range of 0 ≤ x < 100, excluding 11,22,33,44,55,66,77,88,99

Input: n = 0
Output: 1
```

## 限制 Constraints

0 <= n <= 8

## 官方 C 函式簽名 Signature

```c
int countNumbersWithUniqueDigits(int n) {
    
}
```
