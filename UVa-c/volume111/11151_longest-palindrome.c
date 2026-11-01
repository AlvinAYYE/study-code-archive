/*
 * ==========================================================================
 * UVa 11151 - Longest Palindrome
 * Title-CN: 字串中最長迴文子序列區間 DP
 * Difficulty: UVa Star 2
 * Tags: dynamic-programming, string
 * URL: https://onlinejudge.org/external/111/11151.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the length of the longest palindromic subsequence of a given string (not necessarily contiguous).
 *
 * [中文] 題目說明:
 *     計算給定字串中最長迴文子序列 (LPS，不必連續) 的最大長度。
 *
 * [EN] Approach:
 *     Interval dynamic programming: dp[i][j] = dp[i+1][j-1] + 2 if s[i]==s[j], else max(dp[i+1][j], dp[i][j-1]).
 * [中文] 思路:
 *     區間動態規劃：若兩端字元相等則 dp[i][j] = dp[i+1][j-1] + 2；否則取兩側縮小區間之較大值 max(dp[i+1][j], dp[i][j-1])。
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

int solve_uva11151(const char *s) {
    int n = strlen(s);
    if (n == 0) return 0;
    int dp[50][50] = {0};
    for (int i = 0; i < n; i++) dp[i][i] = 1;
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1] + 2;
            else dp[i][j] = dp[i + 1][j] > dp[i][j - 1] ? dp[i + 1][j] : dp[i][j - 1];
        }
    }
    return dp[0][n - 1];
}

int main(void) {

    int l = solve_uva11151("ADAM");
    int ok = (l == 3); // "ADA"
    printf("%s: UVa 11151 - Longest Palindrome\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
