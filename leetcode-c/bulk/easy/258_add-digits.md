# 0258. Add Digits《各位數相加》

- **Difficulty**: Easy
- **Tags**: math, simulation, number-theory
- **題目連結**: https://leetcode.com/problems/add-digits/
- **程式碼**: [`258_add-digits.c`](./258_add-digits.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數 num，反覆將其各位數相加，直到結果只剩一位數，並回傳該數字。題目追問能否不用迴圈或遞迴，在 O(1) 時間完成。

**思路**：直接使用數根公式 (num - 1) % 9 + 1 計算；在 C 中 num 為 0 時也會得到 0。

## Problem Statement (English)

Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.
Example 1:
Example 2:
Constraints:
Follow up: Could you do it without any loop/recursion in O(1) runtime?

## 範例 Examples

```text
Input: num = 38
Output: 2
Explanation: The process is
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2 
Since 2 has only one digit, return it.

Input: num = 0
Output: 0
```

## 限制 Constraints

0 <= num <= 231 - 1

## 官方 C 函式簽名 Signature

```c
int addDigits(int num) {
    
}
```
