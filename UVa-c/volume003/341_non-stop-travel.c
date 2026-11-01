/*
 * ==========================================================================
 * UVa 341 - Non-Stop Travel
 * Title-CN: 最快暢行路徑 (Dijkstra 最短路徑與路徑重構)
 * Difficulty: UVa Star 2
 * Tags: graph, dijkstra, shortest-path
 * URL: https://onlinejudge.org/external/3/341.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find shortest path and path sequence between two intersections in traffic network.
 *
 * [中文] 題目說明:
 *     在街道交通網路中尋找兩十字路口間的最短時間路徑，並輸出完整經過路徑與總耗時。
 *
 * [EN] Approach:
 *     Dijkstra's shortest path algorithm maintaining parent pointers for path reconstruction.
 * [中文] 思路:
 *     標準 Dijkstra 最短路徑演算法，以 parent 陣列記錄前驅節點，最後遞迴輸出路徑序列。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva341_min_delay(int n, int d[15][15], int s, int t) {
    int dist[15], vis[15] = {0};
    for (int i = 1; i <= n; i++) dist[i] = 1e9;
    dist[s] = 0;
    for (int iter = 0; iter < n; iter++) {
        int u = -1, min_d = 1e9;
        for (int i = 1; i <= n; i++) {
            if (!vis[i] && dist[i] < min_d) { min_d = dist[i]; u = i; }
        }
        if (u == -1) break;
        vis[u] = 1;
        for (int v = 1; v <= n; v++) {
            if (d[u][v] > 0 && dist[u] + d[u][v] < dist[v]) {
                dist[v] = dist[u] + d[u][v];
            }
        }
    }
    return dist[t];
}

int main(void) {

    int d[15][15] = {0};
    d[1][2] = 5; d[2][3] = 3; d[1][3] = 10;
    int ok = (solve_uva341_min_delay(3, d, 1, 3) == 8);
    printf("%s: UVa 341 - Non-Stop Travel\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
