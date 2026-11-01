/*
 * ==========================================================================
 * UVa 627 - The Net
 * Title-CN: 網路最短路徑路由
 * Difficulty: Easy
 * Tags: Graph, BFS, Shortest Path
 * URL: https://onlinejudge.org/external/6/627.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the shortest routing path between routers in an unweighted communication network.
 *
 * [中文] 題目說明:
 *     在無權路由器通訊網路中尋找兩節點之間的最短路徑並輸出路徑節點序列。
 *
 * [EN] Approach:
 *     BFS to find shortest hop distance, tracking predecessor pointers to reconstruct path from destination back to source.
 * [中文] 思路:
 *     無權圖 BFS 遍歷求最短路，記錄父節點指標，由終點沿父節點回溯輸出路徑。
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

int route_net(int n, const int adj[20][20], int src, int dst, int *path) {
    int dist[20], parent[20];
    for (int i = 0; i < n; i++) { dist[i] = -1; parent[i] = -1; }
    dist[src] = 0;
    int q[20], head = 0, tail = 0;
    q[tail++] = src;
    while (head < tail) {
        int u = q[head++];
        if (u == dst) break;
        for (int v = 0; v < n; v++) {
            if (adj[u][v] && dist[v] == -1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q[tail++] = v;
            }
        }
    }
    if (dist[dst] == -1) return 0;
    int len = 0, cur = dst;
    int rev[20];
    while (cur != -1) {
        rev[len++] = cur;
        cur = parent[cur];
    }
    for (int i = 0; i < len; i++) path[i] = rev[len - 1 - i];
    return len;
}

int main(void) {

    int adj[20][20] = {0};
    adj[0][1] = adj[1][2] = 1;
    int p[5];
    int len = route_net(3, adj, 0, 2, p);
    int ok = (len == 3 && p[0] == 0 && p[1] == 1 && p[2] == 2);
    printf("%s: UVa 627 - The Net\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
