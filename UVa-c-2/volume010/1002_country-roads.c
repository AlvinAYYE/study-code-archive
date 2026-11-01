/*
 * ==========================================================================
 * UVa 1002 - Country Roads
 * Title-CN: 鄉間小路瓶頸路徑最小化 (Minimax Shortest Path)
 * Difficulty: UVa Star 2
 * Tags: graph, mst, dijkstra
 * URL: https://onlinejudge.org/external/10/1002.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find path from city t to all other cities minimizing the maximum edge weight on the path.
 *
 * [中文] 題目說明:
 *     由指定城市 t 出發前往各城市，使路徑上的最大邊權值最小化 (Minimax 最短路 / 最小生成樹 MST)。
 *
 * [EN] Approach:
 *     Modified Dijkstra: dist[v] = min(dist[v], max(dist[u], weight(u, v))).
 * [中文] 思路:
 *     Dijkstra 變形演算法：鬆弛條件為 dist[v] = min(dist[v], max(dist[u], weight))，以優先佇列求解。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva1002(int n, int d[10][10], int s, int target) {
    int cap[10], vis[10] = {0};
    for (int i = 0; i < n; i++) cap[i] = 1e9;
    cap[s] = 0;
    for (int iter = 0; iter < n; iter++) {
        int u = -1, min_c = 1e9;
        for (int i = 0; i < n; i++) {
            if (!vis[i] && cap[i] < min_c) { min_c = cap[i]; u = i; }
        }
        if (u == -1) break;
        vis[u] = 1;
        for (int v = 0; v < n; v++) {
            if (d[u][v] > 0) {
                int cost = (cap[u] > d[u][v]) ? cap[u] : d[u][v];
                if (cost < cap[v]) cap[v] = cost;
            }
        }
    }
    return cap[target];
}

int main(void) {

    int d[10][10] = {0};
    d[0][1] = 5; d[1][2] = 10; d[0][2] = 20;
    int ok = (solve_uva1002(3, d, 0, 2) == 10);
    printf("%s: UVa 1002 - Country Roads\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
