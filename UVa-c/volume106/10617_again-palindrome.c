/*
 * ==========================================================================
 * UVa 10617 - Again Palindrome
 * Title-CN: 又是回文 (非連續回文子序列計數)
 * Difficulty: Medium
 * Tags: DP, Palindrome
 * URL: https://onlinejudge.org/external/106/10617.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count the number of non-empty palindromic subsequences in a given string of length up to 60.
 *
 * [中文] 題目說明:
 *     計算長度不超過 60 的字串中，所有非空回文子序列的總數。
 *
 * [EN] Approach:
 *     Interval DP: if s[i] == s[j], dp[i][j] = dp[i+1][j] + dp[i][j-1] + 1; else dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1].
 * [中文] 思路:
 *     區間動態規劃：若 s[i] == s[j]，則 dp[i][j] = dp[i+1][j] + dp[i][j-1] + 1；否則 dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1]。
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

long long count_palindromic_subseq(const char *s) {
    int n = strlen(s);
    long long dp[65][65] = {0};
    for (int i = 0; i < n; i++) dp[i][i] = 1;
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j] + dp[i][j - 1] + 1;
            } else {
                dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
            }
        }
    }
    return dp[0][n - 1];
}

int main(void) {

    int ok = (count_palindromic_subseq("BAA") == 4); // B, A, A, AA, and single chars
    printf("%s: UVa 10617 - Again Palindrome\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
