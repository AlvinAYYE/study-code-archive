# 0065. Valid Number《有效數字》

- **Difficulty**: Hard
- **Tags**: string
- **題目連結**: https://leetcode.com/problems/valid-number/
- **程式碼**: [`065_valid-number.c`](./065_valid-number.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

判斷字串 `s` 是否為有效數字。整數可有正負號並至少含一位數字；小數可有正負號與小數點，且小數點至少一側要有數字。有效數字可再接 `e` 或 `E` 與一個帶可選正負號的整數指數，除此之外不得含其他字元。

## 解題思路

1. 指標由左到右解析；先略過前導空白與一個可選正負號。
2. 讀取小數點前的數字並計數；若有小數點，再讀取其後數字。小數點兩側至少一側要有數字。
3. 若遇到 `e` 或 `E`，讀取一個可選正負號後，指數部分必須至少有一位數字。
4. 略過尾端空白後，只有剛好抵達字串結尾才算完整合法；任何剩餘字元都使答案為 `false`。

每個字元最多讀取一次，時間複雜度為 `O(|s|)`，額外空間為 `O(1)`。

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

## 範例

```text
輸入：s = "0"
輸出：true

輸入：s = "e"
輸出：false

輸入：s = "."
輸出：false
```

## 限制

- `1 <= s.length <= 20`
- `s` 僅包含大小寫英文字母、數字 `0-9`、正號 `+`、負號 `-` 或小數點 `.`。

## 官方 C 函式簽名 Signature

```c
bool isNumber(char* s) {
    
}
```
