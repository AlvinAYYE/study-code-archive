# 0188. Best Time to Buy and Sell Stock IV《買賣股票的最佳時機 IV》

- **Difficulty**: Hard
- **Tags**: array, dynamic-programming
- **題目連結**: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
- **程式碼**: [`188_best-time-to-buy-and-sell-stock-iv.c`](./188_best-time-to-buy-and-sell-stock-iv.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定每日股價與整數 k，請求出至多完成 k 次買入及 k 次賣出交易所能取得的最大利潤。不可同時進行多筆交易，因此再次買入前必須先賣出持有的股票。

**思路**：以陣列分別記錄每一筆交易序號的最佳買入與賣出利潤，逐日更新狀態；當 k 足夠大時，直接加總所有正向日差作為不限交易次數的結果。

## Problem Statement (English)

You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.
Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
```

## 限制 Constraints

1 <= k <= 100
1 <= prices.length <= 1000
0 <= prices[i] <= 1000

## 官方 C 函式簽名 Signature

```c
int maxProfit(int k, int* prices, int pricesSize) {
    
}
```
