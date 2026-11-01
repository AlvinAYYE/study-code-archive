/*
 * ==========================================================================
 * UVa 1197 - The Suspects
 * Title-CN: 嫌疑犯 (並查集連通塊大小)
 * Difficulty: Easy
 * Tags: Disjoint Set Union
 * URL: https://onlinejudge.org/external/11/1197.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the number of suspects infected with SARS if person 0 is infected, given student club memberships.
 *
 * [中文] 題目說明:
 *     0 號學生確診 SARS，若同社團成員互相接觸，求受感染的潛在嫌疑犯總人數。
 *
 * [EN] Approach:
 *     Union-Find tracking component sizes. Union members of each club together. Return size of component containing 0.
 * [中文] 思路:
 *     使用維護集合大小的並查集將同社團成員合併，查詢 0 號所在連通塊的大小。
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

int dsu_find_sus(int *p, int x) { return p[x] == x ? x : (p[x] = dsu_find_sus(p, p[x])); }
void dsu_union_sus(int *p, int *sz, int a, int b) {
    int ra = dsu_find_sus(p, a), rb = dsu_find_sus(p, b);
    if (ra != rb) {
        p[ra] = rb;
        sz[rb] += sz[ra];
    }
}
int count_suspects(int n, int m, const int groups[][10], const int *g_sizes) {
    int p[100], sz[100];
    for (int i = 0; i < n; i++) { p[i] = i; sz[i] = 1; }
    for (int i = 0; i < m; i++) {
        for (int j = 1; j < g_sizes[i]; j++) {
            dsu_union_sus(p, sz, groups[i][0], groups[i][j]);
        }
    }
    return sz[dsu_find_sus(p, 0)];
}

int main(void) {

    int g[2][10] = {{0, 1}, {1, 2}}, sz[] = {2, 2};
    int res = count_suspects(3, 2, g, sz);
    int ok = (res == 3);
    printf("%s: UVa 1197 - The Suspects\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
