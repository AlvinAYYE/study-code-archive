# 0892. Surface Area of 3D Shapes《三維形狀的表面積》

- **Difficulty**: Easy
- **Tags**: array, math, geometry, matrix
- **題目連結**: https://leetcode.com/problems/surface-area-of-3d-shapes/
- **程式碼**: [`892_surface-area-of-3d-shapes.c`](./892_surface-area-of-3d-shapes.c) — 本專案自行撰寫並通過官方示例驗證

## 題目說明（中文）

n×n 網格的每個值表示在該格堆疊的單位立方體數量，直接相鄰的立方體會被黏合成形狀。回傳所有形狀的總表面積，且底面也必須計入。

**思路**：程式對每個非零柱先加上頂底面與四側面的 2+4v。再只與上方及左方鄰柱比較，扣除兩邊重疊高度所遮住的兩倍面積。

## Problem Statement (English)

You are given an n x n grid where you have placed some 1 x 1 x 1 cubes. Each value v = grid[i][j] represents a tower of v cubes placed on top of cell (i, j).
After placing these cubes, you have decided to glue any directly adjacent cubes to each other, forming several irregular 3D shapes.
Return the total surface area of the resulting shapes.
Note: The bottom face of each shape counts toward its surface area.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: grid = [[1,2],[3,4]]
Output: 34

Input: grid = [[1,1,1],[1,0,1],[1,1,1]]
Output: 32

Input: grid = [[2,2,2],[2,1,2],[2,2,2]]
Output: 46
```

## 限制 Constraints

n == grid.length == grid[i].length
1 <= n <= 50
0 <= grid[i][j] <= 50

## 官方 C 函式簽名 Signature

```c
int surfaceArea(int** grid, int gridSize, int* gridColSize) {
    
}
```
