/*
 * ==========================================================================
 * UVa 908 - Re-connecting Computer Sites
 * Title-CN: 電腦線路重建最小生成樹重算
 * Difficulty: UVa Star 2
 * Tags: graph, mst, kruskal
 * URL: https://onlinejudge.org/external/9/908.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Compare original spanning tree weight with new minimum spanning tree weight after adding K new candidate lines and M available existing lines.
 *
 * [中文] 題目概述:
 *     比較原有網路生成樹總權重，與加入 K 條新線路與 M 條原有線路重新計算最小生成樹後之總權重。
 *
 * [EN] Approach:
 *     Kruskal's algorithm: combine K new lines and M existing lines, sort by cost, and build new MST. Print old cost and new cost.
 * [中文] 解題思路:
 *     Kruskal 演算法：將新候選邊與原邊集合併後按權重排序，重新構建最小生成樹求出最佳建置成本。
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

typedef struct { int u, v, w; } Edge908;
static int cmp908(const void *a, const void *b) { return ((Edge908*)a)->w - ((Edge908*)b)->w; }
int find908(int *p, int i) { return p[i] == i ? i : (p[i] = find908(p, p[i])); }

int solve_uva908_mst(int n, int m, Edge908 *e) {
    qsort(e, m, sizeof(Edge908), cmp908);
    int p[30];
    for (int i = 0; i < n; i++) p[i] = i;
    int total = 0, cnt = 0;
    for (int i = 0; i < m; i++) {
        int ru = find908(p, e[i].u), rv = find908(p, e[i].v);
        if (ru != rv) {
            p[ru] = rv;
            total += e[i].w;
            cnt++;
        }
    }
    return total;
}

int main(void) {

    Edge908 e[] = {{0, 1, 10}, {1, 2, 5}, {0, 2, 8}};
    int cost = solve_uva908_mst(3, 3, e); // 5 + 8 = 13
    int ok = (cost == 13);
    printf("%s: UVa 908 - Re-connecting Computer Sites\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
