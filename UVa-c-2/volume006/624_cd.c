/*
 * ==========================================================================
 * UVa 624 - CD
 * Title-CN: 錄音帶容量最大化 (0/1 背包與曲目路徑還原)
 * Difficulty: UVa Star 1
 * Tags: dynamic-programming, knapsack, backtracking
 * URL: https://onlinejudge.org/external/6/624.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given tape length N and track durations, select subset of tracks to maximize total time without exceeding N.
 *
 * [中文] 題目說明:
 *     在給定錄音帶容量 N 的限制下，挑選曲目使得總播放時間最接近 N 且不超額，並輸出所挑選的曲目清單。
 *
 * [EN] Approach:
 *     0/1 Knapsack dynamic programming with path tracking, or backtracking DFS since number of tracks <= 20.
 * [中文] 思路:
 *     因曲目數不超過 20，可以 0/1 背包 DP 或回溯搜尋求最優容量，並記錄選取狀態還原具體曲目。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva624(int cap, int n, const int *tracks, int *out_tracks, int *out_cnt) {
    int dp[1005] = {0};
    int take[25][1005] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = cap; j >= tracks[i]; j--) {
            if (dp[j - tracks[i]] + tracks[i] > dp[j]) {
                dp[j] = dp[j - tracks[i]] + tracks[i];
                take[i][j] = 1;
            }
        }
    }
    int cur_c = dp[cap];
    int cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (take[i][cur_c]) {
            out_tracks[cnt++] = tracks[i];
            cur_c -= tracks[i];
        }
    }
    *out_cnt = cnt;
    return dp[cap];
}

int main(void) {

    int tr[3] = {5, 10, 12};
    int sel[3], cnt;
    int tot = solve_uva624(20, 3, tr, sel, &cnt);
    int ok = (tot == 17); /* 5 + 12 */
    printf("%s: UVa 624 - CD\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
