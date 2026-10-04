# 0913. Cat and Mouse《貓和老鼠》

- **Difficulty**: Hard
- **Tags**: math, dynamic-programming, graph, topological-sort, memoization, game-theory
- **題目連結**: https://leetcode.com/problems/cat-and-mouse/
- **程式碼**: [`913_cat-and-mouse.c`](./913_cat-and-mouse.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

在無向圖中，老鼠從節點 1 先走，貓從節點 2 後走，洞口位於節點 0，雙方每回合都必須沿一條相鄰邊移動，且貓不得進入洞口。老鼠到達洞口時獲勝，貓與老鼠位於同一節點時獲勝；若同一個雙方位置與輪到移動者的狀態重複，則為平手。假設雙方皆最佳策略，回傳老鼠勝的 1、貓勝的 2，或平手的 0。

**思路**：以「老鼠位置、貓位置、輪到誰走」建立狀態，從老鼠在洞口與雙方相遇的終局狀態反向推導。若行動方有一步可走向己方必勝子狀態即可定勝，否則所有子狀態皆為對手必勝時才判敗。

## Problem Statement (English)

A game on an undirected graph is played by two players, Mouse and Cat, who alternate turns.
The graph is given as follows: graph[a] is a list of all nodes b such that ab is an edge of the graph.
The mouse starts at node 1 and goes first, the cat starts at node 2 and goes second, and there is a hole at node 0.
During each player's turn, they must travel along one edge of the graph that meets where they are.  For example, if the Mouse is at node 1, it must travel to any node in graph[1].
Additionally, it is not allowed for the Cat to travel to the Hole (node 0).
Then, the game can end in three ways:
Given a graph, and assuming both players play optimally, return
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: graph = [[2,5],[3],[0,4,5],[1,4,5],[2,3],[0,2,3]]
Output: 0

Input: graph = [[1,3],[0],[3],[0,2]]
Output: 1
```

## 限制 Constraints

3 <= graph.length <= 50
1 <= graph[i].length < graph.length
0 <= graph[i][j] < graph.length
graph[i][j] != i
graph[i] is unique.
The mouse and the cat can always move.

## 官方 C 函式簽名 Signature

```c
int catMouseGame(int** graph, int graphSize, int* graphColSize) {
    
}
```
