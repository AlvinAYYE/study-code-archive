# 0322. Coin Change《零錢兌換》

- **Difficulty**: Medium
- **Tags**: array, dynamic-programming, breadth-first-search
- **題目連結**: https://leetcode.com/problems/coin-change/
- **程式碼**: [`322_coin-change.c`](./322_coin-change.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定各種面額的 coins 與總金額 amount，每種面額都可無限使用。請回傳湊出 amount 所需的最少硬幣數；若無法湊出則回傳 -1。

**思路**：以 dp[i] 表示湊出金額 i 的最少硬幣數，dp[0] 設為 0。對每個金額嘗試所有不超過它的面額，從可達的 dp[i - coin] 轉移並取最小值。

## Problem Statement (English)

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Input: coins = [2], amount = 3
Output: -1

Input: coins = [1], amount = 0
Output: 0
```

## 限制 Constraints

1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104

## 官方 C 函式簽名 Signature

```c
int coinChange(int* coins, int coinsSize, int amount) {
    
}
```
