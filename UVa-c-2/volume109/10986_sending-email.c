/*
 * ==========================================================================
 * UVa 10986 - Sending email
 * Title-CN: 伺服器郵件路由最短延遲時間
 * Difficulty: UVa Star 2
 * Tags: graph, dijkstra, shortest-path
 * URL: https://onlinejudge.org/external/109/10986.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the minimum latency path to route an email from source server S to destination server T in an undirected network.
 *
 * [中文] 題目說明:
 *     在帶有權重的無向伺服器網路中，求將電子郵件自來源主機 S 傳送至目標主機 T 的最短延遲時間。
 *
 * [EN] Approach:
 *     Dijkstra's shortest path algorithm. Return distance to T, or -1 if unreachable.
 * [中文] 思路:
 *     以標準 Dijkstra 演算法求解單源最短路徑，維護最小距離陣列，若目的地不可達則回傳 -1。
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

int solve_uva10986(int n, int adj[50][50], int src, int dst) {
    int dist[50], vis[50] = {0};
    for (int i = 0; i < n; i++) dist[i] = 1e9;
    dist[src] = 0;
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
    return dist[dst] < 1e9 ? dist[dst] : -1;
}

int main(void) {

    int adj[50][50];
    for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) adj[i][j] = -1;
    adj[0][1] = adj[1][0] = 10;
    adj[1][2] = adj[2][1] = 20;
    int d = solve_uva10986(3, adj, 0, 2);
    int ok = (d == 30);
    printf("%s: UVa 10986 - Sending email\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
