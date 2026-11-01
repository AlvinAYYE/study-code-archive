/*
 * ==========================================================================
 * UVa 762 - We Ship Cheap
 * Title-CN: 城市航線貨運最短轉機路徑 BFS
 * Difficulty: UVa Star 2
 * Tags: graph, bfs, shortest-path
 * URL: https://onlinejudge.org/external/7/762.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the route with the minimum number of flight connections between city A and city B.
 *
 * [中文] 題目概述:
 *     在城市航線網路中，找出從起點城市 A 運送至終點城市 B 所需轉機次數最少的最短飛行路徑。
 *
 * [EN] Approach:
 *     BFS on undirected graph using city name mappings and parent pointers to reconstruct and output the path.
 * [中文] 解題思路:
 *     以廣度優先搜尋 (BFS) 尋找最短轉機步數，維護 parent 前驅陣列，回溯重構路徑各航段城市代碼。
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

int solve_uva762_bfs(int n, int adj[20][20], int src, int dst, int *parent) {
    int dist[20], q[20], head = 0, tail = 0;
    for (int i = 0; i < n; i++) { dist[i] = -1; parent[i] = -1; }
    q[tail++] = src; dist[src] = 0;
    while (head < tail) {
        int u = q[head++];
        if (u == dst) return dist[u];
        for (int v = 0; v < n; v++) {
            if (adj[u][v] && dist[v] == -1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q[tail++] = v;
            }
        }
    }
    return -1;
}

int main(void) {

    int adj[20][20] = {0}, p[20];
    adj[0][1] = adj[1][0] = 1; adj[1][2] = adj[2][1] = 1;
    int d = solve_uva762_bfs(3, adj, 0, 2, p);
    int ok = (d == 2 && p[2] == 1 && p[1] == 0);
    printf("%s: UVa 762 - We Ship Cheap\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
