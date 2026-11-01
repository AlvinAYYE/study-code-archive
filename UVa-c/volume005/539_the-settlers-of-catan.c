/*
 * ==========================================================================
 * UVa 539 - The Settlers of Catan
 * Title-CN: 卡坦島開拓者 (圖中最長無重複邊簡單路徑)
 * Difficulty: UVa Star 1
 * Tags: graph, dfs, backtracking
 * URL: https://onlinejudge.org/external/5/539.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the length of the longest path in an undirected graph such that no edge is traversed more than once.
 *
 * [中文] 題目說明:
 *     在無向圖中尋找一條最長路徑，要求每條邊最多只能經過一次 (節點可重複造訪)，求最大路徑長度。
 *
 * [EN] Approach:
 *     DFS backtracking from each vertex. Mark traversed edges as visited, explore unvisited adjacent edges, take maximum depth.
 * [中文] 思路:
 *     從圖中每個節點分別進行深度優先搜尋 (DFS)，遞迴走訪未造訪的邊並標記已用，搜尋結束後回溯，取最大走訪邊數。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

static int g_539[30][30];
static int max_len_539;

void dfs_539(int u, int len, int n) {
    if (len > max_len_539) max_len_539 = len;
    for (int v = 0; v < n; v++) {
        if (g_539[u][v]) {
            g_539[u][v] = g_539[v][u] = 0;
            dfs_539(v, len + 1, n);
            g_539[u][v] = g_539[v][u] = 1;
        }
    }
}

int solve_uva539(int n, int m, int edges[][2]) {
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) g_539[i][j] = 0;
    for (int i = 0; i < m; i++) {
        g_539[edges[i][0]][edges[i][1]] = g_539[edges[i][1]][edges[i][0]] = 1;
    }
    max_len_539 = 0;
    for (int i = 0; i < n; i++) dfs_539(i, 0, n);
    return max_len_539;
}

int main(void) {

    int e[3][2] = {{0, 1}, {1, 2}, {2, 0}};
    int ok = (solve_uva539(3, 3, e) == 3);
    printf("%s: UVa 539 - The Settlers of Catan\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
