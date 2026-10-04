# 0904. Fruit Into Baskets《水果成籃》

- **Difficulty**: Medium
- **Tags**: array, hash-table, sliding-window
- **題目連結**: https://leetcode.com/problems/fruit-into-baskets/
- **程式碼**: [`904_fruit-into-baskets.c`](./904_fruit-into-baskets.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

一排果樹由 fruits 表示，可任選起點後只能持續向右摘果。你有兩個籃子，每個籃子可裝無限多但只能裝一種水果；回傳最多可摘得的水果數量。

**思路**：程式以滑動視窗和計數陣列維護至多兩種水果。加入第三種水果時，從左端縮小視窗直到只剩兩種，並記錄最大視窗長度。

## Problem Statement (English)

You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.
You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:
Given the integer array fruits, return the maximum number of fruits you can pick.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: fruits = [1,2,1]
Output: 3
Explanation: We can pick from all 3 trees.

Input: fruits = [0,1,2,2]
Output: 3
Explanation: We can pick from trees [1,2,2].
If we had started at the first tree, we would only pick from trees [0,1].

Input: fruits = [1,2,3,2,2]
Output: 4
Explanation: We can pick from trees [2,3,2,2].
If we had started at the first tree, we would only pick from trees [1,2].
```

## 限制 Constraints

1 <= fruits.length <= 105
0 <= fruits[i] < fruits.length

## 官方 C 函式簽名 Signature

```c
int totalFruit(int* fruits, int fruitsSize) {
    
}
```
