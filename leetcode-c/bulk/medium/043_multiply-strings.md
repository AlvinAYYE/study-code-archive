# 0043. Multiply Strings《字串相乘》

- **Difficulty**: Medium
- **Tags**: math, string, simulation
- **題目連結**: https://leetcode.com/problems/multiply-strings/
- **程式碼**: [`043_multiply-strings.c`](./043_multiply-strings.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定兩個以字串表示、沒有前導零的非負整數 num1 與 num2，回傳其乘積字串。不得使用內建大整數函式庫，也不能直接將輸入轉為整數。

**思路**：以直式乘法從兩個字串的尾端逐位相乘，將每一位的和與進位累積在整數陣列中。最後略過前導零並把陣列轉回字串。

## Problem Statement (English)

Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: num1 = "2", num2 = "3"
Output: "6"

Input: num1 = "123", num2 = "456"
Output: "56088"
```

## 限制 Constraints

1 <= num1.length, num2.length <= 200
num1 and num2 consist of digits only.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.

## 官方 C 函式簽名 Signature

```c
char* multiply(char* num1, char* num2) {
    
}
```
