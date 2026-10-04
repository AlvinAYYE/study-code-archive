# 0052. N-Queens II《N 皇后 II》

- **Difficulty**: Hard
- **Tags**: backtracking
- **題目連結**: https://leetcode.com/problems/n-queens-ii/
- **程式碼**: [`052_n-queens-ii.c`](./052_n-queens-ii.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

在 n × n 棋盤上放置 n 個皇后，使任兩個皇后都不會互相攻擊。給定 n，回傳所有不同合法擺法的數量，而非列出棋盤配置。

**思路**：逐列回溯放置皇后，棋盤緩衝區記錄各格受到行、列與對角線攻擊的次數。放置時標記受攻擊格，遞迴返回後再還原標記。

## Problem Statement (English)

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Given an integer n, return the number of distinct solutions to the n-queens puzzle.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: n = 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown.

Input: n = 1
Output: 1
```

## 限制 Constraints

1 <= n <= 9

## 官方 C 函式簽名 Signature

```c
int totalNQueens(int n) {
    
}
```
