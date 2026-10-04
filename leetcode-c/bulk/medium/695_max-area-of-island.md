# 0695. Max Area of Island《島嶼的最大面積》

- **Difficulty**: Medium
- **Tags**: array, depth-first-search, breadth-first-search, union-find, matrix
- **題目連結**: https://leetcode.com/problems/max-area-of-island/
- **程式碼**: [`695_max-area-of-island.c`](./695_max-area-of-island.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定 m × n 的 0/1 矩陣，四向相連的 1 視為一座島嶼，矩陣四周均可視為水域。請回傳最大島嶼的格子數；若沒有島嶼則回傳 0。

**思路**：逐格搜尋尚未拜訪的陸地，透過 DFS 向四個方向擴展並累計該連通塊面積。以 visited 陣列避免重複計數，持續更新最大值。

## Problem Statement (English)

You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
The area of an island is the number of cells with a value 1 in the island.
Return the maximum area of an island in grid. If there is no island, return 0.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.

Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0
```

## 限制 Constraints

m == grid.length
n == grid[i].length
1 <= m, n <= 50
grid[i][j] is either 0 or 1.

## 官方 C 函式簽名 Signature

```c
int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize) {
    
}
```
