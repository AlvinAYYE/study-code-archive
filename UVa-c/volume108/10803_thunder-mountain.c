/*
 * ==========================================================================
 * UVa 10803 - Thunder Mountain
 * Title-CN: 雷霆山 (全源最短路徑最大連通距離)
 * Difficulty: Medium
 * Tags: Graph, Floyd-Warshall
 * URL: https://onlinejudge.org/external/108/10803.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Towns within 10 units of distance can communicate directly. Find the maximum travel distance between any two connected towns, or report 'Send earlier teams!' if disconnected.
 *
 * [中文] 題目說明:
 *     相距不超過 10 單位距離的城鎮可直接連通，求任意兩城鎮間最短路徑的最大值；若全圖不連通則輸出警告。
 *
 * [EN] Approach:
 *     Floyd-Warshall on Euclidean distances <= 10. Maximize dist[i][j] over all pairs. If any dist is infinity, report disconnected.
 * [中文] 思路:
 *     對距離 <= 10 的點對連邊，執行 Floyd-Warshall 求全源最短路徑，取全圖最大距離；若有不可達點對則判定為不連通。
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

double thunder_mountain_max(int n, const double pts[][2]) {
    double dist[20][20];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) { dist[i][j] = 0.0; continue; }
            double dx = pts[i][0] - pts[j][0], dy = pts[i][1] - pts[j][1];
            double d = sqrt(dx * dx + dy * dy);
            dist[i][j] = (d <= 10.0 ? d : 1e9);
        }
    }
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
    double max_d = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (dist[i][j] > 1e8) return -1.0; // disconnected
            if (dist[i][j] > max_d) max_d = dist[i][j];
        }
    return max_d;
}

int main(void) {

    double pts[2][2] = {{0, 0}, {0, 8}};
    double d = thunder_mountain_max(2, pts);
    int ok = (fabs(d - 8.0) < 1e-4);
    printf("%s: UVa 10803 - Thunder Mountain\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
