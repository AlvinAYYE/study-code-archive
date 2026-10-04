# 0292. Nim Game《尼姆遊戲》

- **Difficulty**: Easy
- **Tags**: math, brainteaser, game-theory
- **題目連結**: https://leetcode.com/problems/nim-game/
- **程式碼**: [`292_nim-game.c`](./292_nim-game.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

有一堆 n 顆石頭，兩位玩家輪流移除 1 到 3 顆，移除最後一顆者獲勝，且你先手。假設雙方都採最佳策略，判斷你能否獲勝。

**思路**：程式直接利用必敗局面為 4 的倍數：面對其他數量時可移除適當顆數，使對手面對 4 的倍數。因此只要檢查 n % 4 是否非零。

## Problem Statement (English)

You are playing the following Nim Game with your friend:
Given n, the number of stones in the heap, return true if you can win the game assuming both you and your friend play optimally, otherwise return false.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: n = 4
Output: false
Explanation: These are the possible outcomes:
1. You remove 1 stone. Your friend removes 3 stones, including the last stone. Your friend wins.
2. You remove 2 stones. Your friend removes 2 stones, including the last stone. Your friend wins.
3. You remove 3 stones. Your friend removes the last stone. Your friend wins.
In all outcomes, your friend wins.

Input: n = 1
Output: true

Input: n = 2
Output: true
```

## 限制 Constraints

1 <= n <= 231 - 1

## 官方 C 函式簽名 Signature

```c
bool canWinNim(int n) {
    
}
```
