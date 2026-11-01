/*
 * ==========================================================================
 * UVa 558 - Wormholes
 * Title-CN: 蟲洞時空倒流 (負權迴路 Bellman-Ford 檢測)
 * Difficulty: UVa Star 2
 * Tags: graph, bellman-ford, negative-cycle
 * URL: https://onlinejudge.org/external/5/558.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine if directed graph with negative edge weights contains a negative-weight cycle (time travel).
 *
 * [中文] 題目說明:
 *     在含有負權邊的有向圖中，判定是否存在負權迴路使得旅行者能回到過去 (Bellman-Ford 演算法)。
 *
 * [EN] Approach:
 *     Run Bellman-Ford algorithm for n - 1 iterations. If any edge can still be relaxed on the n-th iteration, a negative cycle exists.
 * [中文] 思路:
 *     執行 n - 1 次 Bellman-Ford 邊鬆弛操作；若在第 n 次仍能成功鬆弛，代表圖中存在負權迴路。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct { int u, v, w; } Edge558;

int solve_uva558(int n, int m, Edge558 *edges) {
    int dist[1005] = {0};
    for (int iter = 0; iter < n - 1; iter++) {
        for (int i = 0; i < m; i++) {
            if (dist[edges[i].u] + edges[i].w < dist[edges[i].v]) {
                dist[edges[i].v] = dist[edges[i].u] + edges[i].w;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        if (dist[edges[i].u] + edges[i].w < dist[edges[i].v]) {
            return 1; /* Negative cycle exists! */
        }
    }
    return 0;
}

int main(void) {

    Edge558 e[3] = {{0, 1, 1}, {1, 2, -2}, {2, 0, -1}}; /* 1 - 2 - 1 = -2 < 0 */
    int ok = (solve_uva558(3, 3, e) == 1);
    printf("%s: UVa 558 - Wormholes\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
