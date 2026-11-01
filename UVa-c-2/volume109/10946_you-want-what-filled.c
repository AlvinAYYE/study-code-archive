/*
 * ==========================================================================
 * UVa 10946 - You want what filled?
 * Title-CN: 你想填滿什麼？
 * Difficulty: Easy
 * Tags: DFS, Flood Fill, Sorting
 * URL: https://onlinejudge.org/external/109/10946.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given a grid of characters, count the size of connected components for each non-'.' character and sort descending by size, then ascending by character.
 *
 * [中文] 題目概述:
 *     給定一個字元網格，計算每個非 '.' 字元的連通分量大小，並按大小降序、字元升序排序。
 *
 * [EN] Approach:
 *     Standard flood fill DFS on 4-neighbors for each unvisited non-'.' cell. Collect sizes and characters, then qsort.
 * [中文] 解題思路:
 *     對每個未訪問的非 '.' 網格點進行四方向 DFS 連通塊著色，統計大小與字元後排序。
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

int dfs_fill(char grid[10][10], int r, int c, int R, int C, char target) {
    if (r < 0 || r >= R || c < 0 || c >= C || grid[r][c] != target) return 0;
    grid[r][c] = '.';
    return 1 + dfs_fill(grid, r+1, c, R, C, target)
             + dfs_fill(grid, r-1, c, R, C, target)
             + dfs_fill(grid, r, c+1, R, C, target)
             + dfs_fill(grid, r, c-1, R, C, target);
}

int main(void) {

    char g[10][10] = {"AAA", "A..", "B.B"};
    int s1 = dfs_fill(g, 0, 0, 3, 3, 'A');
    int ok = (s1 == 4);
    printf("%s: UVa 10946 - You want what filled?\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
