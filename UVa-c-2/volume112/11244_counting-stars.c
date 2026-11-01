/*
 * ==========================================================================
 * UVa 11244 - Counting Stars
 * Title-CN: 夜空孤立星星計數
 * Difficulty: UVa Star 1
 * Tags: simulation, 2d-grid
 * URL: https://onlinejudge.org/external/112/11244.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count the number of lone stars ('*') in a sky grid that have no neighboring '*' in any of the 8 adjacent directions.
 *
 * [中文] 題目說明:
 *     在星空網格中統計孤立的星星 ('*') 數量：該星號周圍 8 個相鄰格子內均不得出現其他任何星號。
 *
 * [EN] Approach:
 *     Scan each cell: if '*', inspect all 8 neighbors. If no neighbor is '*', increment lone star count.
 * [中文] 思路:
 *     雙重迴圈逐格檢查：遇到 '*' 則檢查周圍 8 個相鄰方向，若皆為 '.' 則此星星為孤立星，計數加一。
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

int solve_uva11244(int R, int C, char sky[20][20]) {
    int stars = 0;
    int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (sky[r][c] == '*') {
                int lone = 1;
                for (int d = 0; d < 8; d++) {
                    int nr = r + dr[d], nc = c + dc[d];
                    if (nr >= 0 && nr < R && nc >= 0 && nc < C && sky[nr][nc] == '*') {
                        lone = 0;
                        break;
                    }
                }
                if (lone) stars++;
            }
        }
    }
    return stars;
}

int main(void) {

    char s[20][20] = {"*..", "...", "..*"};
    int cnt = solve_uva11244(3, 3, s);
    int ok = (cnt == 2);
    printf("%s: UVa 11244 - Counting Stars\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
