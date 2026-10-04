# 0463. Island Perimeter《島嶼周長》

- **Difficulty**: Easy
- **Tags**: array, depth-first-search, breadth-first-search, matrix
- **題目連結**: https://leetcode.com/problems/island-perimeter/
- **程式碼**: [`463_island-perimeter.c`](./463_island-perimeter.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定 0 代表水、1 代表陸地的矩形網格，格子只以水平或垂直方向相連。網格被水包圍，且恰有一座沒有湖泊的島嶼。回傳島嶼的周長。

**思路**：掃描每個陸地格先加 4 條邊，若上方或左方也是陸地便扣除重複計入的 2 條邊。累加結果即為周長。

## Problem Statement (English)

You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.
Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).
The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
Output: 16
Explanation: The perimeter is the 16 yellow stripes in the image above.

Input: grid = [[1]]
Output: 4

Input: grid = [[1,0]]
Output: 4
```

## 限制 Constraints

row == grid.length
col == grid[i].length
1 <= row, col <= 100
grid[i][j] is 0 or 1.
There is exactly one island in grid.

## 官方 C 函式簽名 Signature

```c
int islandPerimeter(int** grid, int gridSize, int* gridColSize) {
    
}
```
