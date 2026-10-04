# 0063. Unique Paths II《不同路徑 II》

- **Difficulty**: Medium
- **Tags**: array, dynamic-programming, matrix
- **題目連結**: https://leetcode.com/problems/unique-paths-ii/
- **程式碼**: [`063_unique-paths-ii.c`](./063_unique-paths-ii.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定 m × n 網格，機器人從左上角到右下角時只能向右或向下走；值為 1 的格子是障礙物，0 是可通行空格。回傳所有不經過障礙物的不同路徑數，且答案不超過 2 × 10⁹。

**思路**：配置二維 DP 陣列並以起點是否可通行初始化。對每個非障礙格，累加上方與左方的路徑數；障礙格維持為零。

## Problem Statement (English)

You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.
Return the number of possible unique paths that the robot can take to reach the bottom-right corner.
The testcases are generated so that the answer will be less than or equal to 2 * 109.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

Input: obstacleGrid = [[0,1],[0,0]]
Output: 1
```

## 限制 Constraints

m == obstacleGrid.length
n == obstacleGrid[i].length
1 <= m, n <= 100
obstacleGrid[i][j] is 0 or 1.

## 官方 C 函式簽名 Signature

```c
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
    
}
```
