# 0329. Longest Increasing Path in a Matrix《矩陣中的最長遞增路徑》

- **Difficulty**: Hard
- **Tags**: array, dynamic-programming, depth-first-search, breadth-first-search, graph, topological-sort, memoization, matrix
- **題目連結**: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
- **程式碼**: [`329_longest-increasing-path-in-a-matrix.c`](./329_longest-increasing-path-in-a-matrix.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定 m × n 整數矩陣，請回傳最長嚴格遞增路徑的長度。每一步只能向上下左右移動，不能對角線移動、不能超出邊界，也不能環繞到另一側。

**思路**：對每個格子執行記憶化 DFS，遞迴走向值更大的四鄰格。dp[x][y] 快取從該格開始的最長路徑，總答案取所有格子的最大值。

## Problem Statement (English)

Given an m x n integers matrix, return the length of the longest increasing path in matrix.
From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].

Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

Input: matrix = [[1]]
Output: 1
```

## 限制 Constraints

m == matrix.length
n == matrix[i].length
1 <= m, n <= 200
0 <= matrix[i][j] <= 231 - 1

## 官方 C 函式簽名 Signature

```c
int longestIncreasingPath(int** matrix, int matrixSize, int* matrixColSize) {
    
}
```
