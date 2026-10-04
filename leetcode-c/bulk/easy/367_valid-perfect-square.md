# 0367. Valid Perfect Square《有效的完全平方數》

- **Difficulty**: Easy
- **Tags**: math, binary-search
- **題目連結**: https://leetcode.com/problems/valid-perfect-square/
- **程式碼**: [`367_valid-perfect-square.c`](./367_valid-perfect-square.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定正整數 num，若它是完全平方數則回傳 true，否則回傳 false。完全平方數是某個整數與自身相乘的結果，且不可使用 sqrt 等內建函式。

**思路**：在 1 到 min(num, 46341) 間二分搜尋，將中點平方後與 num 比較。

## Problem Statement (English)

Given a positive integer num, return true if num is a perfect square or false otherwise.
A perfect square is an integer that is the square of an integer. In other words, it is the product of some integer with itself.
You must not use any built-in library function, such as sqrt.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: num = 16
Output: true
Explanation: We return true because 4 * 4 = 16 and 4 is an integer.

Input: num = 14
Output: false
Explanation: We return false because 3.742 * 3.742 = 14 and 3.742 is not an integer.
```

## 限制 Constraints

1 <= num <= 231 - 1

## 官方 C 函式簽名 Signature

```c
bool isPerfectSquare(int num) {
    
}
```
