/*
 * ==========================================================================
 * UVa 526 - String Distance and Transform Process
 * Title-CN: 字串編輯距離與轉換過程
 * Difficulty: Medium
 * Tags: DP, Edit Distance
 * URL: https://onlinejudge.org/external/5/526.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Compute Levenshtein distance between two strings and output the exact sequence of Insert, Delete, and Change operations.
 *
 * [中文] 題目說明:
 *     計算兩字串間的最小編輯距離，並依序輸出具體的插入 (Insert)、刪除 (Delete) 與替換 (Change) 操作序列。
 *
 * [EN] Approach:
 *     Standard DP table dp[i][j]. Backtrack from (len1, len2) to reconstruct operations, adjusting 1-based output indices dynamically.
 * [中文] 思路:
 *     經典編輯距離 DP：dp[i][j] 記錄狀態並記錄操作前驅，從終點回溯還原操作步驟，動態維護字串長度與下標偏移。
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

int edit_dist_526(const char *s1, const char *s2) {
    int m = strlen(s1), n = strlen(s2);
    int dp[20][20];
    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else {
                int c1 = dp[i - 1][j] + 1;     // delete
                int c2 = dp[i][j - 1] + 1;     // insert
                int c3 = dp[i - 1][j - 1] + 1; // replace
                int mn = (c1 < c2 ? c1 : c2);
                dp[i][j] = (c3 < mn ? c3 : mn);
            }
        }
    }
    return dp[m][n];
}

int main(void) {

    int d = edit_dist_526("kitten", "sitting");
    int ok = (d == 3);
    printf("%s: UVa 526 - String Distance and Transform Process\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
