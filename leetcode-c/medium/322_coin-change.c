/*
 * ==========================================================================
 * LeetCode 322. Coin Change
 * Title-CN: 硬幣找零
 * Difficulty: Medium
 * Tags: array, dynamic-programming, breadthfirst-search
 * URL: https://leetcode.com/problems/coin-change/
 * ==========================================================================
 * [EN] Problem (official statement, source: github mcaupybugs/leetcode-problems-db)
 *     You are given an integer array coins representing coins of different
 *     denominations and an integer amount representing a total amount of
 *     money.
 *     Return the fewest number of coins that you need to make up that amount.
 *     If that amount of money cannot be made up by any combination of the
 *     coins, return -1.
 *     You may assume that you have an infinite number of each kind of coin.
 *
 * [中文] 題目說明 (翻譯自官方英文題面)
 *     用最少的硬幣數湊出給定金額，無法湊出回傳 -1。
 *
 * Examples:
 *   Example 1:
 *     Input: coins = [1,2,5], amount = 11
 *     Output: 3
 *     Explanation: 11 = 5 + 5 + 1
 *   Example 2:
 *     Input: coins = [2], amount = 3
 *     Output: -1
 *   Example 3:
 *     Input: coins = [1], amount = 0
 *     Output: 0
 *
 * Constraints:
 *   - 1 <= coins.length <= 12
 *   - 1 <= coins[i] <= 231 - 1
 *   - 0 <= amount <= 10^4
 *
 * LeetCode official C stub (函式簽名):
 *   int coinChange(int* coins, int coinsSize, int amount) {
 *   }
 *
 * [EN] Approach: Bottom-up DP: dp[a] = 1 + min(dp[a-coin]) over coins with coin<=a; dp[0]=0. Time O(amount*n), space O(amount).
 * [中文] 思路: 自底向上 DP：dp[a]=1+min(dp[a-coin])，dp[0]=0；無解維持 INF 並回傳 -1。時間 O(amount*n)。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>

/* ---------- LeetCode submission / 提交區 ---------- */
int coinChange(int *coins, int coinsSize, int amount) {
    int *dp = (int *)malloc((size_t)(amount + 1) * sizeof(int));
    int a, i;
    dp[0] = 0;
    for (a = 1; a <= amount; ++a) {
        int best = amount + 1;
        for (i = 0; i < coinsSize; ++i)
            if (coins[i] <= a && dp[a - coins[i]] + 1 < best)
                best = dp[a - coins[i]] + 1;
        dp[a] = best;
    }
    {
        int ans = (amount == 0) ? 0 : (dp[amount] > amount ? -1 : dp[amount]);
        free(dp);
        return ans;
    }
}
/* ---------- end submission ---------- */

static int check(int *c, int n, int amount, int expect) {
    int got = coinChange(c, n, amount);
    if (got != expect) { printf("  fail: amount %d -> %d want %d\n", amount, got, expect); return 0; }
    return 1;
}

int main(void) {
    int ok = 1;
    int c1[] = {1, 2, 5};
    ok = ok && check(c1, 3, 11, 3);
    int c2[] = {2};
    ok = ok && check(c2, 1, 3, -1);
    int c3[] = {1};
    ok = ok && check(c3, 1, 0, 0);
    int c4[] = {186, 419, 83, 408};
    ok = ok && check(c4, 4, 6249, 20);
    printf("%s: 322 coin-change\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
