/*
 * ==========================================================================
 * UVa 820 - Internet Bandwidth
 * Title-CN: 網際網路最大頻寬 (最大流 Edmonds-Karp)
 * Difficulty: UVa Star 2
 * Tags: graph, max-flow, edmonds-karp, network-flow
 * URL: https://onlinejudge.org/external/8/820.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Compute maximum network flow bandwidth from source s to destination t in undirected network graph.
 *
 * [中文] 題目說明:
 *     在無向容量網路中，求從資料來源 s 到匯點 t 能傳輸的最大頻寬流量 (經典最大流問題)。
 *
 * [EN] Approach:
 *     Edmonds-Karp algorithm (BFS augmenting paths). Keep residual graph, accumulate bottle neck capacities.
 * [中文] 思路:
 *     以 BFS 尋找殘餘網路中的最短增廣路徑 (Edmonds-Karp 演算法)，不斷增廣直到無法抵達匯點為止。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva820_maxflow(int n, int s, int t, int cap[105][105]) {
    int flow = 0;
    while (1) {
        int parent[105];
        for (int i = 1; i <= n; i++) parent[i] = -1;
        parent[s] = s;
        int q[105], head = 0, tail = 0;
        q[tail++] = s;
        while (head < tail && parent[t] == -1) {
            int u = q[head++];
            for (int v = 1; v <= n; v++) {
                if (parent[v] == -1 && cap[u][v] > 0) {
                    parent[v] = u;
                    q[tail++] = v;
                }
            }
        }
        if (parent[t] == -1) break; /* No augmenting path */
        int bottleneck = 1e9;
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            if (cap[u][v] < bottleneck) bottleneck = cap[u][v];
        }
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            cap[u][v] -= bottleneck;
            cap[v][u] += bottleneck;
        }
        flow += bottleneck;
    }
    return flow;
}

int main(void) {

    int c[105][105] = {0};
    c[1][2] = 20; c[2][4] = 20; c[1][3] = 10; c[3][4] = 10;
    int ok = (solve_uva820_maxflow(4, 1, 4, c) == 30);
    printf("%s: UVa 820 - Internet Bandwidth\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
