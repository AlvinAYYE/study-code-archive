# 0950. Reveal Cards In Increasing Order《按遞增順序顯示卡牌》

- **Difficulty**: Medium
- **Tags**: array, queue, sorting, simulation
- **題目連結**: https://leetcode.com/problems/reveal-cards-in-increasing-order/
- **程式碼**: [`950_reveal-cards-in-increasing-order.c`](./950_reveal-cards-in-increasing-order.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定一副數值互異的牌 deck，你可任意決定初始牌序，所有牌起初皆背面朝上。重複進行「翻開最上方牌」及「若仍有牌，將下一張最上方牌移至底部」，直到所有牌翻開。請回傳一種初始排序，使翻開的數值嚴格遞增；回傳陣列首項視為牌堆頂端。

**思路**：先將牌值排序，再用佇列模擬揭牌時各原始位置被取用的順序；依序把由小到大的牌填入這些位置。

## Problem Statement (English)

You are given an integer array deck. There is a deck of cards where every card has a unique integer. The integer on the ith card is deck[i].
You can order the deck in any order you want. Initially, all the cards start face down (unrevealed) in one deck.
You will do the following steps repeatedly until all cards are revealed:
Return an ordering of the deck that would reveal the cards in increasing order.
Note that the first entry in the answer is considered to be the top of the deck.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: deck = [17,13,11,2,3,5,7]
Output: [2,13,3,11,5,17,7]
Explanation: 
We get the deck in the order [17,13,11,2,3,5,7] (this order does not matter), and reorder it.
After reordering, the deck starts as [2,13,3,11,5,17,7], where 2 is the top of the deck.
We reveal 2, and move 13 to the bottom.  The deck is now [3,11,5,17,7,13].
We reveal 3, and move 11 to the bottom.  The deck is now [5,17,7,13,11].
We reveal 5, and move 17 to the bottom.  The deck is now [7,13,11,17].
We reveal 7, and move 13 to the bottom.  The deck is now [11,17,13].
We reveal 11, and move 17 to the bottom.  The deck is now [13,17].
We reveal 13, and move 17 to the bottom.  The deck is now [17].
We reveal 17.
Since all the cards revealed are in increasing order, the answer is correct.

Input: deck = [1,1000]
Output: [1,1000]
```

## 限制 Constraints

1 <= deck.length <= 1000
1 <= deck[i] <= 106
All the values of deck are unique.

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* deckRevealedIncreasing(int* deck, int deckSize, int* returnSize) {
    
}
```
