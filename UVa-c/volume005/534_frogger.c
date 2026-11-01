/*
 * ==========================================================================
 * UVa 534 - Frogger
 * Title-CN: 青蛙跳石 (最小化最大跳躍距離 Minimax)
 * Difficulty: UVa Star 2
 * Tags: graph, shortest-path, floyd-warshall, mst
 * URL: https://onlinejudge.org/external/5/534.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find path between stone 1 and 2 that minimizes the maximum single jump distance (frog distance).
 *
 * [中文] 題目說明:
 *     青蛙從 1 號石頭跳至 2 號石頭，求所有可能路徑中「單次最大跳躍跨度」的最小值 (Minimax 路徑)。
 *
 * [EN] Approach:
 *     Floyd-Warshall minimax variant: dist[i][j] = min(dist[i][j], max(dist[i][k], dist[k][j])).
 * [中文] 思路:
 *     Floyd-Warshall 變形：距離鬆弛定義為 dist[i][j] = min(dist[i][j], max(dist[i][k], dist[k][j]))，初值為歐式距離。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <math.h>

double solve_uva534(int n, const double x[], const double y[]) {
    double d[105][105];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double dx = x[i] - x[j], dy = y[i] - y[j];
            d[i][j] = sqrt(dx * dx + dy * dy);
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                double m = (d[i][k] > d[k][j]) ? d[i][k] : d[k][j];
                if (m < d[i][j]) d[i][j] = m;
            }
        }
    }
    return d[0][1];
}

int main(void) {

    double x[3] = {0, 0, 0};
    double y[3] = {0, 2, 1};
    double res = solve_uva534(3, x, y);
    int ok = (fabs(res - 1.0) < 1e-4);
    printf("%s: UVa 534 - Frogger\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
