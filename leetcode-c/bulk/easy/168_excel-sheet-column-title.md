# 0168. Excel Sheet Column Title《Excel 欄名稱》

- **Difficulty**: Easy
- **Tags**: math, string
- **題目連結**: https://leetcode.com/problems/excel-sheet-column-title/
- **程式碼**: [`168_excel-sheet-column-title.c`](./168_excel-sheet-column-title.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定正整數 columnNumber，請回傳它在 Excel 欄位系統中對應的英文字母欄名。例如 1 對應 A、26 對應 Z、27 對應 AA。columnNumber 的範圍不超過 32 位元有號整數。

**思路**：將數字視為沒有 0 的 26 進位制，每次以 (n - 1) 取餘取得末位字母並更新 n，最後反轉累積的字元。

## Problem Statement (English)

Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.
For example:
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...

Input: columnNumber = 1
Output: "A"

Input: columnNumber = 28
Output: "AB"

Input: columnNumber = 701
Output: "ZY"
```

## 限制 Constraints

1 <= columnNumber <= 231 - 1

## 官方 C 函式簽名 Signature

```c
char* convertToTitle(int columnNumber) {
    
}
```
