/*
 * ==========================================================================
 * UVa 562 - Dividing coins
 * Title-CN: 分金幣 (0/1 背包子集和最小差劃分)
 * Difficulty: UVa Star 1
 * Tags: dynamic-programming, knapsack
 * URL: https://onlinejudge.org/external/5/562.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Divide m coins between two people such that the difference between the two totals is minimized.
 *
 * [中文] 題目說明:
 *     將 m 枚不同面額的金幣分給兩人，求兩人所分得金幣總價值差額的最小值 (0/1 背包容量為 Sum/2)。
 *
 * [EN] Approach:
 *     0/1 Knapsack: find maximum sum <= total_sum / 2. Minimal difference is total_sum - 2 * max_sub_sum.
 * [中文] 思路:
 *     計算金幣總和 S，背包容量設為 S / 2 執行 0/1 背包動態規劃，最接近半數的最佳子集和為 S'，最小差值即 S - 2*S'。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva562(int m, const int *coins) {
    int sum = 0;
    for (int i = 0; i < m; i++) sum += coins[i];
    int half = sum / 2;
    int dp[25005] = {0};
    for (int i = 0; i < m; i++) {
        for (int j = half; j >= coins[i]; j--) {
            if (dp[j - coins[i]] + coins[i] > dp[j]) {
                dp[j] = dp[j - coins[i]] + coins[i];
            }
        }
    }
    return sum - 2 * dp[half];
}

int main(void) {

    int c[3] = {2, 3, 5};
    int ok = (solve_uva562(3, c) == 0); /* 5 vs 5 -> diff 0 */
    printf("%s: UVa 562 - Dividing coins\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
