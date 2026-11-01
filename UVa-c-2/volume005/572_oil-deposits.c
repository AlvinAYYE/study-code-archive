/*
 * ==========================================================================
 * UVa 572 - Oil Deposits
 * Title-CN: 油田連通塊數量
 * Difficulty: UVa Star 1
 * Tags: graph, dfs, flood-fill
 * ==========================================================================
 * [EN] Problem: Count connected components of oil pockets '@' in 8 directions.
 * [中文] 題目說明: 8 方向連通網格，計算油田 '@' 的連通塊數量。
 * [EN] Approach: DFS / BFS flood fill marking visited pockets.
 * [中文] 思路: 經典八方向 Flood Fill 遍歷計數。
 * ==========================================================================
 */
#include <stdio.h>

static void dfs(int r, int c, int m, int n, char grid[105][105]) {
    grid[r][c] = '*';
    for (int dr = -1; dr <= 1; dr++) {
        for (int dc = -1; dc <= 1; dc++) {
            int nr = r + dr, nc = c + dc;
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == '@') {
                dfs(nr, nc, m, n, grid);
            }
        }
    }
}

int solve_uva572(int m, int n, char grid[105][105]) {
    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '@') {
                count++;
                dfs(i, j, m, n, grid);
            }
        }
    }
    return count;
}

int main(void) {
    char g[105][105] = {
        "*@*",
        "***",
        "@*@"
    };
    int res = solve_uva572(3, 3, g);
    int ok = (res == 3);
    printf("%s: UVa 572 - Oil Deposits\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
