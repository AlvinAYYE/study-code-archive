/*
 * ==========================================================================
 * UVa 10911 - Forming Quiz Teams
 * Title-CN: 問答競賽組隊最小歐氏距離和狀態壓縮 DP
 * Difficulty: UVa Star 2
 * Tags: dynamic-programming, bitmask
 * URL: https://onlinejudge.org/external/109/10911.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given 2N students on a 2D plane, pair them into N teams of 2 to minimize the sum of Euclidean distances between teammates.
 *
 * [中文] 題目說明:
 *     給定平面上 2N 位學生的座標，將其兩兩配對成 N 組使所有組員間歐幾里得距離總和最小 (狀態壓縮 DP)。
 *
 * [EN] Approach:
 *     Bitmask dynamic programming: dp[mask] represents minimum cost to pair the subset of students encoded by mask. Transition by picking lowest unset bit.
 * [中文] 思路:
 *     狀態壓縮動態規劃：dp[mask] 記錄已配對學生的集合狀態，每次挑選最小未配對學生並枚舉其隊友轉移更新。
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

double solve_uva10911(int n, double *x, double *y) {
    int total = 2 * n;
    int max_mask = 1 << total;
    double dp[1 << 8];
    for (int i = 0; i < max_mask; i++) dp[i] = 1e9;
    dp[0] = 0;
    for (int mask = 0; mask < max_mask; mask++) {
        if (dp[mask] >= 1e8) continue;
        int i = -1;
        for (int k = 0; k < total; k++) {
            if (!(mask & (1 << k))) { i = k; break; }
        }
        if (i == -1) continue;
        for (int j = i + 1; j < total; j++) {
            if (!(mask & (1 << j))) {
                double dist = sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
                int nxt = mask | (1 << i) | (1 << j);
                if (dp[mask] + dist < dp[nxt]) dp[nxt] = dp[mask] + dist;
            }
        }
    }
    return dp[max_mask - 1];
}

int main(void) {

    double x[] = {0, 0}, y[] = {0, 4};
    double d = solve_uva10911(1, x, y);
    int ok = (fabs(d - 4.0) < 1e-4);
    printf("%s: UVa 10911 - Forming Quiz Teams\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
