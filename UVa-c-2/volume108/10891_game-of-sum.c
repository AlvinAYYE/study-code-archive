/*
 * ==========================================================================
 * UVa 10891 - Game of Sum
 * Title-CN: 求和博弈
 * Difficulty: Medium
 * Tags: Game Theory, Interval DP
 * URL: https://onlinejudge.org/external/108/10891.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Two players take turns removing 1 to remaining elements from either end of an array. Find max score difference Player 1 can guarantee.
 *
 * [中文] 題目概述:
 *     兩人輪流從陣列任一端取走連續 1 個或多個數字，求先手能保證獲得的最大分數差值。
 *
 * [EN] Approach:
 *     Interval DP: dp[i][j] = sum(i..j) - min(0, min_{k} dp[i+k][j], min_{k} dp[i][j-k]).
 * [中文] 解題思路:
 *     區間 DP：dp[i][j] = sum(i..j) - min(0, min(dp[k][j]), min(dp[i][k]))，雙方皆採取最優策略爭奪最大分差。
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

int game_of_sum(int n, const int *a) {
    int prefix[105] = {0};
    for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + a[i];
    int dp[105][105] = {0};
    for (int len = 1; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            int total = prefix[j + 1] - prefix[i];
            int mn = 0;
            for (int k = i + 1; k <= j; k++) if (dp[k][j] < mn) mn = dp[k][j];
            for (int k = i; k < j; k++) if (dp[i][k] < mn) mn = dp[i][k];
            dp[i][j] = total - mn;
        }
    }
    return dp[0][n - 1];
}

int main(void) {

    int a[] = {4, -10, -20, 7};
    int res = game_of_sum(4, a);
    int ok = (res == -6);
    printf("%s: UVa 10891 - Game of Sum\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
