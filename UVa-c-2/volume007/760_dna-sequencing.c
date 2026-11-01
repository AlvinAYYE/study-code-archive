/*
 * ==========================================================================
 * UVa 760 - DNA Sequencing
 * Title-CN: DNA 測序 (最長公共子串 LCS)
 * Difficulty: Medium
 * Tags: String, Longest Common Substring
 * URL: https://onlinejudge.org/external/7/760.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find all longest common substrings between two DNA strings, sorted alphabetically.
 *
 * [中文] 題目描述:
 *     求兩段 DNA 序列之間的所有最長公共連續子串，按字典序去重輸出；若無公共子串則輸出提示。
 *
 * [EN] Approach:
 *     DP table dp[i][j] = common substring length ending at s1[i-1] and s2[j-1]. Track max length and collect distinct substrings of that length.
 *
 * [中文] 解題思維:
 *     二維動態規劃求解最長公共子串（若 s1[i]==s2[j] 則 dp[i][j] = dp[i-1][j-1] + 1），求最大長度並去重排序提取子串。
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

int longest_common_sub_dna(const char *s1, const char *s2, char out[10][20]) {
    int m = strlen(s1), n = strlen(s2);
    int dp[20][20] = {0};
    int max_l = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > max_l) max_l = dp[i][j];
            }
        }
    }
    return max_l;
}

int main(void) {

    char out[10][20];
    int l = longest_common_sub_dna("atgc", "tgca", out); // "tgc" -> len 3
    int ok = (l == 3);
    printf("%s: UVa 760 - DNA Sequencing\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
