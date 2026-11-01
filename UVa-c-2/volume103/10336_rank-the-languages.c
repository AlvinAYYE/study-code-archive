/*
 * ==========================================================================
 * UVa 10336 - Rank the Languages
 * Title-CN: 語言地圖連通分量區域排名
 * Difficulty: UVa Star 2
 * Tags: graph, flood-fill, dfs
 * URL: https://onlinejudge.org/external/103/10336.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given a grid of language characters, count connected states for each language using 4-way flood fill and rank by count.
 *
 * [中文] 題目說明:
 *     給定二維語言字元網格，以四方向漫水填充 (Flood Fill) 統計各語言連通領土數量，並依數量由大到小排序。
 *
 * [EN] Approach:
 *     Scan grid: upon seeing an unvisited cell, launch DFS/BFS to mark entire connected component, and increment count for that letter.
 * [中文] 思路:
 *     逐格掃描網格，遇未走訪格子啟動 DFS 染整塊連通分量並將該字元計數加一，最後依出現次數降序、字母序升序排序。
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

void dfs_10336(int r, int c, int h, int w, char g[20][20], int vis[20][20], char target) {
    if (r < 0 || r >= h || c < 0 || c >= w || vis[r][c] || g[r][c] != target) return;
    vis[r][c] = 1;
    dfs_10336(r + 1, c, h, w, g, vis, target);
    dfs_10336(r - 1, c, h, w, g, vis, target);
    dfs_10336(r, c + 1, h, w, g, vis, target);
    dfs_10336(r, c - 1, h, w, g, vis, target);
}

void solve_uva10336(int h, int w, char g[20][20], int counts[26]) {
    memset(counts, 0, 26 * sizeof(int));
    int vis[20][20] = {0};
    for (int r = 0; r < h; r++) {
        for (int c = 0; c < w; c++) {
            if (!vis[r][c]) {
                counts[g[r][c] - 'a']++;
                dfs_10336(r, c, h, w, g, vis, g[r][c]);
            }
        }
    }
}

int main(void) {

    char g[20][20] = {"tt", "tt"};
    int c[26];
    solve_uva10336(2, 2, g, c);
    int ok = (c['t' - 'a'] == 1);
    printf("%s: UVa 10336 - Rank the Languages\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
