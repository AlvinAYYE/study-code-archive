/*
 * ==========================================================================
 * UVa 10806 - Dijkstra, Dijkstra.
 * Title-CN: 去回不重複路徑之最小總長度
 * Difficulty: Hard
 * Tags: Network Flow, Min-Cost Max-Flow, MCMF
 * URL: https://onlinejudge.org/external/108/10806.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find two edge-disjoint paths from vertex 1 to vertex N with minimum total length (there and back).
 *
 * [中文] 題目描述:
 *     求從頂點 1 到頂點 N 的兩條邊不相交路徑（去與回走不同邊），使其總權重和最小。
 *
 * [EN] Approach:
 *     Model as Min-Cost Max-Flow: find flow of 2 from source 1 to sink N where each edge has capacity 1.
 *
 * [中文] 解題思維:
 *     轉化為最小費用最大流問題：每條無向邊容量為 1，求從頂點 1 到 N 流量為 2 的最小費用流。
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

#define MCMF_INF 100000000

typedef struct {
    int to, cap, flow, cost, rev;
} MCMF_Edge;

static MCMF_Edge mcmf_adj[105][205];
static int mcmf_deg[105];

static void add_mcmf_edge(int from, int to, int cap, int cost) {
    mcmf_adj[from][mcmf_deg[from]] = (MCMF_Edge){to, cap, 0, cost, mcmf_deg[to]};
    mcmf_deg[from]++;
    mcmf_adj[to][mcmf_deg[to]] = (MCMF_Edge){from, 0, 0, -cost, mcmf_deg[from] - 1};
    mcmf_deg[to]++;
}

int min_cost_two_paths(int n, int m, int edges[][3]) {
    for (int i = 0; i <= n; i++) mcmf_deg[i] = 0;
    for (int i = 0; i < m; i++) {
        int u = edges[i][0], v = edges[i][1], w = edges[i][2];
        add_mcmf_edge(u, v, 1, w);
        add_mcmf_edge(v, u, 1, w);
    }
    int s = 1, t = n;
    int flow = 0, cost = 0;
    int dist[105], prev_v[105], prev_e[105], inq[105];

    while (flow < 2) {
        for (int i = 1; i <= n; i++) { dist[i] = MCMF_INF; inq[i] = 0; }
        int q[5000], head = 0, tail = 0;
        dist[s] = 0; q[tail++] = s; inq[s] = 1;

        while (head < tail) {
            int u = q[head++];
            inq[u] = 0;
            for (int i = 0; i < mcmf_deg[u]; i++) {
                MCMF_Edge *e = &mcmf_adj[u][i];
                if (e->cap > e->flow && dist[e->to] > dist[u] + e->cost) {
                    dist[e->to] = dist[u] + e->cost;
                    prev_v[e->to] = u;
                    prev_e[e->to] = i;
                    if (!inq[e->to]) {
                        q[tail++] = e->to;
                        inq[e->to] = 1;
                    }
                }
            }
        }
        if (dist[t] == MCMF_INF) return -1; // cannot find 2 paths

        flow++;
        cost += dist[t];
        for (int v = t; v != s; v = prev_v[v]) {
            MCMF_Edge *e = &mcmf_adj[prev_v[v]][prev_e[v]];
            e->flow += 1;
            mcmf_adj[v][e->rev].flow -= 1;
        }
    }
    return cost;
}

int main(void) {

    int edges[][3] = {{1, 2, 1}, {2, 3, 1}, {1, 3, 5}};
    // Path 1: 1->2->3 (cost 2), Path 2: 1->3 (cost 5), total = 7
    int res = min_cost_two_paths(3, 3, edges);
    int ok = (res == 7);
    printf("%s: UVa 10806 - Dijkstra, Dijkstra.\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
