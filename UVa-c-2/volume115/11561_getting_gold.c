/*
 * ==========================================================================
 * UVa 11561 - Getting Gold
 * Title-CN: 迷宮採金 (避開陷阱微風感應)
 * Difficulty: Medium
 * Tags: Graph, DFS, BFS, Simulation
 * URL: https://onlinejudge.org/external/115/11561.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the maximum gold a player can collect starting at 'P' without risking falling into a trap 'T'.
 *
 * [中文] 題目描述:
 *     玩家在迷宮中採集金幣 'G'，若當前格四相鄰處有陷阱 'T' 則會感覺到微風而不敢前進，求能安全取得的最大金幣數。
 *
 * [EN] Approach:
 *     DFS exploration: collect gold at current cell. If any neighbor has trap 'T', do not expand neighbors.
 *
 * [中文] 解題思維:
 *     DFS/BFS 遍歷：到達新格子若有金幣則計數；若相鄰四格存在陷阱 'T' 則停止由此格向外擴展。
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

static int gold_cnt;
static int visited_11561[55][55];
static const int dr11561[] = {-1, 1, 0, 0};
static const int dc11561[] = {0, 0, -1, 1};

static void dfs_gold(int r, int c, int R, int C, const char grid[55][55]) {
    visited_11561[r][c] = 1;
    if (grid[r][c] == 'G') gold_cnt++;

    // Check for draft (adjacent trap)
    for (int d = 0; d < 4; d++) {
        int nr = r + dr11561[d], nc = c + dc11561[d];
        if (nr >= 0 && nr < R && nc >= 0 && nc < C && grid[nr][nc] == 'T') {
            return; // draft felt, do not move further
        }
    }
    // Expand
    for (int d = 0; d < 4; d++) {
        int nr = r + dr11561[d], nc = c + dc11561[d];
        if (nr >= 0 && nr < R && nc >= 0 && nc < C && !visited_11561[nr][nc] && grid[nr][nc] != '#') {
            dfs_gold(nr, nc, R, C, grid);
        }
    }
}

int collect_safe_gold(int R, int C, const char grid[55][55]) {
    gold_cnt = 0;
    memset(visited_11561, 0, sizeof(visited_11561));
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (grid[r][c] == 'P') {
                dfs_gold(r, c, R, C, grid);
                return gold_cnt;
            }
        }
    }
    return 0;
}

int main(void) {

    char g[55][55] = {
        "#####",
        "#P.G#",
        "#####"
    };
    int res = collect_safe_gold(3, 5, g);
    int ok = (res == 1);
    printf("%s: UVa 11561 - Getting Gold\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
