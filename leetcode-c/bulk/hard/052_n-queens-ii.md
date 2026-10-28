# 0052. N-Queens II《N 皇后 II》

- **Difficulty**: Hard
- **Tags**: backtracking
- **題目連結**: https://leetcode.com/problems/n-queens-ii/
- **程式碼**: [`052_n-queens-ii.c`](./052_n-queens-ii.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

在 `n × n` 棋盤上放置 `n` 個皇后，使任意兩個皇后都不會位於同一列、同一欄或同一條對角線。給定 `n`，請回傳所有不同合法擺法的數量，不必列出棋盤配置。

## 解題思路

1. 每列恰好放一個皇后，因此從第 0 列開始，逐欄嘗試未受攻擊的位置。
2. `buff` 中的 `-1` 代表皇后，正數代表該格被幾個已放皇后攻擊，只有 0 可以放置。
3. 放下皇后時，`set_flags` 標記同行、同欄與兩條對角線，再遞迴處理下一列。
4. 遞迴返回後撤銷相同標記，讓下一個選擇可以重用棋盤狀態。
5. 當 `row == n` 時，代表成功放滿所有列，將答案數加一。

搜尋上界約為 `O(n!)`；棋盤標記使用 `O(n^2)` 空間，遞迴深度為 `O(n)`。

## Problem Statement (English)

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Given an integer n, return the number of distinct solutions to the n-queens puzzle.
Example 1:
Example 2:
Constraints:

## 範例

```text
輸入：n = 4
輸出：2
說明：四皇后問題共有兩種不同的合法擺法。

輸入：n = 1
輸出：1
```

## 限制

- `1 <= n <= 9`

## 官方 C 函式簽名 Signature

```c
int totalNQueens(int n) {
    
}
```
