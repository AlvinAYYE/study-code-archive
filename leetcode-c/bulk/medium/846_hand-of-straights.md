# 0846. Hand of Straights《一手順子》

- **Difficulty**: Medium
- **Tags**: array, hash-table, greedy, sorting
- **題目連結**: https://leetcode.com/problems/hand-of-straights/
- **程式碼**: [`846_hand-of-straights.c`](./846_hand-of-straights.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定手牌 hand 與 groupSize，判斷能否重新排列所有牌，使每一組恰有 groupSize 張且牌面連續。每張牌都必須被分入某一組。

**思路**：程式先排序並以雜湊表統計各牌值剩餘數量。每遇到尚未用完的最小牌值，就依序扣除其後 groupSize−1 個連續值；任何值不足即失敗。

## Problem Statement (English)

Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.
Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.
Example 1:
Example 2:
Constraints:
Note: This question is the same as 1296: https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/

## 範例 Examples

```text
Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]

Input: hand = [1,2,3,4,5], groupSize = 4
Output: false
Explanation: Alice's hand can not be rearranged into groups of 4.
```

## 限制 Constraints

1 <= hand.length <= 104
0 <= hand[i] <= 109
1 <= groupSize <= hand.length

## 官方 C 函式簽名 Signature

```c
bool isNStraightHand(int* hand, int handSize, int groupSize) {
    
}
```
