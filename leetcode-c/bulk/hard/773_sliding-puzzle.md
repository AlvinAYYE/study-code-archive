# 0773. Sliding Puzzle《滑動拼圖》

- **Difficulty**: Hard
- **Tags**: array, dynamic-programming, backtracking, breadth-first-search, memoization, matrix
- **題目連結**: https://leetcode.com/problems/sliding-puzzle/
- **程式碼**: [`773_sliding-puzzle.c`](./773_sliding-puzzle.c) — 社群解答（repo caotrongphuoc_algorithms），已通過編譯+官方示例執行驗證

## 題目說明（中文）

在 2 × 3 棋盤中，數字 1 至 5 與空格 0 可將 0 和上下左右相鄰數字交換。求將棋盤變為 [[1,2,3],[4,5,0]] 的最少步數；若無法復原則回傳 -1。

**思路**：將棋盤壓成六字元狀態字串，對 0 的合法交換位置做廣度優先搜尋，並用已拜訪狀態避免重複；首次到達目標的層數即為答案。

## Problem Statement (English)

On an 2 x 3 board, there are five tiles labeled from 1 to 5, and an empty square represented by 0. A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.
The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].
Given the puzzle board board, return the least number of moves required so that the state of the board is solved. If it is impossible for the state of the board to be solved, return -1.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: board = [[1,2,3],[4,0,5]]
Output: 1
Explanation: Swap the 0 and the 5 in one move.

Input: board = [[1,2,3],[5,4,0]]
Output: -1
Explanation: No number of moves will make the board solved.

Input: board = [[4,1,2],[5,0,3]]
Output: 5
Explanation: 5 is the smallest number of moves that solves the board.
An example path:
After move 0: [[4,1,2],[5,0,3]]
After move 1: [[4,1,2],[0,5,3]]
After move 2: [[0,1,2],[4,5,3]]
After move 3: [[1,0,2],[4,5,3]]
After move 4: [[1,2,0],[4,5,3]]
After move 5: [[1,2,3],[4,5,0]]
```

## 限制 Constraints

board.length == 2
board[i].length == 3
0 <= board[i][j] <= 5
Each value board[i][j] is unique.

## 官方 C 函式簽名 Signature

```c
int slidingPuzzle(int** board, int boardSize, int* boardColSize) {
    
}
```
