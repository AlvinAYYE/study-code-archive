/*
 * ==========================================================================
 * UVa 11631 - Dark roads
 * Title-CN: 黑暗道路最小生成樹省電節能
 * Difficulty: UVa Star 2
 * Tags: graph, mst, kruskal
 * URL: https://onlinejudge.org/external/116/11631.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the maximum total electricity money saved by turning off street lights on redundant roads while keeping all junctions connected.
 *
 * [中文] 題目說明:
 *     在保證所有路口彼此連通的前提下關閉多餘道路的路燈，求最多可節省之照明總費用 (原總權重扣除最小生成樹權重)。
 *
 * [EN] Approach:
 *     Kruskal's algorithm: compute total edge weight minus weight of Minimum Spanning Tree (MST).
 * [中文] 思路:
 *     利用 Kruskal 演算法求出最小生成樹 (MST) 的邊權和，節省費用即為總邊權減去 MST 邊權。
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

typedef struct { int u, v, w; } Edge11631;

static int cmp_edge11631(const void *a, const void *b) {
    return ((Edge11631*)a)->w - ((Edge11631*)b)->w;
}

int mst_find(int *p, int i) {
    return p[i] == i ? i : (p[i] = mst_find(p, p[i]));
}

int solve_uva11631(int n, int m, Edge11631 *e) {
    qsort(e, m, sizeof(Edge11631), cmp_edge11631);
    int p[50];
    for (int i = 0; i < n; i++) p[i] = i;
    int mst_w = 0, total_w = 0;
    for (int i = 0; i < m; i++) {
        total_w += e[i].w;
        int ru = mst_find(p, e[i].u);
        int rv = mst_find(p, e[i].v);
        if (ru != rv) {
            p[ru] = rv;
            mst_w += e[i].w;
        }
    }
    return total_w - mst_w;
}

int main(void) {

    Edge11631 e[] = {{0, 1, 10}, {1, 2, 20}, {0, 2, 25}};
    int saved = solve_uva11631(3, 3, e);
    int ok = (saved == 25);
    printf("%s: UVa 11631 - Dark roads\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
