/*
 * ==========================================================================
 * UVa 821 - Page Hopping
 * Title-CN: 網頁點擊跳躍平均距離
 * Difficulty: UVa Star 2
 * Tags: graph, floyd-warshall, shortest-path
 * URL: https://onlinejudge.org/external/8/821.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find average shortest path length between all pairs of reachable pages.
 *
 * [中文] 題目說明:
 *     計算網路中所有相異可達網頁節點對之間的最短路徑長度平均值 (Floyd-Warshall 全點對最短路)。
 *
 * [EN] Approach:
 *     Floyd-Warshall algorithm on up to 100 nodes. Sum all dist[i][j] where i != j and divide by total pairs.
 * [中文] 思路:
 *     對最多 100 個網頁節點執行 Floyd-Warshall 演算法，累加所有 i != j 的最短距離除以有效點對數。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double solve_uva821(int n, int d[105][105], int present[105]) {
    for (int k = 1; k <= 100; k++) {
        if (!present[k]) continue;
        for (int i = 1; i <= 100; i++) {
            if (!present[i]) continue;
            for (int j = 1; j <= 100; j++) {
                if (!present[j]) continue;
                if (d[i][k] + d[k][j] < d[i][j]) d[i][j] = d[i][k] + d[k][j];
            }
        }
    }
    int sum = 0, pairs = 0;
    for (int i = 1; i <= 100; i++) {
        if (!present[i]) continue;
        for (int j = 1; j <= 100; j++) {
            if (!present[j] || i == j) continue;
            sum += d[i][j];
            pairs++;
        }
    }
    return pairs ? ((double)sum / pairs) : 0.0;
}

int main(void) {

    int d[105][105], p[105] = {0};
    for (int i = 1; i <= 100; i++) for (int j = 1; j <= 100; j++) d[i][j] = (i == j) ? 0 : 1000;
    p[1] = p[2] = 1; d[1][2] = 1; d[2][1] = 1;
    double avg = solve_uva821(2, d, p);
    int ok = (fabs(avg - 1.0) < 1e-4);
    printf("%s: UVa 821 - Page Hopping\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
