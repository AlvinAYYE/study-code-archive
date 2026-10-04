# 0877. Stone Game《石子遊戲》

- **Difficulty**: Medium
- **Tags**: array, math, dynamic-programming, game-theory
- **題目連結**: https://leetcode.com/problems/stone-game/
- **程式碼**: [`877_stone-game.c`](./877_stone-game.c) — 社群解答（repo Senthil455_Leetcode-Code），已通過編譯+官方示例執行驗證

## 題目說明（中文）

Alice 與 Bob 輪流從一列偶數堆石子的任一端取走整堆，Alice 先手，總石子數為奇數而不會平手。雙方皆採最佳策略，判斷 Alice 最後能否取得較多石子。

**思路**：程式直接回傳 true。它採用本題偶數堆且總數為奇數時 Alice 必勝的結論，而未另外執行動態規劃或模擬。

## Problem Statement (English)

Alice and Bob play a game with piles of stones. There are an even number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].
The objective of the game is to end with the most stones. The total number of stones across all the piles is odd, so there are no ties.
Alice and Bob take turns, with Alice starting first. Each turn, a player takes the entire pile of stones either from the beginning or from the end of the row. This continues until there are no more piles left, at which point the person with the most stones wins.
Assuming Alice and Bob play optimally, return true if Alice wins the game, or false if Bob wins.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: piles = [5,3,4,5]
Output: true
Explanation: 
Alice starts first, and can only take the first 5 or the last 5.
Say she takes the first 5, so that the row becomes [3, 4, 5].
If Bob takes 3, then the board is [4, 5], and Alice takes 5 to win with 10 points.
If Bob takes the last 5, then the board is [3, 4], and Alice takes 4 to win with 9 points.
This demonstrated that taking the first 5 was a winning move for Alice, so we return true.

Input: piles = [3,7,2,3]
Output: true
```

## 限制 Constraints

2 <= piles.length <= 500
piles.length is even.
1 <= piles[i] <= 500
sum(piles[i]) is odd.

## 官方 C 函式簽名 Signature

```c
bool stoneGame(int* piles, int pilesSize) {
    
}
```
