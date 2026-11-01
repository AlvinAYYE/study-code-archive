/*
 * ==========================================================================
 * UVa 10496 - Collecting Beepers
 * Title-CN: 網格尋呼機收集最短巡迴路徑 TSP
 * Difficulty: UVa Star 2
 * Tags: dynamic-programming, bitmask, tsp
 * URL: https://onlinejudge.org/external/104/10496.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the shortest route starting and ending at home position that visits all N beepers in a grid (Manhattan distance).
 *
 * [中文] 題目說明:
 *     以曼哈頓距離為代價，求從家出發收集完地圖上所有 N 個尋呼機 (Beeper) 並返回起點的最短巡迴路徑長度 (旅行商問題 TSP)。
 *
 * [EN] Approach:
 *     TSP with Bitmask DP: dp[mask][cur_node] stores shortest distance to visit subset of beepers ending at cur_node.
 * [中文] 思路:
 *     狀態壓縮 DP 求解 TSP：dp[mask][u] 記錄當前拜訪狀態為 mask 且最後停在點 u 的最短路徑，最後回到原點求最小值。
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

int solve_uva10496(int n, int *x, int *y) {
    int total = n + 1; // 0 is start
    int max_mask = 1 << total;
    int dp[1 << 5][5];
    for (int i = 0; i < max_mask; i++) for (int j = 0; j < total; j++) dp[i][j] = 1e9;
    dp[1][0] = 0;
    for (int mask = 1; mask < max_mask; mask++) {
        for (int u = 0; u < total; u++) {
            if (dp[mask][u] >= 1e8) continue;
            for (int v = 0; v < total; v++) {
                if (!(mask & (1 << v))) {
                    int dist = abs(x[u] - x[v]) + abs(y[u] - y[v]);
                    int nxt = mask | (1 << v);
                    if (dp[mask][u] + dist < dp[nxt][v]) dp[nxt][v] = dp[mask][u] + dist;
                }
            }
        }
    }
    int best = 1e9;
    for (int u = 1; u < total; u++) {
        int back_dist = abs(x[u] - x[0]) + abs(y[u] - y[0]);
        if (dp[max_mask - 1][u] + back_dist < best) best = dp[max_mask - 1][u] + back_dist;
    }
    return best;
}

int main(void) {

    int x[] = {0, 1}, y[] = {0, 1}; // 0 is start, 1 is beeper
    int ans = solve_uva10496(1, x, y); // dist = 2 + 2 = 4
    int ok = (ans == 4);
    printf("%s: UVa 10496 - Collecting Beepers\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
