/*
 * ==========================================================================
 * UVa 674 - Coin Change
 * Title-CN: 找零錢問題
 * Difficulty: UVa Star 1
 * Tags: dynamic-programming, coin-change
 * ==========================================================================
 * [EN] Problem: Number of ways to make change for amount using coins {1, 5, 10, 25, 50}.
 * [中文] 題目說明: 使用面額 1, 5, 10, 25, 50 分的硬幣湊出金額，求可能的方法數。
 * [EN] Approach: Unbounded knapsack DP: dp[j] += dp[j - coin].
 * [中文] 思路: 完全背包動態規劃，預先計算 dp[0..7489]。
 * ==========================================================================
 */
#include <stdio.h>

static const int coins[5] = {1, 5, 10, 25, 50};

int solve_uva674(int n) {
    static int dp[7500] = {0};
    static int init = 0;
    if (!init) {
        dp[0] = 1;
        for (int c = 0; c < 5; c++) {
            int coin = coins[c];
            for (int j = coin; j < 7500; j++) {
                dp[j] += dp[j - coin];
            }
        }
        init = 1;
    }
    return dp[n];
}

int main(void) {
    int ok = (solve_uva674(11) == 4); /* 11 = 10+1, 5+5+1, 5+1*6, 1*11 -> 4 ways */
    printf("%s: UVa 674 - Coin Change\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
