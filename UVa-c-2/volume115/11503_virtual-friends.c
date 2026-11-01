/*
 * ==========================================================================
 * UVa 11503 - Virtual Friends
 * Title-CN: 虛擬交友網路好友圈規模
 * Difficulty: UVa Star 2
 * Tags: graph, dsu
 * URL: https://onlinejudge.org/external/115/11503.pdf
 * ==========================================================================
 * [EN] Problem:
 *     When two people become friends, merge their friend networks and output the total size of their combined network.
 *
 * [中文] 題目說明:
 *     每當兩人建立好友關係時，合併雙方的朋友圈，並即時輸出該好友圈所包含的總人數。
 *
 * [EN] Approach:
 *     Disjoint-Set Union with size tracking (size[root]). Return size[find(u)] after union.
 * [中文] 思路:
 *     帶權並查集 (DSU)：維護每個連通分量的大小 size[root]，每次合併兩集合代表元時將大小相加並回傳新集合大小。
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

int vf_find(int *p, int i) {
    if (p[i] == i) return i;
    return p[i] = vf_find(p, p[i]);
}

int solve_uva11503_union(int *p, int *sz, int u, int v) {
    int ru = vf_find(p, u);
    int rv = vf_find(p, v);
    if (ru != rv) {
        p[ru] = rv;
        sz[rv] += sz[ru];
    }
    return sz[rv];
}

int main(void) {

    int p[10] = {0, 1, 2, 3}, sz[10] = {1, 1, 1, 1};
    int s1 = solve_uva11503_union(p, sz, 0, 1);
    int s2 = solve_uva11503_union(p, sz, 1, 2);
    int ok = (s1 == 2 && s2 == 3);
    printf("%s: UVa 11503 - Virtual Friends\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
