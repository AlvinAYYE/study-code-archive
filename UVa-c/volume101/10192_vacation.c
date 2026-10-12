/*
 * ==========================================================================
 * UVa 10192 - Vacation
 * Title-CN: 度假景點
 * Difficulty: UVa Star 1
 * Tags: dynamic-programming, lcs
 * ==========================================================================
 * [EN] Problem: Longest common subsequence between two vacation itineraries.
 * [中文] 題目說明: 求兩個度假城市字串序列的最長公共子序列（LCS）。
 * [EN] Approach: Classic DP LCS on two strings.
 * [中文] 思路: 經典字串二維動態規劃 LCS。
 * ==========================================================================
 */
#include <stdio.h>
#include <string.h>

static inline int max_val(int a, int b) { return a > b ? a : b; }

int solve_uva10192(const char *s1, const char *s2) {
    int n = (int)strlen(s1);
    int m = (int)strlen(s2);
    int dp[105][105] = {0};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max_val(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}

int main(void) {
    int res = solve_uva10192("ROME", "PISA");
    int ok = (res == 0);
    int res2 = solve_uva10192("VENICE", "NICE");
    ok = ok && (res2 == 4);
    printf("%s: UVa 10192 - Vacation\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
