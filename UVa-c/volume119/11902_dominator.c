/*
 * ==========================================================================
 * UVa 11902 - Dominator
 * Title-CN: 支配點判定
 * Difficulty: Medium
 * Tags: Graph, DFS, Dominator Tree
 * URL: https://onlinejudge.org/external/119/11902.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given a directed graph, determine for every pair (u, v) if node u dominates node v (every path from start 0 to v must pass through u).
 *
 * [中文] 題目說明:
 *     給定有向圖，判斷節點 u 是否為節點 v 的支配點（從起點 0 到 v 的所有路徑皆必經 u）。
 *
 * [EN] Approach:
 *     First DFS to find all nodes reachable from 0. For each node u, run DFS ignoring u; any node reachable initially but not without u is dominated by u.
 * [中文] 思路:
 *     先求起點 0 能抵達的節點集合。枚舉節點 u，忽略 u 進行 DFS，原本可達而現在不可達的點即被 u 支配。
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

void dfs_reach_dom(int u, int n, const int adj[10][10], int disabled, bool *vis) {
    if (u == disabled) return;
    vis[u] = true;
    for (int v = 0; v < n; v++) {
        if (adj[u][v] && !vis[v]) dfs_reach_dom(v, n, adj, disabled, vis);
    }
}
void find_dominators(int n, const int adj[10][10], bool dom[10][10]) {
    bool reach[10] = {false};
    dfs_reach_dom(0, n, adj, -1, reach);
    for (int u = 0; u < n; u++) {
        bool cur[10] = {false};
        dfs_reach_dom(0, n, adj, u, cur);
        for (int v = 0; v < n; v++) {
            if (reach[v] && (!cur[v] || u == v)) dom[u][v] = true;
            else dom[u][v] = false;
        }
    }
}

int main(void) {

    int adj[3][3] = {{0,1,0}, {0,0,1}, {0,0,0}};
    bool dom[10][10];
    find_dominators(3, adj, dom);
    // 0 -> 1 -> 2: 0 dominates all, 1 dominates 1 and 2
    int ok = dom[0][0] && dom[0][1] && dom[0][2] && dom[1][2];
    printf("%s: UVa 11902 - Dominator\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
