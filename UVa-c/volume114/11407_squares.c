/*
 * ==========================================================================
 * UVa 11407 - Squares
 * Title-CN: 平方數最少和 (四平方和定理動態規劃)
 * Difficulty: Easy
 * Tags: DP, Math
 * URL: https://onlinejudge.org/external/114/11407.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the minimum number of square numbers required to sum to N.
 *
 * [中文] 題目說明:
 *     求將正整數 N 表示為完全平方數之和的最少個數（Lagrange 四平方和定理）。
 *
 * [EN] Approach:
 *     DP state dp[i] = 1 + min(dp[i - j*j]) for all j*j <= i.
 * [中文] 思路:
 *     動態規劃：dp[i] = 1 + min(dp[i - j*j])，其中 j*j <= i，答案不超過 4。
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

int min_squares_sum(int n) {
    int dp[10005];
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = i;
        for (int j = 1; j * j <= i; j++) {
            if (dp[i - j * j] + 1 < dp[i]) dp[i] = dp[i - j * j] + 1;
        }
    }
    return dp[n];
}

int main(void) {

    int ok = (min_squares_sum(1) == 1) && (min_squares_sum(2) == 2) && (min_squares_sum(4) == 1);
    printf("%s: UVa 11407 - Squares\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
