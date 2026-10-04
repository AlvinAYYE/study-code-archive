# 0062. Unique Paths《不同路徑》

- **Difficulty**: Medium
- **Tags**: math, dynamic-programming, combinatorics
- **題目連結**: https://leetcode.com/problems/unique-paths/
- **程式碼**: [`062_unique-paths.c`](./062_unique-paths.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

機器人從 m × n 網格的左上角出發，只能向右或向下移動，目標是右下角。回傳可到達目標的不同路徑數，且測資保證答案不超過 2 × 10⁹。

**思路**：使用二維動態規劃，第一列與第一行的路徑數皆設為 1。其餘格子的值為上方與左方路徑數之和。

## Problem Statement (English)

There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.
The test cases are generated so that the answer will be less than or equal to 2 * 109.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: m = 3, n = 7
Output: 28

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
```

## 限制 Constraints

1 <= m, n <= 100

## 官方 C 函式簽名 Signature

```c
int uniquePaths(int m, int n) {
    
}
```
