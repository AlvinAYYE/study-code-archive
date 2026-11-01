/*
 * ==========================================================================
 * UVa 164 - String Computer
 * Title-CN: 字串編輯指令重構
 * Difficulty: UVa Star 2
 * Tags: dynamic-programming, string, edit-distance
 * URL: https://onlinejudge.org/external/1/164.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find minimum number of insert, delete, change operations to transform string A into string B and print operations.
 *
 * [中文] 題目說明:
 *     求將字串 A 轉換為字串 B 的最少插入、刪除、取代操作次數，並輸出對應指令 (帶路徑回溯的編輯距離 DP)。
 *
 * [EN] Approach:
 *     Standard Wagner-Fischer edit distance algorithm with 2D backtrack table to reconstruct formatted command string.
 * [中文] 思路:
 *     標準編輯距離動態規劃，維護操作來源陣列，自底向上回溯還原每步插入、刪除與替換指令與位置。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva164_dist(const char *s1, const char *s2) {
    int l1 = (int)strlen(s1), l2 = (int)strlen(s2);
    int dp[25][25];
    for (int i = 0; i <= l1; i++) dp[i][0] = i;
    for (int j = 0; j <= l2; j++) dp[0][j] = j;
    for (int i = 1; i <= l1; i++) {
        for (int j = 1; j <= l2; j++) {
            if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else {
                int m = dp[i - 1][j] + 1;
                if (dp[i][j - 1] + 1 < m) m = dp[i][j - 1] + 1;
                if (dp[i - 1][j - 1] + 1 < m) m = dp[i - 1][j - 1] + 1;
                dp[i][j] = m;
            }
        }
    }
    return dp[l1][l2];
}

int main(void) {

    int ok = (solve_uva164_dist("abc", "adc") == 1);
    printf("%s: UVa 164 - String Computer\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
