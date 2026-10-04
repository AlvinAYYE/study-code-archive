# 0289. Game of Life《生命遊戲》

- **Difficulty**: Medium
- **Tags**: array, matrix, simulation
- **題目連結**: https://leetcode.com/problems/game-of-life/
- **程式碼**: [`289_game-of-life.c`](./289_game-of-life.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定 m × n 的細胞棋盤，1 代表活細胞、0 代表死細胞；每個細胞只考慮周圍八個方向的鄰居。所有細胞必須同時依規則更新：活細胞有 2 或 3 個活鄰居才存活，死細胞恰有 3 個活鄰居才復活，其餘情況為死亡或維持死亡。請原地把棋盤改為下一世代，無須回傳值。

**思路**：第一輪以低位保存原狀、以 0x10 標記下一世代，計算鄰居時只讀低位，因此不會受已處理格子影響。第二輪再依高位統一寫回 0 或 1。

## Problem Statement (English)

According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."
The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):
The next state of the board is determined by applying the above rules simultaneously to every cell in the current state of the m x n grid board. In this process, births and deaths occur simultaneously.
Given the current state of the board, update the board to reflect its next state.
Note that you do not need to return anything.
Example 1:
Example 2:
Constraints:
Follow up:

## 範例 Examples

```text
Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]

Input: board = [[1,1],[1,0]]
Output: [[1,1],[1,1]]
```

## 限制 Constraints

m == board.length
n == board[i].length
1 <= m, n <= 25
board[i][j] is 0 or 1.

## 官方 C 函式簽名 Signature

```c
void gameOfLife(int** board, int boardSize, int* boardColSize) {
    
}
```
