/*
 * ==========================================================================
 * UVa 10285 - Longest Run on a Snowboard
 * Title-CN: 滑雪板最長滑行路徑記憶化搜尋
 * Difficulty: UVa Star 2
 * Tags: dynamic-programming, dfs
 * URL: https://onlinejudge.org/external/102/10285.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the length of the longest strictly descending path in an R x C elevation grid.
 *
 * [中文] 題目說明:
 *     在 R x C 的高度網格地圖中，求只能向四相鄰且高度嚴格較低處滑行時的最長滑行路徑長度。
 *
 * [EN] Approach:
 *     DFS with memoization (DAG longest path): memo[r][c] = 1 + max(dfs(nr, nc)) for neighbors with lower elevation.
 * [中文] 思路:
 *     記憶化深度優先搜尋 (有向無環圖最長路)：memo[r][c] 記錄該點出發最長路，向四鄰居高度較低者遞推取最大值。
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

int dfs_snow(int r, int c, int R, int C, int grid[20][20], int memo[20][20]) {
    if (memo[r][c] != 0) return memo[r][c];
    int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
    int max_len = 1;
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i], nc = c + dc[i];
        if (nr >= 0 && nr < R && nc >= 0 && nc < C && grid[nr][nc] < grid[r][c]) {
            int sub = 1 + dfs_snow(nr, nc, R, C, grid, memo);
            if (sub > max_len) max_len = sub;
        }
    }
    return memo[r][c] = max_len;
}

int solve_uva10285(int R, int C, int grid[20][20]) {
    int memo[20][20] = {0};
    int overall = 0;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            int cur = dfs_snow(r, c, R, C, grid, memo);
            if (cur > overall) overall = cur;
        }
    }
    return overall;
}

int main(void) {

    int g[20][20] = {{5, 4}, {1, 2}}; // 5 -> 4 -> 2 -> 1 (len 4)
    int len = solve_uva10285(2, 2, g);
    int ok = (len == 4);
    printf("%s: UVa 10285 - Longest Run on a Snowboard\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
