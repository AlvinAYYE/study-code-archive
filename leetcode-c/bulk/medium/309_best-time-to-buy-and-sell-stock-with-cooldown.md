# 0309. Best Time to Buy and Sell Stock with Cooldown《含冷凍期的最佳買賣股票時機》

- **Difficulty**: Medium
- **Tags**: array, dynamic-programming
- **題目連結**: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
- **程式碼**: [`309_best-time-to-buy-and-sell-stock-with-cooldown.c`](./309_best-time-to-buy-and-sell-stock-with-cooldown.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定每天的股價 prices，可進行不限次數的買賣交易，但同一時間只能持有一股，必須先賣出才能再買入。每次賣出後隔天是冷凍期，當天不能買入；請求出最大利潤。

**思路**：以動態規劃維護每天持有、已賣出與冷凍／休息三種狀態的最大利潤。每一天只用前一天三個狀態轉移，即可在 O(1) 額外空間完成。

## Problem Statement (English)

You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]

Input: prices = [1]
Output: 0
```

## 限制 Constraints

1 <= prices.length <= 5000
0 <= prices[i] <= 1000

## 官方 C 函式簽名 Signature

```c
int maxProfit(int* prices, int pricesSize) {
    
}
```
