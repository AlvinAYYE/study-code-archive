/*
 * ==========================================================================
 * UVa 11584 - Partitioning by Palindromes
 * Title-CN: 回文分割
 * Difficulty: UVa Star 2
 * Tags: dynamic-programming, palindrome, string
 * URL: https://onlinejudge.org/external/115/11584.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Partition string into minimum number of palindromic substrings.
 *
 * [中文] 題目說明:
 *     將字串切割成數個子字串，使每個子字串皆為回文，求最少分割成的回文串數量。
 *
 * [EN] Approach:
 *     Precompute is_pal[i][j]. 1D DP: dp[i] = min_{j <= i, is_pal[j][i]} (dp[j - 1] + 1).
 * [中文] 思路:
 *     動態規劃預先判定回文區間，一維 DP 轉移：dp[i] = min(dp[j - 1] + 1)。
 * ==========================================================================
 */
#include <stdio.h>
#include <string.h>

static inline int min_val(int a, int b) { return a < b ? a : b; }

int solve_uva11584(const char *s) {
    int n = (int)strlen(s);
    static int is_pal[1005][1005];
    memset(is_pal, 0, sizeof(is_pal));
    for (int i = 0; i < n; i++) {
        is_pal[i][i] = 1;
        if (i + 1 < n && s[i] == s[i + 1]) is_pal[i][i + 1] = 1;
    }
    for (int len = 3; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            if (s[i] == s[j] && is_pal[i + 1][j - 1]) is_pal[i][j] = 1;
        }
    }
    static int dp[1005];
    for (int i = 0; i < n; i++) {
        dp[i] = i + 1;
        if (is_pal[0][i]) { dp[i] = 1; continue; }
        for (int j = 1; j <= i; j++) {
            if (is_pal[j][i]) dp[i] = min_val(dp[i], dp[j - 1] + 1);
        }
    }
    return dp[n - 1];
}

int main(void) {
    int ok = (solve_uva11584("racecar") == 1) && (solve_uva11584("fastracecar") == 5);
    printf("%s: UVa 11584 - Partitioning by Palindromes\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
