/*
 * ==========================================================================
 * UVa 674 - Coin Change
 * Title-CN: 零錢兌換方法數 (完全背包 DP)
 * Difficulty: UVa Star 1
 * Tags: dynamic-programming, coin-change
 * URL: https://onlinejudge.org/external/6/674.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find number of ways to make change for given cents (up to 7489) using 1, 5, 10, 25, 50 cent coins.
 *
 * [中文] 題目說明:
 *     給定美分金額 (最多 7489)，計算使用 5 種美幣 (1, 5, 10, 25, 50) 湊齊該金額的方法總數。
 *
 * [EN] Approach:
 *     Unbounded knapsack DP precomputed up to 7489: dp[j] += dp[j - coin]. Answer queries in O(1).
 * [中文] 思路:
 *     完全背包一維動態規劃：dp[j] += dp[j - coin]，預先建表至 7489，詢問時 O(1) 輸出。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long long solve_uva674(int n) {
    static long long dp[7500] = {0};
    static int ready = 0;
    int coins[5] = {1, 5, 10, 25, 50};
    if (!ready) {
        dp[0] = 1;
        for (int i = 0; i < 5; i++) {
            for (int j = coins[i]; j < 7500; j++) {
                dp[j] += dp[j - coins[i]];
            }
        }
        ready = 1;
    }
    return (n >= 0 && n < 7500) ? dp[n] : 0;
}

int main(void) {

    int ok = (solve_uva674(11) == 4); /* 11c -> 4 ways */
    printf("%s: UVa 674 - Coin Change\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
