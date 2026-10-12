/*
 * ==========================================================================
 * UVa 10048 - Audiophobia
 * Title-CN: 恐音症
 * Difficulty: UVa Star 2
 * Tags: graph, shortest-path, floyd-warshall
 * URL: https://onlinejudge.org/external/100/10048.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find a path between two nodes that minimizes the maximum sound level (edge weight) encountered.
 *
 * [中文] 題目說明:
 *     求從點 u 到點 v 的路徑中，最大邊權最小化的值（最小化最大瓶頸）。
 *
 * [EN] Approach:
 *     Modified Floyd-Warshall algorithm: d[i][j] = min(d[i][j], max(d[i][k], d[k][j])).
 * [中文] 思路:
 *     修改版 Floyd-Warshall 演算法求 Minimax 路徑。
 * ==========================================================================
 */
#include <stdio.h>

#define INF 1000000000

static inline int max_val(int a, int b) { return a > b ? a : b; }
static inline int min_val(int a, int b) { return a < b ? a : b; }

int solve_uva10048(int c, int d[105][105], int start, int end) {
    for (int k = 1; k <= c; k++) {
        for (int i = 1; i <= c; i++) {
            for (int j = 1; j <= c; j++) {
                int bottleneck = max_val(d[i][k], d[k][j]);
                d[i][j] = min_val(d[i][j], bottleneck);
            }
        }
    }
    return (d[start][end] >= INF) ? -1 : d[start][end];
}

int main(void) {
    int d[105][105];
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) d[i][j] = (i == j ? 0 : INF);
    }
    d[1][2] = d[2][1] = 50;
    d[2][3] = d[3][2] = 60;
    d[1][3] = d[3][1] = 90;
    int res = solve_uva10048(3, d, 1, 3);
    int ok = (res == 60); /* 1->2->3 bottleneck is max(50, 60)=60 < 90 */
    printf("%s: UVa 10048 - Audiophobia\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
