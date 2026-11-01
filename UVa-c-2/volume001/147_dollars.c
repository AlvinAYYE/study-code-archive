/*
 * ==========================================================================
 * UVa 147 - Dollars
 * Title-CN: 貨幣換幣組合數
 * Difficulty: UVa Star 2
 * Tags: dynamic-programming, coin-change
 * URL: https://onlinejudge.org/external/1/147.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given dollar amount up to $300.00, count ways to make change using 11 predefined coin and bill values.
 *
 * [中文] 題目說明:
 *     給定最多 $300.00 的金額，計算使用 11 種特定硬幣與鈔票面額湊齊金額的方法數 (完全背包 DP)。
 *
 * [EN] Approach:
 *     Multiply all values by 20 to convert to integers (5c = 1 unit, max 6000). Precompute 1D unbounded knapsack DP.
 * [中文] 思路:
 *     將金額乘 20 轉為整數單位避免浮點數誤差 (5分=1單位，上限6000)。預處理一維完全背包動態規劃。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long long solve_uva147(int cents) {
    static long long dp[6001] = {0};
    static int initialized = 0;
    int coins[11] = {1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000};
    if (!initialized) {
        dp[0] = 1;
        for (int i = 0; i < 11; i++) {
            for (int j = coins[i]; j <= 6000; j++) {
                dp[j] += dp[j - coins[i]];
            }
        }
        initialized = 1;
    }
    int units = cents / 5;
    return (units <= 6000) ? dp[units] : 0;
}

int main(void) {

    int ok = (solve_uva147(20) == 4);
    printf("%s: UVa 147 - Dollars\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
