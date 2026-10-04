/*
 * ==========================================================================
 * LeetCode 121. Best Time to Buy and Sell Stock
 * Title-CN: 買賣股票的最佳時機
 * Difficulty: Easy
 * Tags: array, dynamic-programming
 * URL: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 * ==========================================================================
 * [EN] Problem (official statement, source: github mcaupybugs/leetcode-problems-db)
 *     You are given an array prices where prices[i] is the price of a given
 *     stock on the ith day.
 *     You want to maximize your profit by choosing a single day to buy one
 *     stock and choosing a different day in the future to sell that stock.
 *     Return the maximum profit you can achieve from this transaction. If you
 *     cannot achieve any profit, return 0.
 *
 * [中文] 題目說明 (翻譯自官方英文題面)
 *     給定每日股價陣列，選一天買進、之後某天賣出，求最大利潤（不交易則為 0）。
 *
 * Examples:
 *   Example 1:
 *     Input: prices = [7,1,5,3,6,4]
 *     Output: 5
 *     Explanation: Buy on day 2 (price = 1) and sell on day 5 (price =
 *     6), profit = 6-1 = 5.
 *     Note that buying on day 2 and selling on day 1 is not allowed
 *     because you must buy before you sell.
 *   Example 2:
 *     Input: prices = [7,6,4,3,1]
 *     Output: 0
 *     Explanation: In this case, no transactions are done and the max
 *     profit = 0.
 *
 * Constraints:
 *   - 1 <= prices.length <= 10^5
 *   - 0 <= prices[i] <= 10^4
 *
 * LeetCode official C stub (函式簽名):
 *   int maxProfit(int* prices, int pricesSize) {
 *   }
 *
 * [EN] Approach: Track the lowest price seen so far and the best profit (price - lowest) in one pass. Time O(n), space O(1).
 * [中文] 思路: 單遍掃描：維護歷史最低買價，用「今日價 - 最低價」更新最大利潤。時間 O(n)、空間 O(1)。
 * ==========================================================================
 */
#include <stdio.h>

/* ---------- LeetCode submission / 提交區 ---------- */
int maxProfit(int *prices, int pricesSize) {
    int minp = prices[0], best = 0, i;
    for (i = 1; i < pricesSize; ++i) {
        if (prices[i] - minp > best) best = prices[i] - minp;
        if (prices[i] < minp) minp = prices[i];
    }
    return best;
}
/* ---------- end submission ---------- */

static int check(int *a, int n, int expect) {
    int got = maxProfit(a, n);
    if (got != expect) { printf("  fail: got %d want %d\n", got, expect); return 0; }
    return 1;
}

int main(void) {
    int ok = 1;
    int a1[] = {7, 1, 5, 3, 6, 4};
    ok = ok && check(a1, 6, 5);
    int a2[] = {7, 6, 4, 3, 1};
    ok = ok && check(a2, 5, 0);
    int a3[] = {2, 4, 1};
    ok = ok && check(a3, 3, 2);
    printf("%s: 121 best-time-to-buy-and-sell-stock\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
