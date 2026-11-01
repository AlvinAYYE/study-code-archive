/*
 * ==========================================================================
 * UVa 10842 - Traffic Flow
 * Title-CN: 交通流量 (最大生成樹瓶頸邊)
 * Difficulty: Medium
 * Tags: Graph, MST, Kruskal
 * URL: https://onlinejudge.org/external/108/10842.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find maximum minimum capacity of a subgraph connecting all n intersections (Maximum Spanning Tree minimum edge weight).
 *
 * [中文] 題目說明:
 *     求連接所有 n 個交叉路口使得全圖連通的子圖中，最小道路容量的最大值（即最大生成樹的最輕邊權重）。
 *
 * [EN] Approach:
 *     Sort edges descending by capacity. Run Kruskal's algorithm until all n nodes are connected in a single component. The last added edge weight is the answer.
 * [中文] 思路:
 *     將邊依容量降序排序，使用 Kruskal 演算法構建最大生成樹，最後加入樹中的邊權即為瓶頸最大值。
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

int find_tf(int *p, int x) { return p[x] == x ? x : (p[x] = find_tf(p, p[x])); }
int max_traffic_flow(int n, int m, int edges[][3]) {
    // Sort descending by weight
    for (int i = 0; i < m - 1; i++)
        for (int j = i + 1; j < m; j++)
            if (edges[i][2] < edges[j][2]) {
                for (int k = 0; k < 3; k++) {
                    int t = edges[i][k]; edges[i][k] = edges[j][k]; edges[j][k] = t;
                }
            }
    int p[50];
    for (int i = 0; i < n; i++) p[i] = i;
    int min_w = 1000000;
    int edges_added = 0;
    for (int i = 0; i < m; i++) {
        int u = edges[i][0], v = edges[i][1], w = edges[i][2];
        int ru = find_tf(p, u), rv = find_tf(p, v);
        if (ru != rv) {
            p[ru] = rv;
            if (w < min_w) min_w = w;
            edges_added++;
            if (edges_added == n - 1) break;
        }
    }
    return min_w;
}

int main(void) {

    int edges[3][3] = {{0, 1, 10}, {1, 2, 20}, {0, 2, 5}};
    int res = max_traffic_flow(3, 3, edges); // take 20 and 10 -> bottleneck is 10
    int ok = (res == 10);
    printf("%s: UVa 10842 - Traffic Flow\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
