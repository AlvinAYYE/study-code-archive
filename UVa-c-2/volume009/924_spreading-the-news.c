/*
 * ==========================================================================
 * UVa 924 - Spreading The News
 * Title-CN: 傳播八卦消息 (BFS 單日最大傳播人數)
 * Difficulty: UVa Star 1
 * Tags: graph, bfs
 * URL: https://onlinejudge.org/external/9/924.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the day on which the maximum number of people hear the news (BFS distance frequency) and that max count.
 *
 * [中文] 題目說明:
 *     在社交好友網路中從某人開始傳遞消息，求消息傳播人數達到峰值的單日天數與最大傳播人數 (BFS 深度頻率統計)。
 *
 * [EN] Approach:
 *     Breadth-First Search (BFS) tracking distance from source. Tally frequency of each distance d > 0, find maximum.
 * [中文] 思路:
 *     標準 BFS 走訪圖形，記錄每個節點到起點的最短距離 (天數)。統計每一天的造訪人數，取最大值與最早發生天數。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void solve_uva924(int n, int adj[100][100], int deg[100], int src, int *max_boom, int *first_day) {
    int dist[100], vis[100] = {0};
    for (int i = 0; i < n; i++) dist[i] = -1;
    int q[100], head = 0, tail = 0;
    q[tail++] = src; dist[src] = 0; vis[src] = 1;
    int count[100] = {0};
    while (head < tail) {
        int u = q[head++];
        for (int i = 0; i < deg[u]; i++) {
            int v = adj[u][i];
            if (!vis[v]) {
                vis[v] = 1;
                dist[v] = dist[u] + 1;
                count[dist[v]]++;
                q[tail++] = v;
            }
        }
    }
    *max_boom = 0; *first_day = 0;
    for (int d = 1; d < n; d++) {
        if (count[d] > *max_boom) {
            *max_boom = count[d];
            *first_day = d;
        }
    }
}

int main(void) {

    int adj[5][100] = {0}, deg[5] = {0};
    deg[0] = 2; adj[0][0] = 1; adj[0][1] = 2;
    int mb, fd;
    solve_uva924(3, adj, deg, 0, &mb, &fd);
    int ok = (mb == 2 && fd == 1);
    printf("%s: UVa 924 - Spreading The News\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
