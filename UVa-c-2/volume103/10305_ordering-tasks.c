/*
 * ==========================================================================
 * UVa 10305 - Ordering Tasks
 * Title-CN: 任務排序 (拓撲排序)
 * Difficulty: UVa Star 1
 * Tags: graph, topological-sort, dfs
 * URL: https://onlinejudge.org/external/103/10305.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find a valid topological order of tasks given precedence constraints.
 *
 * [中文] 題目說明:
 *     給定有向任務依賴關係，輸出一個合法的拓撲排序任務執行順序。
 *
 * [EN] Approach:
 *     Kahn's algorithm with queue or DFS post-order reversal.
 * [中文] 思路:
 *     入度陣列佇列拓撲排序（Kahn 演算法）或 DFS 逆後序。
 * ==========================================================================
 */
#include <stdio.h>

void solve_uva10305(int n, int m, const int edges[][2], int *order) {
    int in_deg[105] = {0};
    int adj[105][105], deg[105] = {0};
    for (int i = 0; i < m; i++) {
        int u = edges[i][0], v = edges[i][1];
        adj[u][deg[u]++] = v;
        in_deg[v]++;
    }
    int q[105], head = 0, tail = 0;
    for (int i = 1; i <= n; i++) if (in_deg[i] == 0) q[tail++] = i;

    int idx = 0;
    while (head < tail) {
        int u = q[head++];
        order[idx++] = u;
        for (int i = 0; i < deg[u]; i++) {
            int v = adj[u][i];
            if (--in_deg[v] == 0) q[tail++] = v;
        }
    }
}

int main(void) {
    int e[2][2] = {{1, 2}, {2, 3}};
    int ord[3];
    solve_uva10305(3, 2, e, ord);
    int ok = (ord[0] == 1 && ord[1] == 2 && ord[2] == 3);
    printf("%s: UVa 10305 - Ordering Tasks\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
