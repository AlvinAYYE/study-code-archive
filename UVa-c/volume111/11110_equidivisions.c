/*
 * ==========================================================================
 * UVa 11110 - Equidivisions
 * Title-CN: 等分網格連通性檢測
 * Difficulty: Easy
 * Tags: DFS, Flood Fill, Grid
 * URL: https://onlinejudge.org/external/111/11110.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine if an n x n grid is partitioned into n connected regions of size n each.
 *
 * [中文] 題目說明:
 *     判定 n x n 的網格是否剛好被劃分為 n 個連通區域，且每個區域的格子數恰好均為 n。
 *
 * [EN] Approach:
 *     Run flood fill DFS for each region label 1..n. Check that each region is a single connected component of size exactly n.
 * [中文] 思路:
 *     對每個區域編號 1..n 進行 DFS 洪水填充連通塊檢測，驗證每個區域均單一連通且大小剛好為 n。
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

int dfs_region(int r, int c, int n, int label, int grid[10][10], bool vis[10][10]) {
    if (r < 0 || r >= n || c < 0 || c >= n || vis[r][c] || grid[r][c] != label) return 0;
    vis[r][c] = true;
    return 1 + dfs_region(r + 1, c, n, label, grid, vis)
             + dfs_region(r - 1, c, n, label, grid, vis)
             + dfs_region(r, c + 1, n, label, grid, vis)
             + dfs_region(r, c - 1, n, label, grid, vis);
}
bool is_equidivision(int n, int grid[10][10]) {
    bool vis[10][10] = {false};
    for (int label = 1; label <= n; label++) {
        int found = 0;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (!vis[r][c] && grid[r][c] == label) {
                    found++;
                    if (found > 1) return false;
                    int sz = dfs_region(r, c, n, label, grid, vis);
                    if (sz != n) return false;
                }
            }
        }
        if (found == 0) return false;
    }
    return true;
}

int main(void) {

    int g[10][10] = {{1, 1}, {2, 2}};
    int ok = is_equidivision(2, g);
    printf("%s: UVa 11110 - Equidivisions\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
