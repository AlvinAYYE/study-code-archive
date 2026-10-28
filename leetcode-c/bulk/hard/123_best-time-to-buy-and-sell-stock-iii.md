# 0123. Best Time to Buy and Sell Stock III《買賣股票的最佳時機 III》

- **Difficulty**: Hard
- **Tags**: array, dynamic-programming
- **題目連結**: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
- **程式碼**: [`123_best-time-to-buy-and-sell-stock-iii.c`](./123_best-time-to-buy-and-sell-stock-iii.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

`prices[i]` 表示第 `i` 天的股價。請計算最多完成兩次交易可得到的最大利潤；不可同時持有多筆交易，必須先賣出才能再次買入。若不交易較佳，答案可以是 0。

## 解題思路

1. 掃描每一天，維護第一次買入後、第一次賣出後、第二次買入後、第二次賣出後的最大帳面利潤。
2. `buy1 = max(buy1, -price)`：今天做第一次買入，或保持原狀。
3. `sell1 = max(sell1, buy1+price)`：今天賣出第一次交易，或維持既有利潤。
4. `buy2 = max(buy2, sell1-price)`：第二次買入時，可以帶著第一次交易的利潤。
5. `sell2 = max(sell2, buy2+price)`：掃描結束後即為最多兩次交易的答案。

只需單次掃描，時間複雜度為 `O(n)`，額外空間為 `O(1)`。

## Problem Statement (English)

You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete at most two transactions.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
Example 1:
Example 2:
Example 3:
Constraints:

## 範例

```text
輸入：prices = [3,3,5,0,0,3,1,4]
輸出：6
說明：可以用 0 買、3 賣，再用 1 買、4 賣，總利潤為 6。

輸入：prices = [1,2,3,4,5]
輸出：4
說明：第 1 天買入、第 5 天賣出即可得到最大利潤 4。

輸入：prices = [7,6,4,3,1]
輸出：0
說明：價格持續下跌，不交易最佳。
```

## 限制

- `1 <= prices.length <= 10^5`
- `0 <= prices[i] <= 10^5`

## 官方 C 函式簽名 Signature

```c
int maxProfit(int* prices, int pricesSize) {
    
}
```
