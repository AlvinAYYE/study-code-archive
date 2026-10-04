# 0166. Fraction to Recurring Decimal《分數轉循環小數》

- **Difficulty**: Medium
- **Tags**: hash-table, math, string
- **題目連結**: https://leetcode.com/problems/fraction-to-recurring-decimal/
- **程式碼**: [`166_fraction-to-recurring-decimal.c`](./166_fraction-to-recurring-decimal.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定分子與非零分母，請將分數以字串形式表示。若小數部分會無限循環，必須以括號包住循環區段；結果長度保證小於 10^4。輸入整數可能為負值，需正確處理符號。

**思路**：先處理符號與整數部分，再以長除法逐位產生小數；程式記錄每個餘數及其對應數字，發現相同餘數時在該位置插入括號。

## Problem Statement (English)

Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
If the fractional part is repeating, enclose the repeating part in parentheses.
If multiple answers are possible, return any of them.
It is guaranteed that the length of the answer string is less than 104 for all the given inputs.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: numerator = 1, denominator = 2
Output: "0.5"

Input: numerator = 2, denominator = 1
Output: "2"

Input: numerator = 4, denominator = 333
Output: "0.(012)"
```

## 限制 Constraints

-231 <= numerator, denominator <= 231 - 1
denominator != 0

## 官方 C 函式簽名 Signature

```c
char* fractionToDecimal(int numerator, int denominator) {
    
}
```
