# 0007. Reverse Integer《整数反转》

- **Difficulty**: Medium
- **Tags**: math
- **題目連結**: https://leetcode.com/problems/reverse-integer/
- **程式碼**: [`007_reverse-integer.c`](./007_reverse-integer.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定一個有號 32 位元整數 x，回傳其十進位數字反轉後的值。若反轉結果超出 [-2^31, 2^31-1]，則回傳 0，且不可依賴儲存 64 位元整數。

**思路**：程式反覆取出末位數字並累積到反轉結果。每次乘以 10 前，會依正負號以 32 位元邊界檢查是否溢位，若會溢位即回傳 0。

## Problem Statement (English)

Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: x = 123
Output: 321

Input: x = -123
Output: -321

Input: x = 120
Output: 21
```

## 限制 Constraints

-231 <= x <= 231 - 1

## 官方 C 函式簽名 Signature

```c
int reverse(int x){

}
```
