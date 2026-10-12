/*
 * ==========================================================================
 * UVa 10034 - Freckles
 * Title-CN: 雀斑連線 (最小生成樹 MST)
 * Difficulty: UVa Star 2
 * Tags: graph, mst, kruskal, prim
 * URL: https://onlinejudge.org/external/100/10034.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given N points on a 2D plane, find the minimum total length of ink lines
 *     needed to connect all points into a single connected component.
 *
 * [中文] 題目說明:
 *     平面上有 N 個雀斑點，求連接所有雀斑所需的最小墨水總長度（最小生成樹 MST）。
 *
 * [EN] Approach:
 *     Prim's or Kruskal's algorithm on complete Euclidean graph.
 * [中文] 思路:
 *     計算所有點對間的歐幾里得距離，使用 Prim 或 Kruskal 演算法求解最小生成樹。
 * ==========================================================================
 */
#include <stdio.h>
#include <math.h>

double solve_uva10034(int n, const double pts[][2]) {
    double dist[105];
    int in_mst[105] = {0};
    for (int i = 0; i < n; i++) dist[i] = 1e18;
    dist[0] = 0.0;

    double total = 0.0;
    for (int step = 0; step < n; step++) {
        int u = -1;
        for (int i = 0; i < n; i++) {
            if (!in_mst[i] && (u == -1 || dist[i] < dist[u])) {
                u = i;
            }
        }
        in_mst[u] = 1;
        total += dist[u];

        for (int v = 0; v < n; v++) {
            if (!in_mst[v]) {
                double d = hypot(pts[u][0] - pts[v][0], pts[u][1] - pts[v][1]);
                if (d < dist[v]) dist[v] = d;
            }
        }
    }
    return total;
}

int main(void) {
    double pts[3][2] = {
        {1.0, 1.0},
        {2.0, 2.0},
        {2.0, 4.0}
    };
    double cost = solve_uva10034(3, pts);
    int ok = (fabs(cost - 3.4142) < 0.01);
    printf("%s: UVa 10034 - Freckles\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
