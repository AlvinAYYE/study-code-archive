/*
 * ==========================================================================
 * UVa 10147 - Highways
 * Title-CN: 公路系統建設
 * Difficulty: Medium
 * Tags: Graph, MST, Kruskal
 * URL: https://onlinejudge.org/external/101/10147.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given town locations and already existing highways, find additional highways to build to connect all towns with minimum total length.
 *
 * [中文] 題目概述:
 *     給定城鎮座標與已建成的公路，求需額外興建哪些公路以最小總成本使所有城鎮連通。
 *
 * [EN] Approach:
 *     Kruskal's algorithm: pre-union existing highway endpoints in DSU, sort all remaining pairs by Euclidean distance, add edges connecting different components.
 * [中文] 解題思路:
 *     Kruskal 演算法：將已存在的公路端點在並查集中預先合併，將剩餘點對按歐氏距離排序，依序加入連接不同分量的邊。
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

int hwy_find(int *p, int x) { return p[x] == x ? x : (p[x] = hwy_find(p, p[x])); }
int hwy_union(int *p, int a, int b) {
    int ra = hwy_find(p, a), rb = hwy_find(p, b);
    if (ra != rb) { p[ra] = rb; return 1; }
    return 0;
}
int new_highways_needed(int n, int *parent) {
    int comps = 0;
    for (int i = 1; i <= n; i++) if (parent[i] == i) comps++;
    return comps - 1;
}

int main(void) {

    int p[10];
    for (int i = 1; i <= 4; i++) p[i] = i;
    hwy_union(p, 1, 2);
    int ok = (new_highways_needed(4, p) == 2);
    printf("%s: UVa 10147 - Highways\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
