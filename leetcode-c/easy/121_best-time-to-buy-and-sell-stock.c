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
 *     給定每日股價陣列 prices，其中 prices[i] 是第 i 天的股價。請選一天
 *     買進一股，並在之後的另一天賣出，使這次交易的利潤最大。若無法獲利，
 *     回傳 0。
 *
 * [中文] 範例
 *     1. prices = [7,1,5,3,6,4]，輸出 5；第 2 天以 1 買進，第 5 天
 *        以 6 賣出，利潤為 5。買進必須早於賣出。
 *     2. prices = [7,6,4,3,1]，輸出 0；價格持續下降，不進行交易。
 *
 * [中文] 限制
 *     - 1 <= prices.length <= 10^5
 *     - 0 <= prices[i] <= 10^4
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
 * [中文] 直觀解題思路
 *     1. 由左往右掃描，minp 記錄今天以前看過的最低價格，代表最佳買入價。
 *     2. 若今天賣出，利潤是 prices[i] - minp，用它更新目前最大利潤 best。
 *     3. 再用今天價格更新 minp，供後續日期使用。這個順序自然保證先買後賣。
 *     4. best 初始為 0，所以沒有獲利機會時會回傳 0。時間 O(n)，
 *        額外空間 O(1)。
 * ==========================================================================
 */
#include <stdio.h>

/* ---------- LeetCode submission / 提交區 ---------- */
int maxProfit(int *prices, int pricesSize) {
    int minp = prices[0], best = 0, i;
    for (i = 1; i < pricesSize; ++i) {
        /* 先計算今天賣出的利潤，再把今天納入往後的最低買價。 */
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
