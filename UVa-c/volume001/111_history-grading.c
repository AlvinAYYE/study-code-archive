/*
 * ==========================================================================
 * UVa 111 - History Grading
 * Title-CN: 歷史事件排序評分
 * Difficulty: UVa Star 2
 * Tags: dynamic-programming, lcs, lis
 * URL: https://onlinejudge.org/external/1/111.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given correct chronological rank of events and students' rankings, find length of longest valid relative order.
 *
 * [中文] 題目說明:
 *     給定歷史事件的正確年代順序與學生的排序回答，計算學生保留的相對年代順序的最長長度 (LIS / LCS)。
 *
 * [EN] Approach:
 *     Convert student answer to actual event order sequence, then compute LIS against the standard order.
 * [中文] 思路:
 *     將輸入名次轉換為時間序列表，接著計算標準序列與學生序列的最長共同子序列 (LCS)。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva111(int n, const int *std_order, const int *stu_order) {
    int dp[25][25] = {0};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (std_order[i - 1] == stu_order[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
    }
    return dp[n][n];
}

int main(void) {

    int std[4] = {1, 2, 3, 4};
    int stu[4] = {1, 3, 2, 4};
    int ok = (solve_uva111(4, std, stu) == 3);
    printf("%s: UVa 111 - History Grading\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
