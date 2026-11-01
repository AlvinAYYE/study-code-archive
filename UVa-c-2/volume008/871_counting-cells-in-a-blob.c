/*
 * ==========================================================================
 * UVa 871 - Counting Cells in a Blob
 * Title-CN: 計算斑點中的細胞數
 * Difficulty: Easy
 * Tags: DFS, Flood Fill
 * URL: https://onlinejudge.org/external/8/871.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the maximum size of an 8-connected component of '1's in a binary grid.
 *
 * [中文] 題目概述:
 *     求二進位網格中由 '1' 構成的 8 方向最大連通塊大小。
 *
 * [EN] Approach:
 *     Flood fill DFS in 8 directions from each unvisited '1'. Track maximum blob size.
 * [中文] 解題思路:
 *     對每個未訪問的 '1' 進行 8 方向 DFS 擴展著色，記錄最大斑點大小。
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

int dfs_blob(char grid[10][10], int r, int c, int R, int C) {
    if (r < 0 || r >= R || c < 0 || c >= C || grid[r][c] != '1') return 0;
    grid[r][c] = '0';
    int cnt = 1;
    for (int dr = -1; dr <= 1; dr++)
        for (int dc = -1; dc <= 1; dc++)
            if (dr || dc) cnt += dfs_blob(grid, r + dr, c + dc, R, C);
    return cnt;
}
int max_blob(char grid[10][10], int R, int C) {
    int mx = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (grid[i][j] == '1') {
                int s = dfs_blob(grid, i, j, R, C);
                if (s > mx) mx = s;
            }
        }
    }
    return mx;
}

int main(void) {

    char g[10][10] = {"110", "011", "000"};
    int ok = (max_blob(g, 3, 3) == 4);
    printf("%s: UVa 871 - Counting Cells in a Blob\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
