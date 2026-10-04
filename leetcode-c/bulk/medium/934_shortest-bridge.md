# 0934. Shortest Bridge《最短橋》

- **Difficulty**: Medium
- **Tags**: array, depth-first-search, breadth-first-search, matrix
- **題目連結**: https://leetcode.com/problems/shortest-bridge/
- **程式碼**: [`934_shortest-bridge.c`](./934_shortest-bridge.c) — 社群解答（repo caotrongphuoc_algorithms），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定 n × n 二進位矩陣 grid，1 為陸地、0 為水，且其中恰有兩座以四方向連通定義的島嶼。你可以把 0 變成 1 來連接兩島。請回傳所需翻轉水格數的最小值。

**思路**：先以 DFS 找到並標記第一座島，將其所有格子加入佇列；再從整座島進行多來源 BFS 擴張，首次碰到另一座島時的層數就是最少翻轉數。

## Problem Statement (English)

You are given an n x n binary matrix grid where 1 represents land and 0 represents water.
An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.
You may change 0's to 1's to connect the two islands to form one island.
Return the smallest number of 0's you must flip to connect the two islands.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: grid = [[0,1],[1,0]]
Output: 1

Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
Output: 2

Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
Output: 1
```

## 限制 Constraints

n == grid.length == grid[i].length
2 <= n <= 100
grid[i][j] is either 0 or 1.
There are exactly two islands in grid.

## 官方 C 函式簽名 Signature

```c
int shortestBridge(int** grid, int gridSize, int* gridColSize) {
    
}
```
