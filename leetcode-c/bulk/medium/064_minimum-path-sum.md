# 0064. Minimum Path Sum《最小路徑和》

- **Difficulty**: Medium
- **Tags**: array, dynamic-programming, matrix
- **題目連結**: https://leetcode.com/problems/minimum-path-sum/
- **程式碼**: [`064_minimum-path-sum.c`](./064_minimum-path-sum.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定填有非負數的 m × n 網格，從左上角走到右下角時只能向右或向下移動。請找出沿途格子值總和最小的路徑和。

**思路**：以 DP 預先累積第一列與第一行的路徑和。每個其餘位置取上方、左方較小的累積和，再加上目前格子的值。

## Problem Statement (English)

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

Input: grid = [[1,2,3],[4,5,6]]
Output: 12
```

## 限制 Constraints

m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 200

## 官方 C 函式簽名 Signature

```c
int minPathSum(int** grid, int gridSize, int* gridColSize) {
    
}
```
