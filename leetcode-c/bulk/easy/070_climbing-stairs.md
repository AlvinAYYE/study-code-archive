# 0070. Climbing Stairs《爬樓梯》

- **Difficulty**: Easy
- **Tags**: math, dynamic-programming, memoization
- **題目連結**: https://leetcode.com/problems/climbing-stairs/
- **程式碼**: [`070_climbing-stairs.c`](./070_climbing-stairs.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

有一座共 n 階的樓梯，每次只能往上走 1 階或 2 階。請計算到達頂端的不同走法數量。n 為 1 到 45 的正整數。

**思路**：以動態規劃迭代費波那契關係，僅保留前兩階的走法數並逐階更新。

## Problem Statement (English)

You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
```

## 限制 Constraints

1 <= n <= 45

## 官方 C 函式簽名 Signature

```c
int climbStairs(int n) {
    
}
```
