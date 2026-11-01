/*
 * ==========================================================================
 * UVa 231 - Testing the CATCHER
 * Title-CN: 攔截飛彈 (最長不遞增子序列 LDS)
 * Difficulty: UVa Star 1
 * Tags: dynamic-programming, lis, greedy
 * URL: https://onlinejudge.org/external/2/231.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given sequence of missile heights, find maximum number of missiles that can be intercepted (non-increasing heights).
 *
 * [中文] 題目說明:
 *     給定一組飛彈攔截高度序列，求飛彈攔截系統最多能攔截的飛彈數量 (最長不遞增子序列 LDS)。
 *
 * [EN] Approach:
 *     O(N log N) or O(N^2) Longest Non-Increasing Subsequence DP.
 * [中文] 思路:
 *     標準動態規劃或貪婪二分搜尋求最長不上升子序列 (LDS)。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva231(int n, const int *a) {
    int dp[1000];
    int max_len = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[j] >= a[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
        if (dp[i] > max_len) max_len = dp[i];
    }
    return max_len;
}

int main(void) {

    int h[5] = {300, 250, 275, 250, 200};
    int ok = (solve_uva231(5, h) == 4);
    printf("%s: UVa 231 - Testing the CATCHER\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
