/*
 * ==========================================================================
 * UVa 11137 - Ingenuous Cubrency
 * Title-CN: 立方數貨幣找零組合數動態規劃
 * Difficulty: UVa Star 2
 * Tags: dynamic-programming
 * URL: https://onlinejudge.org/external/111/11137.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the number of ways to pay an amount N using cubic coin denominations 1^3, 2^3, ..., 21^3.
 *
 * [中文] 題目說明:
 *     使用 21 種立方數硬幣面額 (1^3, 2^3, ..., 21^3 = 9261) 湊出金額 N 的方法數 (完全背包計數)。
 *
 * [EN] Approach:
 *     Unbounded knapsack DP: dp[j] += dp[j - coin]. Use 64-bit integers.
 * [中文] 思路:
 *     完全背包動態規劃：預先計算 21 個立方數面額，由小到大遞推更新 dp[j] += dp[j - coin]。
 * ==========================================================================
 * UVa Online Judge Submission Template:
 * #include <stdio.h>
 * #include <stdlib.h>
 * #include <string.h>
 * #include <math.h>
 *
 * int main(void) {
 *     // Read input and call logic function
 *     return 0;
 * }
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

long long solve_uva11137(int n) {
    long long dp[10005] = {0};
    dp[0] = 1;
    for (int i = 1; i <= 21; i++) {
        int coin = i * i * i;
        for (int j = coin; j <= n; j++) {
            dp[j] += dp[j - coin];
        }
    }
    return dp[n];
}

int main(void) {

    int ok = (solve_uva11137(1) == 1 && solve_uva11137(8) == 2); // 8: 8*1^3 or 1*2^3
    printf("%s: UVa 11137 - Ingenuous Cubrency\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
