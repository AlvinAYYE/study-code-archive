/*
 * ==========================================================================
 * UVa 383 - Shipping Routes
 * Title-CN: 貨物航線
 * Difficulty: Easy
 * Tags: Graph, BFS, Shortest Path
 * URL: https://onlinejudge.org/external/3/383.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given a network of warehouse shipping legs, find the shortest path in legs between source and destination and calculate cost ($100 * size * legs).
 *
 * [中文] 題目說明:
 *     給定倉庫間的航線網絡，求起點到終點的最短航線段數，並計算運輸成本（$100 * 貨物大小 * 段數）。
 *
 * [EN] Approach:
 *     Standard unweighted BFS to find the shortest hop distance between two warehouse nodes.
 * [中文] 思路:
 *     無權圖 BFS 最短路徑搜尋兩節點間的最少段數，若連通則費用為 legs * size * 100。
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

int shipping_cost(int n, const int adj[20][20], int src, int dst, int size) {
    if (src == dst) return 0;
    int dist[20];
    for (int i = 0; i < n; i++) dist[i] = -1;
    dist[src] = 0;
    int q[20], head = 0, tail = 0;
    q[tail++] = src;
    while (head < tail) {
        int u = q[head++];
        if (u == dst) return dist[u] * size * 100;
        for (int v = 0; v < n; v++) {
            if (adj[u][v] && dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q[tail++] = v;
            }
        }
    }
    return -1; // no route
}

int main(void) {

    int adj[20][20] = {0};
    adj[0][1] = adj[1][0] = 1;
    adj[1][2] = adj[2][1] = 1;
    int cost = shipping_cost(3, adj, 0, 2, 5);
    int ok = (cost == 1000); // 2 legs * 5 * 100
    printf("%s: UVa 383 - Shipping Routes\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
