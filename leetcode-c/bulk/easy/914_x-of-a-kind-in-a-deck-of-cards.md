# 0914. X of a Kind in a Deck of Cards《一副牌中的 X 張同數字》

- **Difficulty**: Easy
- **Tags**: array, hash-table, math, counting, number-theory
- **題目連結**: https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/
- **程式碼**: [`914_x-of-a-kind-in-a-deck-of-cards.c`](./914_x-of-a-kind-in-a-deck-of-cards.c) — 本專案自行撰寫並通過官方示例驗證

## 題目說明（中文）

給定整數陣列 deck，其中每個元素代表一張牌上的數字。請判斷能否把所有牌分成一組或多組，且每組大小皆為相同的 X（X 至少為 2），並且每組內所有牌的數字都相同。可以則回傳 true，否則回傳 false。

**思路**：統計每種牌面出現次數，並逐一計算所有非零次數的最大公因數；公因數至少為 2 時即可分組。

## Problem Statement (English)

You are given an integer array deck where deck[i] represents the number written on the ith card.
Partition the cards into one or more groups such that:
Return true if such partition is possible, or false otherwise.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: deck = [1,2,3,4,4,3,2,1]
Output: true
Explanation: Possible partition [1,1],[2,2],[3,3],[4,4].

Input: deck = [1,1,1,2,2,2,3,3]
Output: false
Explanation: No possible partition.
```

## 限制 Constraints

1 <= deck.length <= 104
0 <= deck[i] < 104

## 官方 C 函式簽名 Signature

```c
bool hasGroupsSizeX(int* deck, int deckSize) {
    
}
```
