# 0231. Power of Two《2 的冪次》

- **Difficulty**: Easy
- **Tags**: math, bit-manipulation, recursion
- **題目連結**: https://leetcode.com/problems/power-of-two/
- **程式碼**: [`231_power-of-two.c`](./231_power-of-two.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數 n，判斷它是否為 2 的某個冪次。若存在整數 x 使 n 等於 2 的 x 次方則回傳 true，否則回傳 false。

**思路**：先排除零與負數，再利用正的 2 冪只有一個位元為 1 的特性，檢查 n & (n - 1) 是否為 0。

## Problem Statement (English)

Given an integer n, return true if it is a power of two. Otherwise, return false.
An integer n is a power of two, if there exists an integer x such that n == 2x.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: n = 1
Output: true
Explanation: 20 = 1

Input: n = 16
Output: true
Explanation: 24 = 16

Input: n = 3
Output: false
```

## 限制 Constraints

-231 <= n <= 231 - 1

## 官方 C 函式簽名 Signature

```c
bool isPowerOfTwo(int n) {
    
}
```
