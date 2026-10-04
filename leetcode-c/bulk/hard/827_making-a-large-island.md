# 0827. Making A Large Island《製作一座大島》

- **Difficulty**: Hard
- **Tags**: array, depth-first-search, breadth-first-search, union-find, matrix
- **題目連結**: https://leetcode.com/problems/making-a-large-island/
- **程式碼**: [`827_making-a-large-island.c`](./827_making-a-large-island.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定 n × n 二元矩陣，最多可將一個 0 改為 1，求操作後最大島嶼面積。島嶼由上下左右連通的 1 組成，n 最多為 500。

**思路**：先以 DFS 標記每座既有島嶼，並在根位置記錄面積與根座標；對每個 0 加總其四鄰互不重複島嶼面積再加 1，取最大值。

## Problem Statement (English)

You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.
Return the size of the largest island in grid after applying this operation.
An island is a 4-directionally connected group of 1s.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.

Input: grid = [[1,1],[1,0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.

Input: grid = [[1,1],[1,1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 4.
```

## 限制 Constraints

n == grid.length
n == grid[i].length
1 <= n <= 500
grid[i][j] is either 0 or 1.

## 官方 C 函式簽名 Signature

```c
int largestIsland(int** grid, int gridSize, int* gridColSize) {
    
}
```
