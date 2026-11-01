/*
 * ==========================================================================
 * UVa 10739 - String to Palindrome
 * Title-CN: 轉換為回文字串的最少操作數
 * Difficulty: Medium
 * Tags: DP, Edit Distance, Palindrome
 * URL: https://onlinejudge.org/external/107/10739.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the minimum number of insertions, deletions, or substitutions needed to turn a string into a palindrome.
 *
 * [中文] 題目概述:
 *     求最少需要幾次插入、刪除或替換字元的操作，才能將字串變成回文字串。
 *
 * [EN] Approach:
 *     Interval DP: if s[i] == s[j], dp[i][j] = dp[i+1][j-1]. Otherwise 1 + min(dp[i+1][j], dp[i][j-1], dp[i+1][j-1]).
 * [中文] 解題思路:
 *     區間動態規劃：若 s[i] == s[j]，則 dp[i][j] = dp[i+1][j-1]；否則為 1 + min(刪左, 刪右, 替換)。
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

int min_palin_ops(const char *s) {
    int n = strlen(s);
    int dp[105][105] = {0};
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1];
            } else {
                int c1 = dp[i + 1][j];
                int c2 = dp[i][j - 1];
                int c3 = dp[i + 1][j - 1];
                int mn = (c1 < c2 ? c1 : c2);
                dp[i][j] = 1 + (c3 < mn ? c3 : mn);
            }
        }
    }
    return dp[0][n - 1];
}

int main(void) {

    int ok = (min_palin_ops("kitty") == 2);
    printf("%s: UVa 10739 - String to Palindrome\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
