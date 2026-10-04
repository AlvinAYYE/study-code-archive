# 0174. Dungeon Game《地下城遊戲》

- **Difficulty**: Hard
- **Tags**: array, dynamic-programming, matrix
- **題目連結**: https://leetcode.com/problems/dungeon-game/
- **程式碼**: [`174_dungeon-game.c`](./174_dungeon-game.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

騎士從左上角出發，只能向右或向下前進至右下角救出公主。格子可扣除、維持或增加生命值，且生命值在任何時刻降至 0 或以下就會死亡。請回傳保證可抵達終點所需的最小初始生命值，起點與終點格也必須計入。

**思路**：從右下角反向動態規劃，以一維 dp 記錄進入各欄後續所需的最低生命；每格取右與下的較小需求，扣除格子值後至少維持 1。

## Problem Statement (English)

The demons had captured the princess and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of m x n rooms laid out in a 2D grid. Our valiant knight was initially positioned in the top-left room and must fight his way through dungeon to rescue the princess.
The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.
Some of the rooms are guarded by demons (represented by negative integers), so the knight loses health upon entering these rooms; other rooms are either empty (represented as 0) or contain magic orbs that increase the knight's health (represented by positive integers).
To reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.
Return the knight's minimum initial health so that he can rescue the princess.
Note that any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: dungeon = [[-2,-3,3],[-5,-10,1],[10,30,-5]]
Output: 7
Explanation: The initial health of the knight must be at least 7 if he follows the optimal path: RIGHT-> RIGHT -> DOWN -> DOWN.

Input: dungeon = [[0]]
Output: 1
```

## 限制 Constraints

m == dungeon.length
n == dungeon[i].length
1 <= m, n <= 200
-1000 <= dungeon[i][j] <= 1000

## 官方 C 函式簽名 Signature

```c
int calculateMinimumHP(int** dungeon, int dungeonSize, int* dungeonColSize) {
    
}
```
