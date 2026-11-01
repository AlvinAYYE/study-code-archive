/*
 * ==========================================================================
 * UVa 116 - Unidirectional TSP
 * Title-CN: 單向旅行商問題 (循環網格 DP)
 * Difficulty: UVa Star 2
 * Tags: dynamic-programming, grid, lexicographical
 * URL: https://onlinejudge.org/external/1/116.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find path from column 1 to n in a cylindrical grid with minimum weight and lexicographically smallest row sequence.
 *
 * [中文] 題目說明:
 *     在上下相通的圓柱網格中，由左至右移動，求累加權重最小且字典序最小的列移動路徑。
 *
 * [EN] Approach:
 *     Dynamic programming from right to left (col n-1 down to 0). Sort candidate next rows for lexicographical tie-breaking.
 * [中文] 思路:
 *     從最後一列反向向左動態規劃：dp[r][c] 代表從 (r,c) 走到終點的最小成本。遇到相同最小值時優先選列號小者。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void solve_uva116(int m, int n, int grid[10][100], int *out_min, int *out_path) {
    long long dp[10][100];
    int nxt[10][100];
    for (int r = 0; r < m; r++) dp[r][n - 1] = grid[r][n - 1];
    for (int c = n - 2; c >= 0; c--) {
        for (int r = 0; r < m; r++) {
            int cand[3] = {(r - 1 + m) % m, r, (r + 1) % m};
            for (int i = 0; i < 2; i++) {
                for (int j = i + 1; j < 3; j++) {
                    if (cand[i] > cand[j]) { int t = cand[i]; cand[i] = cand[j]; cand[j] = t; }
                }
            }
            long long best = dp[cand[0]][c + 1];
            int best_r = cand[0];
            for (int k = 1; k < 3; k++) {
                if (dp[cand[k]][c + 1] < best) {
                    best = dp[cand[k]][c + 1];
                    best_r = cand[k];
                }
            }
            dp[r][c] = grid[r][c] + best;
            nxt[r][c] = best_r;
        }
    }
    long long min_cost = dp[0][0];
    int start_r = 0;
    for (int r = 1; r < m; r++) {
        if (dp[r][0] < min_cost) { min_cost = dp[r][0]; start_r = r; }
    }
    *out_min = (int)min_cost;
    int cur = start_r;
    for (int c = 0; c < n; c++) {
        out_path[c] = cur + 1;
        cur = nxt[cur][c];
    }
}

int main(void) {

    int g[3][100] = {{3, 4, 1, 2}, {6, 1, 8, 2}, {2, 8, 9, 5}};
    int min_c, path[4];
    solve_uva116(3, 4, g, &min_c, &path[0]);
    int ok = (min_c == 6 && path[0] == 3);
    printf("%s: UVa 116 - Unidirectional TSP\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
