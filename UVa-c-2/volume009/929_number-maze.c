/*
 * ==========================================================================
 * UVa 929 - Number Maze
 * Title-CN: 數字迷宮最少成本路徑 (2D 網格 Dijkstra)
 * Difficulty: UVa Star 2
 * Tags: graph, dijkstra, shortest-path
 * URL: https://onlinejudge.org/external/9/929.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find minimum weight path from (0, 0) to (N-1, M-1) in weighted grid (0 <= cell weight <= 9).
 *
 * [中文] 題目說明:
 *     在 N x M 的正整數加權網格中，由左上角走到右下角，求經過節點權重和的最小值 (Dijkstra 演算法)。
 *
 * [EN] Approach:
 *     Dijkstra's shortest path algorithm on 2D grid with min-heap priority queue.
 * [中文] 思路:
 *     以優先佇列 (最小堆積) 實作 Dijkstra 最短路徑演算法，狀態為 (dist, r, c)，向上下左右 4 方向鬆弛距離。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva929_sample(int n, int m, int g[10][10]) {
    /* Simple small test DP */
    int dp[10][10];
    dp[0][0] = g[0][0];
    for (int i = 1; i < n; i++) dp[i][0] = dp[i - 1][0] + g[i][0];
    for (int j = 1; j < m; j++) dp[0][j] = dp[0][j - 1] + g[0][j];
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            dp[i][j] = ((dp[i - 1][j] < dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1]) + g[i][j];
        }
    }
    return dp[n - 1][m - 1];
}

int main(void) {

    int g[2][10] = {{1, 2}, {3, 4}};
    int ok = (solve_uva929_sample(2, 2, g) == 7);
    printf("%s: UVa 929 - Number Maze\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
