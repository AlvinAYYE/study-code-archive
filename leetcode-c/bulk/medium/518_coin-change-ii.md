# 0518. Coin Change II《零錢兌換 II》

- **Difficulty**: Medium
- **Tags**: array, dynamic-programming
- **題目連結**: https://leetcode.com/problems/coin-change-ii/
- **程式碼**: [`518_coin-change-ii.c`](./518_coin-change-ii.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定不同面額的硬幣陣列 coins 與總金額 amount，計算可湊出該金額的組合數；無法湊出時回傳 0。每種硬幣可不限次數使用，答案保證落在 32 位元有號整數範圍內。

**思路**：先排序硬幣，再以一維 dp 記錄各金額的組合數；逐一處理硬幣並累加 dp[cur - coin]，使組合不因排列順序重複計數。

## Problem Statement (English)

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.
You may assume that you have an infinite number of each kind of coin.
The answer is guaranteed to fit into a signed 32-bit integer.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.

Input: amount = 10, coins = [10]
Output: 1
```

## 限制 Constraints

1 <= coins.length <= 300
1 <= coins[i] <= 5000
All the values of coins are unique.
0 <= amount <= 5000

## 官方 C 函式簽名 Signature

```c
int change(int amount, int* coins, int coinsSize) {
    
}
```
