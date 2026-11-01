/*
 * ==========================================================================
 * UVa 1395 - Slim Spanning Tree
 * Title-CN: 苗條生成樹 (最小化極差)
 * Difficulty: Medium
 * Tags: Graph, MST, Kruskal, Two Pointers
 * URL: https://onlinejudge.org/external/13/1395.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find a spanning tree that minimizes the difference between the maximum and minimum edge weights.
 *
 * [中文] 題目描述:
 *     在給定的無向連通圖中，求一棵生成樹使得最大邊權與最小邊權之差最小。
 *
 * [EN] Approach:
 *     Sort edges by weight. For each possible starting edge, run Kruskal's to find spanning tree and record difference.
 *
 * [中文] 解題思維:
 *     將邊按權重由小到大排序。枚舉每一條邊作為生成樹的最小邊，使用 Kruskal 尋找生成樹，記錄差值的最小值。
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
    int u, v, w;
} Edge1395;

static int cmp_edge1395(const void *a, const void *b) {
    return ((const Edge1395 *)a)->w - ((const Edge1395 *)b)->w;
}

static int find_set1395(int *p, int x) {
    if (p[x] < 0) return x;
    return p[x] = find_set1395(p, p[x]);
}

int min_slim_spanning_tree(int n, int m, Edge1395 *edges) {
    qsort(edges, m, sizeof(Edge1395), cmp_edge1395);
    int p[105];
    int ans = 100000000;

    for (int l = 0; l < m; l++) {
        for (int i = 0; i <= n; i++) p[i] = -1;
        int count = 0, max_w = edges[l].w;
        for (int r = l; r < m; r++) {
            int ru = find_set1395(p, edges[r].u);
            int rv = find_set1395(p, edges[r].v);
            if (ru != rv) {
                p[ru] = rv;
                max_w = edges[r].w;
                if (++count == n - 1) {
                    int diff = max_w - edges[l].w;
                    if (diff < ans) ans = diff;
                    break;
                }
            }
        }
    }
    return ans == 100000000 ? -1 : ans;
}

int main(void) {

    Edge1395 e[] = {{1, 2, 10}, {2, 3, 20}, {1, 3, 30}};
    // Spanning tree with (10, 20) has diff 20 - 10 = 10
    int res = min_slim_spanning_tree(3, 3, e);
    int ok = (res == 10);
    printf("%s: UVa 1395 - Slim Spanning Tree\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
