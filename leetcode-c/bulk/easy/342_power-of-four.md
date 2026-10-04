# 0342. Power of Four《4 的冪》

- **Difficulty**: Easy
- **Tags**: math, bit-manipulation, recursion
- **題目連結**: https://leetcode.com/problems/power-of-four/
- **程式碼**: [`342_power-of-four.c`](./342_power-of-four.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數 n，判斷它是否為 4 的冪，若是則回傳 true，否則回傳 false。當存在整數 x 使 n = 4^x 時，n 即為 4 的冪。

**思路**：以位元條件判斷：n 必須為正且只有一個位元為 1，並且該位元要落在 0x55555555 所標示的偶數位位置。

## Problem Statement (English)

Given an integer n, return true if it is a power of four. Otherwise, return false.
An integer n is a power of four, if there exists an integer x such that n == 4x.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: n = 16
Output: true

Input: n = 5
Output: false

Input: n = 1
Output: true
```

## 限制 Constraints

-231 <= n <= 231 - 1

## 官方 C 函式簽名 Signature

```c
bool isPowerOfFour(int n) {
    
}
```
