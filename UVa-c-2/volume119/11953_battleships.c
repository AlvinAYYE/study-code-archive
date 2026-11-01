/*
 * ==========================================================================
 * UVa 11953 - Battleships
 * Title-CN: 海戰棋存活戰艦連通分量計數
 * Difficulty: UVa Star 2
 * Tags: graph, flood-fill, dfs
 * URL: https://onlinejudge.org/external/119/11953.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given a grid of '.', 'x' (alive ship part), and '@' (hit part), count ships (connected horizontal/vertical cells) that have at least one 'x'.
 *
 * [中文] 題目說明:
 *     給定海戰棋盤面，包含空海 '.'、完好戰艦部位 'x' 與被擊中部位 '@'，統計包含至少一個完好部位 'x' 的存活戰艦總數。
 *
 * [EN] Approach:
 *     Flood fill (DFS) connected components of 'x' and '@'. Mark has_alive flag if any cell is 'x'. Count components with has_alive == 1.
 * [中文] 思路:
 *     以 DFS 漫水填充走訪相鄰的 'x' 與 '@' 形成整艘戰艦，若連通分量內包含至少一個 'x' 則存活戰艦數加一。
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

void dfs_ship(int r, int c, int n, char g[20][20], int *has_x) {
    if (r < 0 || r >= n || c < 0 || c >= n || g[r][c] == '.') return;
    if (g[r][c] == 'x') *has_x = 1;
    g[r][c] = '.';
    dfs_ship(r + 1, c, n, g, has_x);
    dfs_ship(r - 1, c, n, g, has_x);
    dfs_ship(r, c + 1, n, g, has_x);
    dfs_ship(r, c - 1, n, g, has_x);
}

int solve_uva11953(int n, char g[20][20]) {
    int alive_ships = 0;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (g[r][c] == 'x' || g[r][c] == '@') {
                int has_x = 0;
                dfs_ship(r, c, n, g, &has_x);
                if (has_x) alive_ships++;
            }
        }
    }
    return alive_ships;
}

int main(void) {

    char b[20][20] = {"x.", "@."};
    int cnt = solve_uva11953(2, b);
    int ok = (cnt == 1);
    printf("%s: UVa 11953 - Battleships\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
