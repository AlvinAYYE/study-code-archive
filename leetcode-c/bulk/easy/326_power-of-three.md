# 0326. Power of Three《3 的冪》

- **Difficulty**: Easy
- **Tags**: math, recursion
- **題目連結**: https://leetcode.com/problems/power-of-three/
- **程式碼**: [`326_power-of-three.c`](./326_power-of-three.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數 n，若存在整數 x 使 n 等於 3 的 x 次方，回傳 true；否則回傳 false。n 可以是零或負數。

**思路**：程式利用 32 位元整數範圍內最大的 3 的冪 1162261467。當 n 為正且能整除這個常數時，n 必為 3 的冪。

## Problem Statement (English)

Given an integer n, return true if it is a power of three. Otherwise, return false.
An integer n is a power of three, if there exists an integer x such that n == 3x.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: n = 27
Output: true
Explanation: 27 = 33

Input: n = 0
Output: false
Explanation: There is no x where 3x = 0.

Input: n = -1
Output: false
Explanation: There is no x where 3x = (-1).
```

## 限制 Constraints

-231 <= n <= 231 - 1

## 官方 C 函式簽名 Signature

```c
bool isPowerOfThree(int n) {
    
}
```
