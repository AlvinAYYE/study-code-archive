/*
 * ==========================================================================
 * UVa 10943 - How do you add?
 * Title-CN: 你怎麼加？
 * Difficulty: UVa Star 1
 * Tags: dynamic-programming, math, combinatorics
 * URL: https://onlinejudge.org/external/109/10943.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find number of ways to express N as sum of K non-negative integers modulo 1,000,000.
 *
 * [中文] 題目說明:
 *     將正整數 N 拆分成 K 個非負整數相加的方法數模 1,000,000。
 *
 * [EN] Approach:
 *     Stars and bars: C(N + K - 1, K - 1) % 1000000. Or DP: dp[n][k] = sum_{x=0}^n dp[n-x][k-1].
 * [中文] 思路:
 *     動態規劃：dp[n][k] = (dp[n-1][k] + dp[n][k-1]) % 1,000,000（等價於隔板法組合數）。
 * ==========================================================================
 */
#include <stdio.h>

int solve_uva10943(int n, int k) {
    int dp[105][105] = {0};
    for (int i = 0; i <= n; i++) dp[i][1] = 1;
    for (int j = 1; j <= k; j++) dp[0][j] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 2; j <= k; j++) {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000;
        }
    }
    return dp[n][k];
}

int main(void) {
    int res = solve_uva10943(20, 2); /* x + y = 20 -> 21 ways */
    int ok = (res == 21);
    printf("%s: UVa 10943 - How do you add\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
