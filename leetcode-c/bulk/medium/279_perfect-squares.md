# 0279. Perfect Squares《完全平方數》

- **Difficulty**: Medium
- **Tags**: math, dynamic-programming, breadth-first-search
- **題目連結**: https://leetcode.com/problems/perfect-squares/
- **程式碼**: [`279_perfect-squares.c`](./279_perfect-squares.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定正整數 n，回傳和為 n 所需的完全平方數最少個數。完全平方數是某整數的平方，例如 1、4、9、16。

**思路**：以 dp[i] 記錄湊出 i 所需的最少平方數，初始可由 dp[i - 1] + 1 得到。再枚舉所有不超過 i 的平方數 j²，以 dp[i - j²] + 1 取最小值。

## Problem Statement (English)

Given an integer n, return the least number of perfect square numbers that sum to n.
A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
```

## 限制 Constraints

1 <= n <= 104

## 官方 C 函式簽名 Signature

```c
int numSquares(int n) {
    
}
```
