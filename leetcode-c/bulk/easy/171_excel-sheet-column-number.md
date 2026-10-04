# 0171. Excel Sheet Column Number《Excel 欄編號》

- **Difficulty**: Easy
- **Tags**: math, string
- **題目連結**: https://leetcode.com/problems/excel-sheet-column-number/
- **程式碼**: [`171_excel-sheet-column-number.c`](./171_excel-sheet-column-number.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定 Excel 格式的大寫字母欄名 columnTitle，請回傳其對應的欄位編號。例如 A 為 1、Z 為 26、AA 為 27。輸入只含大寫英文字母，且長度最多為 7。

**思路**：由左至右累積 26 進位值，將目前結果乘 26 後加上字母對應的 1 至 26。

## Problem Statement (English)

Given a string columnTitle that represents the column title as appears in an Excel sheet, return its corresponding column number.
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

Input: columnTitle = "A"
Output: 1

Input: columnTitle = "AB"
Output: 28

Input: columnTitle = "ZY"
Output: 701
```

## 限制 Constraints

1 <= columnTitle.length <= 7
columnTitle consists only of uppercase English letters.
columnTitle is in the range ["A", "FXSHRXW"].

## 官方 C 函式簽名 Signature

```c
int titleToNumber(char* columnTitle) {
    
}
```
