# 0909. Snakes and Ladders《蛇梯棋》

- **Difficulty**: Medium
- **Tags**: array, breadth-first-search, matrix
- **題目連結**: https://leetcode.com/problems/snakes-and-ladders/
- **程式碼**: [`909_snakes-and-ladders.c`](./909_snakes-and-ladders.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定 n × n 棋盤，方格從左下角的 1 起按蛇形編號至 n²，且每列方向交替。從 1 出發時，每次擲骰可前進 1 到 6 格；落在有蛇或梯子的格子必須立即移至其指定終點，但同一次擲骰不會繼續連鎖移動。求抵達 n² 的最少擲骰次數，若無法抵達則回傳 -1。

**思路**：將格號換算為棋盤座標後，以 BFS 逐層枚舉每次可走的六個目的地；入隊前套用至多一次蛇或梯子，並以走訪標記避免重複搜尋。

## Problem Statement (English)

You are given an n x n integer matrix board where the cells are labeled from 1 to n2 in a Boustrophedon style starting from the bottom left of the board (i.e. board[n - 1][0]) and alternating direction each row.
You start on square 1 of the board. In each move, starting from square curr, do the following:
A board square on row r and column c has a snake or ladder if board[r][c] != -1. The destination of that snake or ladder is board[r][c]. Squares 1 and n2 are not the starting points of any snake or ladder.
Note that you only take a snake or ladder at most once per dice roll. If the destination to a snake or ladder is the start of another snake or ladder, you do not follow the subsequent snake or ladder.
Return the least number of dice rolls required to reach the square n2. If it is not possible to reach the square, return -1.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: board = [[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,35,-1,-1,13,-1],[-1,-1,-1,-1,-1,-1],[-1,15,-1,-1,-1,-1]]
Output: 4
Explanation: 
In the beginning, you start at square 1 (at row 5, column 0).
You decide to move to square 2 and must take the ladder to square 15.
You then decide to move to square 17 and must take the snake to square 13.
You then decide to move to square 14 and must take the ladder to square 35.
You then decide to move to square 36, ending the game.
This is the lowest possible number of moves to reach the last square, so return 4.

Input: board = [[-1,-1],[-1,3]]
Output: 1
```

## 限制 Constraints

n == board.length == board[i].length
2 <= n <= 20
board[i][j] is either -1 or in the range [1, n2].
The squares labeled 1 and n2 are not the starting points of any snake or ladder.

## 官方 C 函式簽名 Signature

```c
int snakesAndLadders(int** board, int boardSize, int* boardColSize) {
    
}
```
