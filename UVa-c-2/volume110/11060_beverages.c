/*
 * ==========================================================================
 * UVa 11060 - Beverages
 * Title-CN: 飲品偏好偏序關係拓撲排序
 * Difficulty: UVa Star 2
 * Tags: graph, topological-sort
 * URL: https://onlinejudge.org/external/110/11060.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given N beverages in original input order and precedence rules, output a legal drinking sequence respecting priority (Kahn's topological sort).
 *
 * [中文] 題目說明:
 *     給定飲料初始偏好順序與飲用先後依賴關係，輸出滿足依賴約束且優先維持原輸入順序之合法飲用序列 (Kahn 拓撲排序)。
 *
 * [EN] Approach:
 *     Kahn's algorithm using in-degree array. Repeatedly pick the smallest-index available node with in-degree 0.
 * [中文] 思路:
 *     維護入度陣列，每輪挑選入度為 0 且在原輸入中編號最小的節點加入序列並扣減相鄰節點之入度。
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

void solve_uva11060(int n, int adj[20][20], int *out_seq) {
    int in_deg[20] = {0};
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (adj[i][j]) in_deg[j]++;
    int vis[20] = {0};
    for (int step = 0; step < n; step++) {
        int u = -1;
        for (int i = 0; i < n; i++) {
            if (!vis[i] && in_deg[i] == 0) { u = i; break; }
        }
        out_seq[step] = u;
        vis[u] = 1;
        for (int v = 0; v < n; v++) {
            if (adj[u][v]) in_deg[v]--;
        }
    }
}

int main(void) {

    int adj[20][20] = {0}, seq[20];
    adj[0][1] = 1; // 0 before 1
    solve_uva11060(2, adj, seq);
    int ok = (seq[0] == 0 && seq[1] == 1);
    printf("%s: UVa 11060 - Beverages\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
