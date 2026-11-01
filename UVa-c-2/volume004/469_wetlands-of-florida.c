/*
 * ==========================================================================
 * UVa 469 - Wetlands of Florida
 * Title-CN: 佛羅里達濕地漫水填充水域面積
 * Difficulty: UVa Star 2
 * Tags: graph, flood-fill
 * URL: https://onlinejudge.org/external/4/469.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given a grid of 'W' (water) and 'L' (land), answer queries asking for the area of the 8-connected water component containing (r, c).
 *
 * [中文] 題目說明:
 *     給定由水域 'W' 與陸地 'L' 組成的網格，查詢包含指定座標 (r, c) 的八方向連通水域總面積。
 *
 * [EN] Approach:
 *     8-directional DFS flood fill starting at (r, c). Count visited 'W' cells in the component.
 * [中文] 思路:
 *     自查詢點 (r, c) 出發執行八方向 DFS 漫水填充，走訪並計數該連通塊內所有的水域格子數目。
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

int dfs_wet(int r, int c, int R, int C, char g[20][20], int vis[20][20]) {
    if (r < 0 || r >= R || c < 0 || c >= C || vis[r][c] || g[r][c] != 'W') return 0;
    vis[r][c] = 1;
    int count = 1;
    for (int dr = -1; dr <= 1; dr++) {
        for (int dc = -1; dc <= 1; dc++) {
            if (dr != 0 || dc != 0) {
                count += dfs_wet(r + dr, c + dc, R, C, g, vis);
            }
        }
    }
    return count;
}

int solve_uva469(int R, int C, char g[20][20], int qr, int qc) {
    int vis[20][20] = {0};
    return dfs_wet(qr, qc, R, C, g, vis);
}

int main(void) {

    char g[20][20] = {"WWL", "LWL", "LLL"};
    int area = solve_uva469(3, 3, g, 0, 0); // (0,0), (0,1), (1,1) -> 3
    int ok = (area == 3);
    printf("%s: UVa 469 - Wetlands of Florida\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
