/*
 * ==========================================================================
 * UVa 10066 - The Twin Towers
 * Title-CN: 雙子塔
 * Difficulty: UVa Star 1
 * Tags: dynamic-programming, lcs
 * URL: https://onlinejudge.org/external/100/10066.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the Longest Common Subsequence (LCS) of two integer tile arrays.
 *
 * [中文] 題目說明:
 *     求兩組整數陣列的最長公共子序列（LCS）長度。
 *
 * [EN] Approach: Classic O(N*M) DP for LCS.
 * [中文] 思路: 經典動態規劃 LCS，dp[i][j] = (a[i]==b[j]) ? dp[i-1][j-1]+1 : max(dp[i-1][j], dp[i][j-1])。
 * ==========================================================================
 */
#include <stdio.h>

static inline int max_val(int a, int b) { return a > b ? a : b; }

int solve_uva10066(int n1, const int *a, int n2, const int *b) {
    int dp[105][105] = {0};
    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max_val(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n1][n2];
}

int main(void) {
    int a[] = {2, 3, 5, 7};
    int b[] = {1, 3, 7, 8};
    int res = solve_uva10066(4, a, 4, b); /* LCS is {3, 7} length 2 */
    int ok = (res == 2);
    printf("%s: UVa 10066 - The Twin Towers\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
