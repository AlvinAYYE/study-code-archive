/*
 * ==========================================================================
 * UVa 423 - MPI Maelstrom
 * Title-CN: MPI 訊息廣播全源最短傳遞時間
 * Difficulty: UVa Star 2
 * Tags: graph, dijkstra, floyd-warshall
 * URL: https://onlinejudge.org/external/4/423.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the minimum time to broadcast a message from processor 1 to all other processors in an MPI network (maximum shortest path).
 *
 * [中文] 題目概述:
 *     在處理器通訊網路中，求將廣播訊息自 1 號處理器傳送至其餘所有處理器所需的最短時間 (即單源最短路徑中的最大值)。
 *
 * [EN] Approach:
 *     Run Dijkstra's algorithm from node 1. Answer is max(dist[v]) for all v.
 * [中文] 解題思路:
 *     以 1 號節點為起點執行 Dijkstra 最短路徑演算法，所有節點中距離最大者即為整網廣播完成之最短時間。
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

int solve_uva423(int n, int adj[20][20]) {
    int dist[20], vis[20] = {0};
    for (int i = 0; i < n; i++) dist[i] = 1e9;
    dist[0] = 0;
    for (int iter = 0; iter < n; iter++) {
        int u = -1, min_d = 1e9;
        for (int i = 0; i < n; i++) if (!vis[i] && dist[i] < min_d) { min_d = dist[i]; u = i; }
        if (u == -1) break;
        vis[u] = 1;
        for (int v = 0; v < n; v++) {
            if (adj[u][v] >= 0 && dist[u] + adj[u][v] < dist[v])
                dist[v] = dist[u] + adj[u][v];
        }
    }
    int max_d = 0;
    for (int i = 1; i < n; i++) if (dist[i] > max_d) max_d = dist[i];
    return max_d;
}

int main(void) {

    int adj[20][20] = {{0, 10}, {10, 0}};
    int t = solve_uva423(2, adj);
    int ok = (t == 10);
    printf("%s: UVa 423 - MPI Maelstrom\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
