/*
 * ==========================================================================
 * UVa 352 - The Seasonal War
 * Title-CN: 季節戰爭 (八方向連通鷹眼連通塊)
 * Difficulty: UVa Star 1
 * Tags: graph, flood-fill, dfs
 * URL: https://onlinejudge.org/external/3/352.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count number of war eagles (connected components of 1s in 8 directions) in n x n binary image.
 *
 * [中文] 題目說明:
 *     在 n x n 的二值圖像中，計算 8 方向連通的作戰鷹群 (數值 1 形成的連通塊) 總數量。
 *
 * [EN] Approach:
 *     Flood fill (DFS or BFS) in 8 directions. Mark visited pixels and count initiated traversals.
 * [中文] 思路:
 *     對地圖進行 8 方向深度優先搜尋 (DFS)，將已造訪的 '1' 淹沒標記，統計連通塊總數。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

static void dfs_352(int r, int c, int n, char g[30][30]) {
    g[r][c] = '0';
    for (int dr = -1; dr <= 1; dr++) {
        for (int dc = -1; dc <= 1; dc++) {
            int nr = r + dr, nc = c + dc;
            if (nr >= 0 && nr < n && nc >= 0 && nc < n && g[nr][nc] == '1') {
                dfs_352(nr, nc, n, g);
            }
        }
    }
}

int solve_uva352(int n, char g[30][30]) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (g[i][j] == '1') {
                cnt++;
                dfs_352(i, j, n, g);
            }
        }
    }
    return cnt;
}

int main(void) {

    char g[3][30] = {"100", "010", "000"};
    int ok = (solve_uva352(3, g) == 1);
    printf("%s: UVa 352 - The Seasonal War\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
