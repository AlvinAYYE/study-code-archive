# 0714. Best Time to Buy and Sell Stock with Transaction Fee《買賣股票的最佳時機含手續費》

- **Difficulty**: Medium
- **Tags**: array, dynamic-programming, greedy
- **題目連結**: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
- **程式碼**: [`714_best-time-to-buy-and-sell-stock-with-transaction-fee.c`](./714_best-time-to-buy-and-sell-stock-with-transaction-fee.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定每日股價 prices 與每筆交易的手續費 fee，求可進行任意多次交易時的最大獲利。每次完成一筆交易都必須支付手續費。

**思路**：動態規劃維護當日未持股的 sold 與持股的 hold 兩種最佳收益。每日用前一天狀態更新賣出（扣 fee）或買入後的收益。

## Problem Statement (English)

You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.
Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.
Note:
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.

Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6
```

## 限制 Constraints

1 <= prices.length <= 5 * 104
1 <= prices[i] < 5 * 104
0 <= fee < 5 * 104

## 官方 C 函式簽名 Signature

```c
int maxProfit(int* prices, int pricesSize, int fee) {
    
}
```
