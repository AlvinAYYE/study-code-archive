# 0123. Best Time to Buy and Sell Stock III《買賣股票的最佳時機 III》

- **Difficulty**: Hard
- **Tags**: array, dynamic-programming
- **題目連結**: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
- **程式碼**: [`123_best-time-to-buy-and-sell-stock-iii.c`](./123_best-time-to-buy-and-sell-stock-iii.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定每日股價 prices，求最多完成兩次交易可得到的最大利潤。不可同時進行多筆交易，必須先賣出才能再次買入。若不交易較佳，利潤可以是 0。prices 長度介於 1 至 10^5，股價介於 0 至 10^5。

**思路**：掃描股價並維護 buy1、sell1、buy2、sell2 四個狀態，分別表示前後兩筆交易買入或賣出後的最佳利潤。

## Problem Statement (English)

You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete at most two transactions.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
```

## 限制 Constraints

1 <= prices.length <= 105
0 <= prices[i] <= 105

## 官方 C 函式簽名 Signature

```c
int maxProfit(int* prices, int pricesSize) {
    
}
```
