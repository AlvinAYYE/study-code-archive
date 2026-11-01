/*
 * ==========================================================================
 * UVa 796 - Critical Links
 * Title-CN: 網路關鍵鏈路橋樑偵測
 * Difficulty: UVa Star 2
 * Tags: graph, tarjan, bridge
 * URL: https://onlinejudge.org/external/7/796.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given an undirected server network, find all critical links (bridges) whose removal disconnects the graph.
 *
 * [中文] 題目說明:
 *     給定無向伺服器通訊網路，求出所有斷開後會使圖不再連通的關鍵鏈路 (橋樑，Bridges)。
 *
 * [EN] Approach:
 *     Tarjan's bridge-finding algorithm using DFS discovery times (tin) and lowest reachable times (low). An edge (u, v) is a bridge if low[v] > tin[u].
 * [中文] 思路:
 *     使用 Tarjan DFS 走訪演算法：維護發現時間 tin 與回溯最低時間 low，若 low[v] > tin[u] 則無向邊 (u, v) 為橋樑。
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

int tin_796[20], low_796[20], timer_796;
int bridge_cnt_796;

void dfs_bridge(int u, int p, int n, int adj[20][20]) {
    tin_796[u] = low_796[u] = ++timer_796;
    for (int v = 0; v < n; v++) {
        if (adj[u][v]) {
            if (v == p) continue;
            if (tin_796[v]) {
                if (tin_796[v] < low_796[u]) low_796[u] = tin_796[v];
            } else {
                dfs_bridge(v, u, n, adj);
                if (low_796[v] < low_796[u]) low_796[u] = low_796[v];
                if (low_796[v] > tin_796[u]) bridge_cnt_796++;
            }
        }
    }
}

int solve_uva796(int n, int adj[20][20]) {
    timer_796 = 0; bridge_cnt_796 = 0;
    for (int i = 0; i < n; i++) tin_796[i] = 0;
    for (int i = 0; i < n; i++) {
        if (!tin_796[i]) dfs_bridge(i, -1, n, adj);
    }
    return bridge_cnt_796;
}

int main(void) {

    int adj[20][20] = {0};
    adj[0][1] = adj[1][0] = 1; // single edge between 0 and 1 -> 1 bridge
    int b = solve_uva796(2, adj);
    int ok = (b == 1);
    printf("%s: UVa 796 - Critical Links\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
