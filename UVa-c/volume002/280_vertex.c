/*
 * ==========================================================================
 * UVa 280 - Vertex
 * Title-CN: 頂點可達性 (有向圖 DFS 走訪)
 * Difficulty: UVa Star 1
 * Tags: graph, dfs, bfs, reachability
 * URL: https://onlinejudge.org/external/2/280.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given directed graph, find all vertices not reachable from a given starting vertex via length >= 1 paths.
 *
 * [中文] 題目說明:
 *     在有向圖中，求從指定頂點出發無法透過長度大於等於 1 的路徑抵達的所有頂點個數與列表。
 *
 * [EN] Approach:
 *     Standard DFS/BFS starting from neighbors of u (path length must be >= 1). Count unvisited nodes.
 * [中文] 思路:
 *     從起點的鄰接節點出發進行 DFS 走訪 (長度必須至少為 1)，統計未被標記造訪的節點總數。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva280_unreachable(int n, int adj[105][105], int start, int *out_list) {
    int visited[105] = {0};
    int q[105], head = 0, tail = 0;
    for (int v = 1; v <= n; v++) {
        if (adj[start][v]) { visited[v] = 1; q[tail++] = v; }
    }
    while (head < tail) {
        int u = q[head++];
        for (int v = 1; v <= n; v++) {
            if (adj[u][v] && !visited[v]) {
                visited[v] = 1;
                q[tail++] = v;
            }
        }
    }
    int cnt = 0;
    for (int v = 1; v <= n; v++) {
        if (!visited[v]) out_list[cnt++] = v;
    }
    return cnt;
}

int main(void) {

    int adj[105][105] = {0};
    adj[1][2] = adj[2][3] = 1;
    int unreach[10], cnt;
    cnt = solve_uva280_unreachable(3, adj, 1, unreach);
    int ok = (cnt == 1 && unreach[0] == 1);
    printf("%s: UVa 280 - Vertex\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
