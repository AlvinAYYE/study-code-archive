# 0121. Best Time to Buy and Sell Stock《買賣股票的最佳時機》

- **Difficulty**: Easy
- **Tags**: array, dynamic-programming
- **題目連結**: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
- **程式碼**: [`121_best-time-to-buy-and-sell-stock.c`](./121_best-time-to-buy-and-sell-stock.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定 prices，其中 prices[i] 是第 i 天的股價，只能完成一次買入與一次之後賣出的交易。請回傳可取得的最大利潤；若無法獲利則回傳 0。prices 長度介於 1 至 10^5，股價介於 0 至 10^4。

**思路**：線性掃描並維護目前為止最低買入價，對每一天以當日價格減最低價更新最大利潤。

## Problem Statement (English)

You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
```

## 限制 Constraints

1 <= prices.length <= 105
0 <= prices[i] <= 104

## 官方 C 函式簽名 Signature

```c
int maxProfit(int* prices, int pricesSize) {
    
}
```
