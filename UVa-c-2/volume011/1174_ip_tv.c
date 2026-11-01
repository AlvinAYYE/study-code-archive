/*
 * ==========================================================================
 * UVa 1174 - IP-TV
 * Title-CN: IP 電視網路最小生成樹
 * Difficulty: Medium
 * Tags: Graph, MST, Kruskal
 * URL: https://onlinejudge.org/external/11/1174.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Connect all cities in an IP-TV network with the minimum total cost of optical fiber cables.
 *
 * [中文] 題目描述:
 *     給定城市之間的連接成本，求將所有城市連接起來的最小光纖電纜總成本（最小生成樹）。
 *
 * [EN] Approach:
 *     Apply Kruskal's algorithm with Disjoint-Set Union to find the Minimum Spanning Tree weight.
 *
 * [中文] 解題思維:
 *     使用 Kruskal 演算法搭配並查集計算圖的最小生成樹權重總和。
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

typedef struct {
    int u, v, cost;
} Edge1174;

static int cmp_edge1174(const void *a, const void *b) {
    return ((const Edge1174 *)a)->cost - ((const Edge1174 *)b)->cost;
}

static int find_set1174(int *p, int x) {
    if (p[x] < 0) return x;
    return p[x] = find_set1174(p, p[x]);
}

int kruskal_mst_cost(int n, int m, Edge1174 *edges) {
    qsort(edges, m, sizeof(Edge1174), cmp_edge1174);
    int p[1005];
    for (int i = 0; i <= n; i++) p[i] = -1;

    int total = 0, count = 0;
    for (int i = 0; i < m; i++) {
        int ru = find_set1174(p, edges[i].u);
        int rv = find_set1174(p, edges[i].v);
        if (ru != rv) {
            p[ru] = rv;
            total += edges[i].cost;
            if (++count == n - 1) break;
        }
    }
    return total;
}

int main(void) {

    Edge1174 edges[] = {{1, 2, 2}, {2, 3, 4}, {1, 3, 3}};
    int cost = kruskal_mst_cost(3, 3, edges);
    int ok = (cost == 5); // edges (1,2: 2) and (1,3: 3)
    printf("%s: UVa 1174 - IP-TV\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
