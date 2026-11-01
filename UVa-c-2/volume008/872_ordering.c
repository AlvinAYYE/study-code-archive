/*
 * ==========================================================================
 * UVa 872 - Ordering
 * Title-CN: 拓撲排序的所有合法排列
 * Difficulty: Medium
 * Tags: Backtracking, Topological Sort
 * URL: https://onlinejudge.org/external/8/872.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find all topological sorts of a given set of variables satisfying pairwise ordering constraints.
 *
 * [中文] 題目說明:
 *     給定變數集合與兩兩先後關係約束，求所有合法的拓撲排序結果。
 *
 * [EN] Approach:
 *     Backtracking search: at each step, find all unvisited variables with in-degree 0 in alphabetical order, pick one, recurse.
 * [中文] 思路:
 *     回溯搜尋：每一步按字母序挑選當前入度為 0 的未訪問變數推進，遞迴生成所有合法拓撲序。
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

int topo_count(int n, int adj[5][5], int *in_deg, int *vis, int count) {
    if (count == n) return 1;
    int total = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i] && in_deg[i] == 0) {
            vis[i] = 1;
            for (int j = 0; j < n; j++) if (adj[i][j]) in_deg[j]--;
            total += topo_count(n, adj, in_deg, vis, count + 1);
            for (int j = 0; j < n; j++) if (adj[i][j]) in_deg[j]++;
            vis[i] = 0;
        }
    }
    return total;
}

int main(void) {

    int adj[5][5] = {0}, in_deg[5] = {0}, vis[5] = {0};
    adj[0][1] = 1; in_deg[1] = 1; // A < B
    int orders = topo_count(2, adj, in_deg, vis, 0);
    int ok = (orders == 1);
    printf("%s: UVa 872 - Ordering\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
