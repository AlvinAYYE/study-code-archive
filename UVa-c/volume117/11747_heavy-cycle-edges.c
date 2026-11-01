/*
 * ==========================================================================
 * UVa 11747 - Heavy Cycle Edges
 * Title-CN: 環路最大冗餘邊 Kruskal 篩選
 * Difficulty: UVa Star 2
 * Tags: graph, mst, kruskal
 * URL: https://onlinejudge.org/external/117/11747.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find all edges in an undirected graph that are the heaviest edge on some cycle (i.e. edges discarded by Kruskal's algorithm).
 *
 * [中文] 題目說明:
 *     在無向圖中找出所有落在某環路上的最重邊 (即 Kruskal 最小生成樹演算法中因形成環而被丟棄的邊)。
 *
 * [EN] Approach:
 *     Run Kruskal's algorithm on edges sorted by weight. Any edge whose endpoints are already in the same connected component is collected and printed.
 * [中文] 思路:
 *     按權重排序邊集執行 Kruskal 演算法：每當遇到兩端點已連通的邊，即為環中最重邊，收集此類邊排序輸出。
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

typedef struct { int u, v, w; } Edge11747;

int cmp11747(const void *a, const void *b) { return ((Edge11747*)a)->w - ((Edge11747*)b)->w; }
int find11747(int *p, int i) { return p[i] == i ? i : (p[i] = find11747(p, p[i])); }

int solve_uva11747(int n, int m, Edge11747 *e, int *heavy_weights) {
    qsort(e, m, sizeof(Edge11747), cmp11747);
    int p[20];
    for (int i = 0; i < n; i++) p[i] = i;
    int h_cnt = 0;
    for (int i = 0; i < m; i++) {
        int ru = find11747(p, e[i].u), rv = find11747(p, e[i].v);
        if (ru == rv) {
            heavy_weights[h_cnt++] = e[i].w;
        } else {
            p[ru] = rv;
        }
    }
    return h_cnt;
}

int main(void) {

    Edge11747 e[] = {{0, 1, 1}, {1, 2, 2}, {0, 2, 3}};
    int hw[5];
    int c = solve_uva11747(3, 3, e, hw);
    int ok = (c == 1 && hw[0] == 3);
    printf("%s: UVa 11747 - Heavy Cycle Edges\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
