/*
 * ==========================================================================
 * UVa 10600 - ACM Contest and Blackout
 * Title-CN: 次小生成樹邊權和計算
 * Difficulty: UVa Star 2
 * Tags: graph, mst, kruskal
 * URL: https://onlinejudge.org/external/106/10600.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the weight of the Minimum Spanning Tree (MST) and the second-best Minimum Spanning Tree.
 *
 * [中文] 題目說明:
 *     計算給定無向連通網路之最小生成樹 (MST) 邊權和，以及次小生成樹 (Second MST) 邊權和。
 *
 * [EN] Approach:
 *     Run Kruskal's algorithm to obtain MST edges. For each edge in MST, temporarily remove it, re-run Kruskal, and take minimum among all valid spanning trees.
 * [中文] 思路:
 *     先求出最佳 MST，依序強制禁用 MST 中的每一條邊並重跑 Kruskal，在所有依然連通的生成樹中取邊權和最小者即為次小生成樹。
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

typedef struct { int u, v, w; } Edge10600;

int find10600(int *p, int i) { return p[i] == i ? i : (p[i] = find10600(p, p[i])); }

int kruskal_ex(int n, int m, Edge10600 *e, int skip_idx) {
    int p[20];
    for (int i = 0; i < n; i++) p[i] = i;
    int weight = 0, count = 0;
    for (int i = 0; i < m; i++) {
        if (i == skip_idx) continue;
        int ru = find10600(p, e[i].u), rv = find10600(p, e[i].v);
        if (ru != rv) {
            p[ru] = rv;
            weight += e[i].w;
            count++;
        }
    }
    return (count == n - 1) ? weight : 1e9;
}

int main(void) {

    Edge10600 e[] = {{0, 1, 10}, {1, 2, 20}, {0, 2, 25}};
    int w1 = kruskal_ex(3, 3, e, -1); // 10+20=30
    int w2 = kruskal_ex(3, 3, e, 0);  // skip 10: 20+25=45
    int ok = (w1 == 30 && w2 == 45);
    printf("%s: UVa 10600 - ACM Contest and Blackout\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
