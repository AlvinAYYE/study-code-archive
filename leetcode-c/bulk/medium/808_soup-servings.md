# 0808. Soup Servings《分湯》

- **Difficulty**: Medium
- **Tags**: math, dynamic-programming, probability-and-statistics
- **題目連結**: https://leetcode.com/problems/soup-servings/
- **程式碼**: [`808_soup-servings.c`](./808_soup-servings.c) — 社群解答（repo ourhouchmohamed97_LeetCode_in_C），已通過編譯+官方示例執行驗證

## 題目說明（中文）

兩碗湯 A、B 初始各有 n mL，每回合等機率選擇 (100,0)、(75,25)、(50,50)、(25,75) 四種取用量，任一碗耗盡便立即結束。回傳 A 先耗盡的機率，加上兩碗同時耗盡機率的一半；誤差 10^-5 內皆可接受。

**思路**：將容量以 25 mL 為單位縮小，使用記憶化 DFS 計算四種操作的平均機率，並處理 A 先盡、B 先盡與同時耗盡的邊界；n 很大時直接回傳 1。

## Problem Statement (English)

You have two soups, A and B, each starting with n mL. On every turn, one of the following four serving operations is chosen at random, each with probability 0.25 independent of all previous turns:
Note:
The process stops immediately after any turn in which one of the soups is used up.
Return the probability that A is used up before B, plus half the probability that both soups are used up in the same turn. Answers within 10-5 of the actual answer will be accepted.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: n = 50
Output: 0.62500
Explanation: 
If we perform either of the first two serving operations, soup A will become empty first.
If we perform the third operation, A and B will become empty at the same time.
If we perform the fourth operation, B will become empty first.
So the total probability of A becoming empty first plus half the probability that A and B become empty at the same time, is 0.25 * (1 + 1 + 0.5 + 0) = 0.625.

Input: n = 100
Output: 0.71875
Explanation: 
If we perform the first serving operation, soup A will become empty first.
If we perform the second serving operations, A will become empty on performing operation [1, 2, 3], and both A and B become empty on performing operation 4.
If we perform the third operation, A will become empty on performing operation [1, 2], and both A and B become empty on performing operation 3.
If we perform the fourth operation, A will become empty on performing operation 1, and both A and B become empty on performing operation 2.
So the total probability of A becoming empty first plus half the probability that A and B become empty at the same time, is 0.71875.
```

## 限制 Constraints

0 <= n <= 109

## 官方 C 函式簽名 Signature

```c
double soupServings(int n) {
    
}
```
