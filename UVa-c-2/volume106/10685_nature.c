/*
 * ==========================================================================
 * UVa 10685 - Nature
 * Title-CN: 食物鏈生物群落最大連通分支
 * Difficulty: UVa Star 2
 * Tags: graph, dsu
 * URL: https://onlinejudge.org/external/106/10685.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given predator-prey relationships between animals, find the size of the largest connected ecosystem network.
 *
 * [中文] 題目概述:
 *     給定動物之間的捕食連通關係，求出整個生態系中規模最大之連通生物群落所包含的物種數量。
 *
 * [EN] Approach:
 *     Disjoint-Set Union (DSU) with subtree size tracking. Return max(size[root]).
 * [中文] 解題思路:
 *     利用帶權並查集 (DSU) 維護連通分量大小，將相連物種合併，回傳集合大小的最大值。
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

int dsu_find10685(int *p, int i) { return p[i] == i ? i : (p[i] = dsu_find10685(p, p[i])); }

void dsu_union10685(int *p, int *sz, int u, int v) {
    int ru = dsu_find10685(p, u), rv = dsu_find10685(p, v);
    if (ru != rv) {
        p[ru] = rv;
        sz[rv] += sz[ru];
    }
}

int solve_uva10685(int c, int r, int edges[][2]) {
    int p[50], sz[50];
    for (int i = 0; i < c; i++) { p[i] = i; sz[i] = 1; }
    for (int i = 0; i < r; i++) dsu_union10685(p, sz, edges[i][0], edges[i][1]);
    int max_sz = 1;
    for (int i = 0; i < c; i++) if (sz[i] > max_sz) max_sz = sz[i];
    return max_sz;
}

int main(void) {

    int e[2][2] = {{0, 1}, {1, 2}};
    int m = solve_uva10685(4, 2, e);
    int ok = (m == 3);
    printf("%s: UVa 10685 - Nature\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
