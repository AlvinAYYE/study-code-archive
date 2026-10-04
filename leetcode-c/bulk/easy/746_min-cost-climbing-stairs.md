# 0746. Min Cost Climbing Stairs《使用最小花費爬樓梯》

- **Difficulty**: Easy
- **Tags**: array, dynamic-programming
- **題目連結**: https://leetcode.com/problems/min-cost-climbing-stairs/
- **程式碼**: [`746_min-cost-climbing-stairs.c`](./746_min-cost-climbing-stairs.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定樓梯每一階的花費 cost，支付某階花費後可以爬一階或兩階，且可從索引 0 或 1 起步。請回傳到達樓頂所需的最小總花費。

**思路**：DP 陣列記錄踩到每一階為止的最低花費，當前階取前一或前兩階最低花費再加本階成本。樓頂可由最後一階或倒數第二階到達，因此取兩者最小值。

## Problem Statement (English)

You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.
You can either start from the step with index 0, or the step with index 1.
Return the minimum cost to reach the top of the floor.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.

Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.
```

## 限制 Constraints

2 <= cost.length <= 1000
0 <= cost[i] <= 999

## 官方 C 函式簽名 Signature

```c
int minCostClimbingStairs(int* cost, int costSize) {
    
}
```
