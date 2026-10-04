# 0122. Best Time to Buy and Sell Stock II《買賣股票的最佳時機 II》

- **Difficulty**: Medium
- **Tags**: array, dynamic-programming, greedy
- **題目連結**: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
- **程式碼**: [`122_best-time-to-buy-and-sell-stock-ii.c`](./122_best-time-to-buy-and-sell-stock-ii.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定每日股價 prices，每天可決定買入或賣出股票。任一時刻至多持有一股，但允許在同一天先買後賣。請回傳可完成任意次交易時的最大總利潤。prices 長度介於 1 至 3×10^4，股價介於 0 至 10^4。

**思路**：貪心地累加所有相鄰兩天的正價差，等同取得每一段上漲區間的全部利潤。

## Problem Statement (English)

You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.
Find and return the maximum profit you can achieve.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.
```

## 限制 Constraints

1 <= prices.length <= 3 * 104
0 <= prices[i] <= 104

## 官方 C 函式簽名 Signature

```c
int maxProfit(int* prices, int pricesSize) {
    
}
```
