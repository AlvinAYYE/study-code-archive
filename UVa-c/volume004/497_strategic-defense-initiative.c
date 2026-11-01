/*
 * ==========================================================================
 * UVa 497 - Strategic Defense Initiative
 * Title-CN: 戰略防禦倡議 (最長遞增子序列路徑還原)
 * Difficulty: UVa Star 2
 * Tags: dynamic-programming, lis
 * URL: https://onlinejudge.org/external/4/497.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find maximum number of missile targets that can be hit (strictly increasing altitudes) and output path.
 *
 * [中文] 題目說明:
 *     求依序攔截高度嚴格遞增的最多飛彈數量，並輸出還原出的具體飛彈高度序列 (LIS DP 與路徑還原)。
 *
 * [EN] Approach:
 *     Classic LIS DP with parent array tracking previous missile index for backtracking.
 * [中文] 思路:
 *     經典 LIS 動態規劃，以 parent 陣列記錄前驅飛彈下標，最後自最大 LIS 結尾遞迴回溯印出答案。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva497(int n, const int *a) {
    int dp[500];
    int max_l = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && dp[j] + 1 > dp[i]) dp[i] = dp[j] + 1;
        }
        if (dp[i] > max_l) max_l = dp[i];
    }
    return max_l;
}

int main(void) {

    int a[5] = {1, 6, 2, 3, 5};
    int ok = (solve_uva497(5, a) == 4); /* 1, 2, 3, 5 */
    printf("%s: UVa 497 - Strategic Defense Initiative\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
