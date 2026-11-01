/*
 * ==========================================================================
 * UVa 11518 - Dominos 2
 * Title-CN: 骨牌二部手動擊倒連鎖反應 DFS
 * Difficulty: UVa Star 1
 * Tags: graph, dfs
 * URL: https://onlinejudge.org/external/115/11518.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given directed domino knocking relationships, find total dominos that fall after a set of specific dominos are manually knocked over.
 *
 * [中文] 題目說明:
 *     給定骨牌推倒有向圖與手動推倒的骨牌編號列表，求因連鎖反應最終倒下的骨牌總張數。
 *
 * [EN] Approach:
 *     Standard Depth-First Search: from each manually pushed domino, run DFS marking visited dominos. Count all visited dominos.
 * [中文] 思路:
 *     多源深度優先搜尋：對所有手動推倒的骨牌發動 DFS，將倒下的骨牌標記為已訪問，最後統計訪問標記總數。
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

void dfs_domino(int u, int n, int adj[20][20], int *vis) {
    vis[u] = 1;
    for (int v = 0; v < n; v++) {
        if (adj[u][v] && !vis[v]) dfs_domino(v, n, adj, vis);
    }
}

int solve_uva11518(int n, int adj[20][20], int push_cnt, int *pushes) {
    int vis[20] = {0};
    for (int i = 0; i < push_cnt; i++) {
        int u = pushes[i];
        if (!vis[u]) dfs_domino(u, n, adj, vis);
    }
    int total = 0;
    for (int i = 0; i < n; i++) if (vis[i]) total++;
    return total;
}

int main(void) {

    int adj[20][20] = {0}, p[] = {0};
    adj[0][1] = 1; adj[1][2] = 1; // 0 -> 1 -> 2
    int f = solve_uva11518(3, adj, 1, p);
    int ok = (f == 3);
    printf("%s: UVa 11518 - Dominos 2\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
