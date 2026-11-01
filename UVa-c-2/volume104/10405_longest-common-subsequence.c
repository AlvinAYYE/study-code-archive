/*
 * ==========================================================================
 * UVa 10405 - Longest Common Subsequence
 * Title-CN: 最長共同子序列 (經典 LCS)
 * Difficulty: UVa Star 1
 * Tags: dynamic-programming, lcs, string
 * URL: https://onlinejudge.org/external/104/10405.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find length of Longest Common Subsequence between two strings.
 *
 * [中文] 題目說明:
 *     求兩字串的最長共同子序列 (LCS) 的最大長度。
 *
 * [EN] Approach:
 *     Standard 2D DP: dp[i][j] = (s1[i-1] == s2[j-1] ? dp[i-1][j-1] + 1 : max(dp[i-1][j], dp[i][j-1])).
 * [中文] 思路:
 *     經典二維動態規劃轉移：若字元相同則由左上角 +1；否則取左方與上方最大值。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva10405(const char *s1, const char *s2) {
    int l1 = (int)strlen(s1), l2 = (int)strlen(s2);
    static int dp[1005][1005];
    for (int i = 0; i <= l1; i++) dp[i][0] = 0;
    for (int j = 0; j <= l2; j++) dp[0][j] = 0;
    for (int i = 1; i <= l1; i++) {
        for (int j = 1; j <= l2; j++) {
            if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
        }
    }
    return dp[l1][l2];
}

int main(void) {

    int ok = (solve_uva10405("a1b2c3d4e", "zz1yy2xx3ww4vv") == 4);
    printf("%s: UVa 10405 - Longest Common Subsequence\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
