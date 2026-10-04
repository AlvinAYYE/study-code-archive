# 0883. Projection Area of 3D Shapes《三維形狀的投影面積》

- **Difficulty**: Easy
- **Tags**: array, math, geometry, matrix
- **題目連結**: https://leetcode.com/problems/projection-area-of-3d-shapes/
- **程式碼**: [`883_projection-area-of-3d-shapes.c`](./883_projection-area-of-3d-shapes.c) — 社群解答（repo DimitrisJim_leetcode_solutions），已通過編譯+官方示例執行驗證

## 題目說明（中文）

n×n 網格的 grid[i][j] 代表該格上堆疊的單位立方體數量。從 xy、yz、zx 三個平面觀察這些立方體的投影，回傳三個投影面積的總和。

**思路**：程式累加非零格數作為俯視投影，並累加每一列的最大高度。它同時維護每一欄的最大高度，最後加上各欄最大值作為第三個投影。

## Problem Statement (English)

You are given an n x n grid where we place some 1 x 1 x 1 cubes that are axis-aligned with the x, y, and z axes.
Each value v = grid[i][j] represents a tower of v cubes placed on top of the cell (i, j).
We view the projection of these cubes onto the xy, yz, and zx planes.
A projection is like a shadow, that maps our 3-dimensional figure to a 2-dimensional plane. We are viewing the "shadow" when looking at the cubes from the top, the front, and the side.
Return the total area of all three projections.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: grid = [[1,2],[3,4]]
Output: 17
Explanation: Here are the three projections ("shadows") of the shape made with each axis-aligned plane.

Input: grid = [[2]]
Output: 5

Input: grid = [[1,0],[0,2]]
Output: 8
```

## 限制 Constraints

n == grid.length == grid[i].length
1 <= n <= 50
0 <= grid[i][j] <= 50

## 官方 C 函式簽名 Signature

```c
int projectionArea(int** grid, int gridSize, int* gridColSize) {
    
}
```
