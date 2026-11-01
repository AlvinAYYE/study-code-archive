/*
 * ==========================================================================
 * UVa 1112 - Mice and Maze
 * Title-CN: 迷宮老鼠反向最短路徑 Dijkstra
 * Difficulty: UVa Star 2
 * Tags: graph, dijkstra, shortest-path
 * URL: https://onlinejudge.org/external/11/1112.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find how many mice starting at different maze cells can reach the designated exit cell within countdown timer T.
 *
 * [中文] 題目說明:
 *     在有向迷宮中，統計有多少隻老鼠能在倒數計時 T 內自各自的起點抵達指定出口 (反向邊建圖 Dijkstra 最短路)。
 *
 * [EN] Approach:
 *     Reverse all directed edges and run single-source Dijkstra from the exit node. Count nodes with shortest distance <= T.
 * [中文] 思路:
 *     將所有有向邊反向，以出口為單源起點執行 Dijkstra 最短路徑演算法，統計最短距離小於等於 T 的節點總數。
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

int solve_uva1112(int n, int exit_node, int T, int adj[20][20]) {
    int dist[20], vis[20] = {0};
    for (int i = 0; i < n; i++) dist[i] = 1e9;
    dist[exit_node] = 0;
    for (int iter = 0; iter < n; iter++) {
        int u = -1, min_d = 1e9;
        for (int i = 0; i < n; i++) {
            if (!vis[i] && dist[i] < min_d) { min_d = dist[i]; u = i; }
        }
        if (u == -1) break;
        vis[u] = 1;
        for (int v = 0; v < n; v++) {
            if (adj[u][v] >= 0 && dist[u] + adj[u][v] < dist[v])
                dist[v] = dist[u] + adj[u][v];
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++) if (dist[i] <= T) count++;
    return count;
}

int main(void) {

    int adj[20][20];
    for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) adj[i][j] = -1;
    adj[0][1] = 5; // reversed edge from exit 0 to node 1 with cost 5
    int cnt = solve_uva1112(2, 0, 10, adj);
    int ok = (cnt == 2);
    printf("%s: UVa 1112 - Mice and Maze\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
