/*
 * ==========================================================================
 * UVa 125 - Numbering Paths
 * Title-CN: 有向圖路徑計數與環路判定
 * Difficulty: UVa Star 2
 * Tags: graph, floyd-warshall
 * URL: https://onlinejudge.org/external/1/125.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given directed street network, find the number of paths between all pairs of intersections, or -1 if infinitely many paths exist (via cycle).
 *
 * [中文] 題目說明:
 *     給定有向街道網路，計算所有交會點對之間的路徑數量；若兩點間存在有向環導致有無窮多條路徑，則標記為 -1。
 *
 * [EN] Approach:
 *     Modified Floyd-Warshall: path count matrix dp[i][j] += dp[i][k] * dp[k][j]. Nodes k with dp[k][k] > 0 are on a cycle, setting affected paths to -1.
 * [中文] 思路:
 *     變形 Floyd-Warshall：更新路徑數 dp[i][j] += dp[i][k]*dp[k][j]。若發現 dp[k][k] > 0 則節點 k 在環上，所有可達該環且由該環可達的 (i, j) 均標記為 -1。
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

void solve_uva125(int n, int adj[30][30], int paths[30][30]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            paths[i][j] = adj[i][j];

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                paths[i][j] += paths[i][k] * paths[k][j];

    for (int k = 0; k < n; k++) {
        if (paths[k][k] > 0) {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (paths[i][k] != 0 && paths[k][j] != 0)
                        paths[i][j] = -1;
        }
    }
}

int main(void) {

    int adj[30][30] = {0};
    adj[0][1] = 1; adj[1][2] = 1; adj[0][2] = 1;
    int paths[30][30];
    solve_uva125(3, adj, paths);
    int ok = (paths[0][2] == 2 && paths[0][1] == 1);
    printf("%s: UVa 125 - Numbering Paths\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
