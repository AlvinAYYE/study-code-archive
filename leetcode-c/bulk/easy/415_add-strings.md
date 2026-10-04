# 0415. Add Strings《字串相加》

- **Difficulty**: Easy
- **Tags**: math, string, simulation
- **題目連結**: https://leetcode.com/problems/add-strings/
- **程式碼**: [`415_add-strings.c`](./415_add-strings.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定兩個以字串表示的非負整數 num1 與 num2，回傳其和的字串。輸入只含數字且除數值 0 外沒有前導零；不得使用大整數函式庫，也不可直接將輸入轉成整數。

**思路**：由兩個字串末端向前逐位相加，連同進位寫入由尾端填入的緩衝區。最後視是否仍有進位，回傳完整緩衝區或其有效的後段。

## Problem Statement (English)

Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.
You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: num1 = "11", num2 = "123"
Output: "134"

Input: num1 = "456", num2 = "77"
Output: "533"

Input: num1 = "0", num2 = "0"
Output: "0"
```

## 限制 Constraints

1 <= num1.length, num2.length <= 104
num1 and num2 consist of only digits.
num1 and num2 don't have any leading zeros except for the zero itself.

## 官方 C 函式簽名 Signature

```c
char* addStrings(char* num1, char* num2) {
    
}
```
