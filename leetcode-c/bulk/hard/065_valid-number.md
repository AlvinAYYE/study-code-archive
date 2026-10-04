# 0065. Valid Number《有效數字》

- **Difficulty**: Hard
- **Tags**: string
- **題目連結**: https://leetcode.com/problems/valid-number/
- **程式碼**: [`065_valid-number.c`](./065_valid-number.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

判斷字串 s 是否為有效數字：整數可有正負號並至少含一位數字；小數可有正負號與小數點，且小數點至少一側要有數字。有效數字也可接 e 或 E 與一個帶可選正負號的整數指數，字串不得含其他字元。

**思路**：程式依序略過空白、可選符號、整數部分、小數部分與可選指數部分，並在各必要區段確認至少讀到一位數字。最後略過尾端空白，僅在剛好讀到字串結尾時回傳真。

## Problem Statement (English)

Given a string s, return whether s is a valid number.

For example, all the following are valid numbers: "2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789", while the following are not valid numbers: "abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53".
Formally, a valid number is defined using one of the following definitions:
An integer number is defined with an optional sign '-' or '+' followed by digits.
A decimal number is defined with an optional sign '-' or '+' followed by one of the following definitions:
An exponent is defined with an exponent notation 'e' or 'E' followed by an integer number.
The digits are defined as one or more digits.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: s = "0"
Output: true

Input: s = "e"
Output: false

Input: s = "."
Output: false
```

## 限制 Constraints

1 <= s.length <= 20
s consists of only English letters (both uppercase and lowercase), digits (0-9), plus '+', minus '-', or dot '.'.

## 官方 C 函式簽名 Signature

```c
bool isNumber(char* s) {
    
}
```
