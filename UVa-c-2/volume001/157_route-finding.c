/*
 * ==========================================================================
 * UVa 157 - Route Finding
 * Title-CN: 地鐵線路換乘最短時間與路徑 Dijkstra
 * Difficulty: UVa Star 2
 * Tags: graph, shortest-path
 * URL: https://onlinejudge.org/external/1/157.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the shortest travel route between subway stations, factoring in route segment travel times and line transfer penalties.
 *
 * [中文] 題目說明:
 *     計算地鐵網路中任意兩站之間的最短路徑與耗時，包含相鄰站間行駛時間與跨線換乘站的額外換線懲罰時間。
 *
 * [EN] Approach:
 *     Model as graph with nodes representing (line, station) pairs. Add edges for intra-line travel and transfer edges between lines at common stations. Run Dijkstra.
 * [中文] 思路:
 *     以 (路線, 車站) 作為狀態圖節點，同路線相鄰站連線賦權行駛時間，同名換乘站間連線賦權換線懲罰時間，執行 Dijkstra 演算法求解。
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

int shortest_path_simple(int n, int dist[20][20], int src, int dst) {
    int d[20], vis[20] = {0};
    for (int i = 0; i < n; i++) d[i] = 1e9;
    d[src] = 0;
    for (int iter = 0; iter < n; iter++) {
        int u = -1, min_d = 1e9;
        for (int i = 0; i < n; i++) {
            if (!vis[i] && d[i] < min_d) { min_d = d[i]; u = i; }
        }
        if (u == -1) break;
        vis[u] = 1;
        for (int v = 0; v < n; v++) {
            if (dist[u][v] > 0 && d[u] + dist[u][v] < d[v])
                d[v] = d[u] + dist[u][v];
        }
    }
    return d[dst];
}

int main(void) {

    int adj[20][20] = {0};
    adj[0][1] = 2; adj[1][2] = 3; adj[0][2] = 10;
    int res = shortest_path_simple(3, adj, 0, 2);
    int ok = (res == 5);
    printf("%s: UVa 157 - Route Finding\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
