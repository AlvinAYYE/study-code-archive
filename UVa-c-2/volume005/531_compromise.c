/*
 * ==========================================================================
 * UVa 531 - Compromise
 * Title-CN: 外交妥協 (單詞級最長共同子序列 LCS)
 * Difficulty: UVa Star 2
 * Tags: dynamic-programming, lcs, string
 * URL: https://onlinejudge.org/external/5/531.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given two texts composed of words, find the Longest Common Subsequence of words and print them.
 *
 * [中文] 題目說明:
 *     給定兩篇外交報告文字，求單詞層級的最長共同子序列 (LCS)，並輸出共同單詞序列。
 *
 * [EN] Approach:
 *     2D LCS dynamic programming on word arrays. Reconstruct common sequence using direction backtrack table.
 * [中文] 思路:
 *     以單詞字串作為基本元素進行二維 LCS 動態規劃，並以回溯方向陣列輸出還原的最長共同單詞清單。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva531_lcs(int n, int m, char w1[][35], char w2[][35]) {
    int dp[105][105] = {0};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (strcmp(w1[i - 1], w2[j - 1]) == 0) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
        }
    }
    return dp[n][m];
}

int main(void) {

    char w1[3][35] = {"peace", "is", "good"};
    char w2[3][35] = {"peace", "and", "good"};
    int ok = (solve_uva531_lcs(3, 3, w1, w2) == 2);
    printf("%s: UVa 531 - Compromise\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
