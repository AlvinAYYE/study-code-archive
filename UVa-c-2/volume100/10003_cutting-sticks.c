/*
 * ==========================================================================
 * UVa 10003 - Cutting Sticks
 * Title-CN: 切木棍 (區間 DP)
 * Difficulty: UVa Star 2
 * Tags: dynamic-programming, interval-dp
 * URL: https://onlinejudge.org/external/100/10003.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find minimal cutting cost to cut stick of length L at given locations.
 *     Cost of cutting equals length of stick segment being cut.
 *
 * [中文] 題目說明:
 *     一根長度為 L 的木棍需要在指定的 n 個點切割。每次切斷的成本為當前木棍長度。
 *     求將所有點切完的最小總成本。
 *
 * [EN] Approach:
 *     Interval DP: dp[i][j] = min_{i < k < j} (dp[i][k] + dp[k][j]) + (cut[j] - cut[i]).
 * [中文] 思路:
 *     經典區間動態規劃。dp[i][j] 表示從切點 i 到切點 j 的最小切割花費。
 * ==========================================================================
 */
#include <stdio.h>

#define INF 1000000000

static inline int min_val(int a, int b) { return a < b ? a : b; }

int solve_uva10003(int l, int n, const int *c) {
    int cuts[55];
    cuts[0] = 0;
    for (int i = 0; i < n; i++) cuts[i + 1] = c[i];
    cuts[n + 1] = l;
    int m = n + 2;

    int dp[55][55] = {0};
    for (int len = 2; len < m; len++) {
        for (int i = 0; i + len < m; i++) {
            int j = i + len;
            dp[i][j] = INF;
            for (int k = i + 1; k < j; k++) {
                int cost = dp[i][k] + dp[k][j] + (cuts[j] - cuts[i]);
                dp[i][j] = min_val(dp[i][j], cost);
            }
        }
    }
    return dp[0][m - 1];
}

int main(void) {
    int cuts[] = {25, 50, 75};
    int res = solve_uva10003(100, 3, cuts);
    int ok = (res == 200);
    printf("%s: UVa 10003 - Cutting Sticks\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
