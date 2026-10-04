# 0405. Convert a Number to Hexadecimal《數字轉十六進位表示》

- **Difficulty**: Easy
- **Tags**: math, string, bit-manipulation
- **題目連結**: https://leetcode.com/problems/convert-a-number-to-hexadecimal/
- **程式碼**: [`405_convert-a-number-to-hexadecimal.c`](./405_convert-a-number-to-hexadecimal.c) — 社群解答（repo BlackDragonF_LeetcodeSolutions），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定一個 32 位元整數 num，回傳其小寫十六進位字串。負數須以二補數表示，結果除了數值 0 本身外不得有前導零，且不可直接使用內建函式完成轉換。

**思路**：每次取最低 4 個位元，透過字元表取得對應的十六進位字元，再將整數算術右移 4 位。從尾端填入暫存陣列，對 0 另行回傳 "0"。

## Problem Statement (English)

Given a 32-bit integer num, return a string representing its hexadecimal representation. For negative integers, two’s complement method is used.
All the letters in the answer string should be lowercase characters, and there should not be any leading zeros in the answer except for the zero itself.
Note: You are not allowed to use any built-in library method to directly solve this problem.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: num = 26
Output: "1a"

Input: num = -1
Output: "ffffffff"
```

## 限制 Constraints

-231 <= num <= 231 - 1

## 官方 C 函式簽名 Signature

```c
char* toHex(int num) {
    
}
```
