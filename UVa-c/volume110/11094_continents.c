/*
 * ==========================================================================
 * UVa 11094 - Continents
 * Title-CN: 大陸板塊圓柱網格最大未佔領土地面積
 * Difficulty: UVa Star 2
 * Tags: graph, flood-fill
 * URL: https://onlinejudge.org/external/110/11094.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the maximum size of a continent (connected land cells) on a cylindrical globe, excluding the continent where the king currently resides.
 *
 * [中文] 題目說明:
 *     在圓柱形東西相接的地球網格上，以漫水填充求出國王所在板塊以外之最大未佔領大陸面積。
 *
 * [EN] Approach:
 *     Flood fill to erase king's continent. Then flood fill remaining land components, taking maximum size with cylindrical column wrapping (c = (c + C) % C).
 * [中文] 思路:
 *     首先將國王所在的大陸以 DFS 標記清除，再對其餘陸地進行漫水填充，水平行座標以取模實現東西邊界相接環形走訪。
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

int dfs_continent(int r, int c, int R, int C, char g[20][25], char land) {
    if (r < 0 || r >= R || g[r][c] != land) return 0;
    g[r][c] = land == 'l' ? 'w' : 'l'; // flip
    int sz = 1;
    sz += dfs_continent(r + 1, c, R, C, g, land);
    sz += dfs_continent(r - 1, c, R, C, g, land);
    sz += dfs_continent(r, (c + 1) % C, R, C, g, land);
    sz += dfs_continent(r, (c - 1 + C) % C, R, C, g, land);
    return sz;
}

int solve_uva11094(int R, int C, char g[20][25], int kr, int kc) {
    char land = g[kr][kc];
    dfs_continent(kr, kc, R, C, g, land); // remove king continent
    int max_sz = 0;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (g[r][c] == land) {
                int sz = dfs_continent(r, c, R, C, g, land);
                if (sz > max_sz) max_sz = sz;
            }
        }
    }
    return max_sz;
}

int main(void) {

    char g[20][25] = {"llw", "www", "wlw"};
    int max_c = solve_uva11094(3, 3, g, 0, 0);
    int ok = (max_c == 1); // lone land at (2, 1)
    printf("%s: UVa 11094 - Continents\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
