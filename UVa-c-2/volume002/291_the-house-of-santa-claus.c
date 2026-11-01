/*
 * ==========================================================================
 * UVa 291 - The House Of Santa Claus
 * Title-CN: 聖誕老人之屋 (歐拉一筆畫全路徑枚舉)
 * Difficulty: UVa Star 1
 * Tags: graph, eulerian-path, backtracking
 * URL: https://onlinejudge.org/external/2/291.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Print all 1-stroke drawing paths of Santa Claus House starting from vertex 1 traversing all 8 edges in numerical order.
 *
 * [中文] 題目說明:
 *     由頂點 1 出發，以一筆畫走遍聖誕老人之屋的 8 條邊，輸出所有合法的歐拉路徑編號。
 *
 * [EN] Approach:
 *     Backtracking DFS with edge-visited marks. 8 steps complete a valid Eulerian trail.
 * [中文] 思路:
 *     回溯搜尋：以陣列標記無向邊是否已走過，遞迴深度達到 8 步即為合法路徑，由小到大枚舉頂點自動保證字典序。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

static int count_291;
static int g_291[6][6];
static int path_291[10];

void dfs_291(int u, int step) {
    path_291[step] = u;
    if (step == 8) { count_291++; return; }
    for (int v = 1; v <= 5; v++) {
        if (g_291[u][v]) {
            g_291[u][v] = g_291[v][u] = 0;
            dfs_291(v, step + 1);
            g_291[u][v] = g_291[v][u] = 1;
        }
    }
}

int solve_uva291(void) {
    count_291 = 0;
    int edges[8][2] = {{1,2},{1,3},{1,5},{2,3},{2,5},{3,4},{3,5},{4,5}};
    for (int i = 1; i <= 5; i++) for (int j = 1; j <= 5; j++) g_291[i][j] = 0;
    for (int i = 0; i < 8; i++) g_291[edges[i][0]][edges[i][1]] = g_291[edges[i][1]][edges[i][0]] = 1;
    dfs_291(1, 0);
    return count_291;
}

int main(void) {

    int ok = (solve_uva291() == 44);
    printf("%s: UVa 291 - The House Of Santa Claus\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
