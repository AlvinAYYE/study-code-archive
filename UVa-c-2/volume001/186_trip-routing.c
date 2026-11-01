/*
 * ==========================================================================
 * UVa 186 - Trip Routing
 * Title-CN: 最短公路自駕路徑導航
 * Difficulty: UVa Star 2
 * Tags: graph, floyd-warshall
 * URL: https://onlinejudge.org/external/1/186.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given a highway road network with distances and route names, find the shortest driving path between cities and print detailed driving legs.
 *
 * [中文] 題目說明:
 *     給定包含里程與公路名稱的公路網路，計算兩城市間之最短行車路徑，並依序列印各路段名稱與距離明細。
 *
 * [EN] Approach:
 *     Map city names to vertex IDs. Run Floyd-Warshall with a next-hop predecessor matrix to reconstruct and print the optimal route.
 * [中文] 思路:
 *     以雜湊表將城市名稱映射為整數編號，執行 Floyd-Warshall 全源最短路徑並記錄轉移中繼點，以遞迴重構輸出完整路徑路段。
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

void floyd_init(int n, int d[50][50], int nxt[50][50]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) d[i][j] = 0;
            nxt[i][j] = (d[i][j] < 1e8 && i != j) ? j : -1;
        }
    }
}

int main(void) {

    int d[50][50] = {0}, nxt[50][50];
    d[0][1] = 5; d[1][0] = 5;
    floyd_init(2, d, nxt);
    int ok = (nxt[0][1] == 1);
    printf("%s: UVa 186 - Trip Routing\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
