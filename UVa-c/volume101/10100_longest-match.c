/*
 * ==========================================================================
 * UVa 10100 - Longest Match
 * Title-CN: 最長匹配單字序列 (單字級LCS)
 * Difficulty: Medium
 * Tags: DP, LCS, String Parsing
 * URL: https://onlinejudge.org/external/101/10100.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the length of the longest common subsequence of words between two given texts.
 *
 * [中文] 題目說明:
 *     求兩段文字中以單字為單位的最長公共子序列 (LCS) 長度。
 *
 * [EN] Approach:
 *     Tokenize text into words (alphanumeric sequences). Run standard dynamic programming LCS on words.
 * [中文] 思路:
 *     以非字母數字字元為邊界將文章分詞，對單字陣列進行標準 LCS 動態規劃。
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

int lcs_words(int n, char w1[20][20], int m, char w2[20][20]) {
    int dp[25][25] = {0};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (strcmp(w1[i-1], w2[j-1]) == 0) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = (dp[i-1][j] > dp[i][j-1] ? dp[i-1][j] : dp[i][j-1]);
        }
    }
    return dp[n][m];
}

int main(void) {

    char w1[2][20] = {"hello", "world"};
    char w2[3][20] = {"a", "hello", "world"};
    int ok = (lcs_words(2, w1, 3, w2) == 2);
    printf("%s: UVa 10100 - Longest Match\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
