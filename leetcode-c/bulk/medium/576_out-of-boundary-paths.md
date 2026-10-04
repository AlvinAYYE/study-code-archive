# 0576. Out of Boundary Paths《出界的路徑數》

- **Difficulty**: Medium
- **Tags**: dynamic-programming
- **題目連結**: https://leetcode.com/problems/out-of-boundary-paths/
- **程式碼**: [`576_out-of-boundary-paths.c`](./576_out-of-boundary-paths.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

在 m × n 方格中，球從指定起點出發，每步可往上下左右相鄰格移動，也可越過邊界，最多可移動 maxMove 步。請計算能使球離開方格的路徑數，答案需對 10^9 + 7 取模。

**思路**：建立以步數、列、欄為維度的 DP；每格由前一步四個相鄰格轉移，而走出邊界的方向直接貢獻 1，所有結果皆取模。

## Problem Statement (English)

There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn]. You are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the grid crossing the grid boundary). You can apply at most maxMove moves to the ball.
Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball out of the grid boundary. Since the answer can be very large, return it modulo 109 + 7.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
Output: 6

Input: m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
Output: 12
```

## 限制 Constraints

1 <= m, n <= 50
0 <= maxMove <= 50
0 <= startRow < m
0 <= startColumn < n

## 官方 C 函式簽名 Signature

```c
int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    
}
```
