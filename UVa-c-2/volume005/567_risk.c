/*
 * ==========================================================================
 * UVa 567 - Risk
 * Title-CN: 戰國風雲 (BFS 最短路徑走訪)
 * Difficulty: UVa Star 1
 * Tags: graph, bfs, shortest-path
 * URL: https://onlinejudge.org/external/5/567.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given board graph of 20 countries, find minimum armies needed to move between country pairs (BFS shortest path).
 *
 * [中文] 題目說明:
 *     在 20 個國家的世界地圖圖形中，求從出發國至目的國所需經過的最少邊數 (BFS 最短路徑)。
 *
 * [EN] Approach:
 *     Breadth-First Search (BFS) or Floyd-Warshall across 20 nodes with unit edge weights.
 * [中文] 思路:
 *     因圖中頂點僅 20 個且邊權皆為 1，直接以 BFS 走訪或 Floyd-Warshall 預先算好所有點對最短距離。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva567_bfs(int adj[21][21], int deg[21], int s, int t) {
    int dist[21], vis[21] = {0};
    for (int i = 1; i <= 20; i++) dist[i] = -1;
    int q[25], head = 0, tail = 0;
    q[tail++] = s; dist[s] = 0; vis[s] = 1;
    while (head < tail) {
        int u = q[head++];
        if (u == t) return dist[t];
        for (int i = 0; i < deg[u]; i++) {
            int v = adj[u][i];
            if (!vis[v]) {
                vis[v] = 1;
                dist[v] = dist[u] + 1;
                q[tail++] = v;
            }
        }
    }
    return dist[t];
}

int main(void) {

    int adj[21][21] = {0}, deg[21] = {0};
    adj[1][0] = 2; deg[1] = 1;
    adj[2][0] = 1; adj[2][1] = 3; deg[2] = 2;
    adj[3][0] = 2; deg[3] = 1;
    int ok = (solve_uva567_bfs(adj, deg, 1, 3) == 2);
    printf("%s: UVa 567 - Risk\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
