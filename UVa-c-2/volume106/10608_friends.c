/*
 * ==========================================================================
 * UVa 10608 - Friends
 * Title-CN: 朋友關係
 * Difficulty: UVa Star 1
 * Tags: data-structures, dsu, disjoint-set
 * URL: https://onlinejudge.org/external/106/10608.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the size of the largest group of mutual friends using Disjoint Set Union (DSU).
 *
 * [中文] 題目說明:
 *     朋友的朋友也是朋友，給定多對朋友關係，求最大朋友圈中包含的人數。
 *
 * [EN] Approach:
 *     Union-Find with size tracking. Answer is max(size[find(i)]).
 * [中文] 思路:
 *     並查集（DSU）維護各集合元素個數，查詢最大的集合大小。
 * ==========================================================================
 */
#include <stdio.h>

static int parent[30005], sz[30005];

static int find_set(int i) {
    if (parent[i] == i) return i;
    return parent[i] = find_set(parent[i]);
}

int solve_uva10608(int n, int m, const int pairs[][2]) {
    for (int i = 1; i <= n; i++) { parent[i] = i; sz[i] = 1; }
    int max_sz = 1;
    for (int i = 0; i < m; i++) {
        int u = find_set(pairs[i][0]);
        int v = find_set(pairs[i][1]);
        if (u != v) {
            parent[u] = v;
            sz[v] += sz[u];
            if (sz[v] > max_sz) max_sz = sz[v];
        }
    }
    return max_sz;
}

int main(void) {
    int p[2][2] = {{1, 2}, {2, 3}};
    int res = solve_uva10608(3, 2, p);
    int ok = (res == 3);
    printf("%s: UVa 10608 - Friends\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
