/*
 * ==========================================================================
 * UVa 544 - Heavy Cargo
 * Title-CN: 重載卡車貨運 (最大負載瓶頸路徑 Maximin)
 * Difficulty: UVa Star 2
 * Tags: graph, mst, dijkstra, shortest-path
 * URL: https://onlinejudge.org/external/5/544.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find path between city A and B that maximizes minimum bridge weight limit (bottleneck capacity).
 *
 * [中文] 題目說明:
 *     求兩城市間貨運卡車能通行的最大載重噸位 (即使得路徑上的最小承重橋樑噸位最大化，Maximin 問題)。
 *
 * [EN] Approach:
 *     Maximum Spanning Tree via Kruskal or modified Dijkstra / Floyd-Warshall maximizing the bottleneck edge.
 * [中文] 思路:
 *     以 Kruskal 演算法求最大生成樹 (邊權由大到小排序)，或以類似 Dijkstra 演算法鬆弛更新 bottleneck 最大值。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva544(int n, int weight[25][25], int s, int t) {
    int cap[25] = {0}, vis[25] = {0};
    cap[s] = 1e9;
    for (int iter = 0; iter < n; iter++) {
        int u = -1, max_c = -1;
        for (int i = 1; i <= n; i++) {
            if (!vis[i] && cap[i] > max_c) { max_c = cap[i]; u = i; }
        }
        if (u == -1) break;
        vis[u] = 1;
        for (int v = 1; v <= n; v++) {
            if (weight[u][v] > 0) {
                int bottleneck = (cap[u] < weight[u][v]) ? cap[u] : weight[u][v];
                if (bottleneck > cap[v]) cap[v] = bottleneck;
            }
        }
    }
    return cap[t];
}

int main(void) {

    int w[25][25] = {0};
    w[1][2] = 20; w[2][3] = 30; w[1][3] = 15;
    int ok = (solve_uva544(3, w, 1, 3) == 20);
    printf("%s: UVa 544 - Heavy Cargo\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
