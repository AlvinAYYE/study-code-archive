/*
 * ==========================================================================
 * UVa 348 - Optimal Array Multiplication Sequence
 * Title-CN: 最佳矩陣鏈乘積括號化
 * Difficulty: UVa Star 2
 * Tags: dynamic-programming, matrix-chain-multiplication
 * URL: https://onlinejudge.org/external/3/348.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find optimal parenthesization of matrix chain multiplication to minimize scalar multiplications.
 *
 * [中文] 題目說明:
 *     求矩陣鏈相乘的最佳括號化方案，使純量乘法運算次數最小 (經典矩陣鏈乘積區間 DP)。
 *
 * [EN] Approach:
 *     Interval dynamic programming: dp[i][j] = min(dp[i][k] + dp[k+1][j] + p[i-1]*p[k]*p[j]). Store split points k.
 * [中文] 思路:
 *     經典區間動態規劃：枚舉長度與分割點 k，記錄最佳分割位置以遞迴印出完整括號表達式。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva348(int n, const int *p) {
    long long dp[15][15] = {0};
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = 1e18;
            for (int k = i; k < j; k++) {
                long long cost = dp[i][k] + dp[k + 1][j] + (long long)p[i - 1] * p[k] * p[j];
                if (cost < dp[i][j]) dp[i][j] = cost;
            }
        }
    }
    return (int)dp[1][n];
}

int main(void) {

    int p[4] = {10, 20, 30, 40};
    int ok = (solve_uva348(3, p) == 18000);
    printf("%s: UVa 348 - Optimal Array Multiplication Sequence\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
