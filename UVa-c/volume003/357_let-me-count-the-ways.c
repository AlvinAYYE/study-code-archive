/*
 * ==========================================================================
 * UVa 357 - Let Me Count The Ways
 * Title-CN: 算算有多少種方法
 * Difficulty: UVa Star 1
 * Tags: dynamic-programming, coin-change
 * ==========================================================================
 * [EN] Problem: Count ways to produce change for N cents using 1, 5, 10, 25, 50 cent coins (64-bit int).
 * [中文] 題目說明: 使用 1, 5, 10, 25, 50 分湊出 N 分的方法數（答案需用 64 位元整數）。
 * [EN] Approach: 64-bit integer unbounded knapsack DP array up to 30000.
 * [中文] 思路: 完全背包 DP 預先計算 dp[0..30000]。
 * ==========================================================================
 */
#include <stdio.h>

static const int coins[5] = {1, 5, 10, 25, 50};

long long solve_uva357(int n) {
    static long long dp[30005] = {0};
    static int init = 0;
    if (!init) {
        dp[0] = 1;
        for (int c = 0; c < 5; c++) {
            int coin = coins[c];
            for (int j = coin; j <= 30000; j++) {
                dp[j] += dp[j - coin];
            }
        }
        init = 1;
    }
    return dp[n];
}

int main(void) {
    long long w = solve_uva357(17);
    int ok = (w == 6);
    printf("%s: UVa 357 - Let Me Count The Ways\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
