# 0807. Max Increase to Keep City Skyline《保持城市天際線的最大增高》

- **Difficulty**: Medium
- **Tags**: array, greedy, matrix
- **題目連結**: https://leetcode.com/problems/max-increase-to-keep-city-skyline/
- **程式碼**: [`807_max-increase-to-keep-city-skyline.c`](./807_max-increase-to-keep-city-skyline.c) — 社群解答（repo DimitrisJim_leetcode_solutions），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定 n × n 建築高度矩陣，可任意提高任意棟建築（含原高為 0 者），但四個方向看到的城市天際線不得改變。求所有建築可增加高度總和的最大值；n 介於 2 與 50。

**思路**：對每列求列最大值、對每欄求欄最大值；每格至多可提高到兩者較小值，將此值與原高度的差累加。

## Problem Statement (English)

There is a city composed of n x n blocks, where each block contains a single building shaped like a vertical square prism. You are given a 0-indexed n x n integer matrix grid where grid[r][c] represents the height of the building located in the block at row r and column c.
A city's skyline is the outer contour formed by all the building when viewing the side of the city from a distance. The skyline from each cardinal direction north, east, south, and west may be different.
We are allowed to increase the height of any number of buildings by any amount (the amount can be different per building). The height of a 0-height building can also be increased. However, increasing the height of a building should not affect the city's skyline from any cardinal direction.
Return the maximum total sum that the height of the buildings can be increased by without changing the city's skyline from any cardinal direction.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: grid = [[3,0,8,4],[2,4,5,7],[9,2,6,3],[0,3,1,0]]
Output: 35
Explanation: The building heights are shown in the center of the above image.
The skylines when viewed from each cardinal direction are drawn in red.
The grid after increasing the height of buildings without affecting skylines is:
gridNew = [ [8, 4, 8, 7],
            [7, 4, 7, 7],
            [9, 4, 8, 7],
            [3, 3, 3, 3] ]

Input: grid = [[0,0,0],[0,0,0],[0,0,0]]
Output: 0
Explanation: Increasing the height of any building will result in the skyline changing.
```

## 限制 Constraints

n == grid.length
n == grid[r].length
2 <= n <= 50
0 <= grid[r][c] <= 100

## 官方 C 函式簽名 Signature

```c
int maxIncreaseKeepingSkyline(int** grid, int gridSize, int* gridColSize) {
    
}
```
