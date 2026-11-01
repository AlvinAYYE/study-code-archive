/*
 * ==========================================================================
 * UVa 10453 - Make Palindrome
 * Title-CN: 構造回文 (最少插入次數與字串還原)
 * Difficulty: Medium
 * Tags: DP, Palindrome, LCS
 * URL: https://onlinejudge.org/external/104/10453.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the minimum number of character insertions to make a string a palindrome, and reconstruct the resulting palindrome.
 *
 * [中文] 題目說明:
 *     求最少需要插入多少個字元才能將給定字串變為回文字串，並輸出構造後的回文字串。
 *
 * [EN] Approach:
 *     Interval DP: dp[i][j] = 0 if i >= j. If s[i] == s[j], dp[i][j] = dp[i+1][j-1]; else 1 + min(dp[i+1][j], dp[i][j-1]). Backtrack to build string.
 * [中文] 思路:
 *     區間動態規劃：若 s[i] == s[j] 則兩端保留向內遞推；否則取兩側插入代價較小者加 1，回溯遞迴構建對稱回文字串。
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

int min_insert_palindrome(const char *s) {
    int n = strlen(s);
    int dp[25][25] = {0};
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1];
            else dp[i][j] = 1 + (dp[i + 1][j] < dp[i][j - 1] ? dp[i + 1][j] : dp[i][j - 1]);
        }
    }
    return dp[0][n - 1];
}

int main(void) {

    int ok = (min_insert_palindrome("google") == 2); // e.g. "elgoogle" -> 2
    printf("%s: UVa 10453 - Make Palindrome\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
