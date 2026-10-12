/*
 * ==========================================================================
 * UVa 10189 - Minesweeper
 * Title-CN: 踩地雷
 * Difficulty: UVa Star 1 / CPE 49 顆星必考題
 * Tags: 2d-array, simulation, grid
 * URL: https://onlinejudge.org/external/101/10189.pdf
 * ==========================================================================
 * [EN] Problem Statement:
 *     Have you ever played Minesweeper? The goal of the game is to find where
 *     all the mines are located within a M x N field.
 *     Given an M x N grid containing safe spots ('.') and mines ('*'), produce
 *     a field where each safe spot is replaced with a number indicating how
 *     many mines are adjacent to it (in all 8 directions).
 *
 * [中文] 題目說明:
 *     給定一個 n x m 的踩地雷棋盤，其中 '*' 代表地雷，'.' 代表安全格。
 *     請計算出每個安全格周圍 8 個方向（上下左右與對角線）總共有幾顆地雷，
 *     並輸出帶有地雷提示數字的新棋盤。
 *
 * Examples:
 *   Input:
 *     4 4
 *     *...
 *     ....
 *     .*..
 *     ....
 *   Output:
 *     Field #1:
 *     *100
 *     2210
 *     1*10
 *     1110
 *
 * Constraints:
 *   - 0 < n, m <= 100
 *   - Input ends when n = 0 and m = 0.
 *
 * [EN] Approach:
 *     For each '.', check the 8 neighboring cells. If neighbor is '*', increment count.
 * [中文] 思路:
 *     雙重迴圈遍歷棋盤，對於非地雷的格子，使用 8 個方向的位移陣列統計周圍地雷總數。
 * ==========================================================================
 */
#include <stdio.h>
#include <string.h>

static const int dr[8] = {-1, -1, -1,  0, 0,  1, 1, 1};
static const int dc[8] = {-1,  0,  1, -1, 1, -1, 0, 1};

void solve_uva10189(int n, int m, char grid[105][105], char result[105][105]) {
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (grid[r][c] == '*') {
                result[r][c] = '*';
            } else {
                int mines = 0;
                for (int d = 0; d < 8; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == '*') {
                        mines++;
                    }
                }
                result[r][c] = (char)('0' + mines);
            }
        }
        result[r][m] = '\0';
    }
}

int main(void) {
    char grid[105][105] = {
        "*...",
        "....",
        ".*..",
        "...."
    };
    char res[105][105];
    solve_uva10189(4, 4, grid, res);
    int ok = (strcmp(res[0], "*100") == 0) &&
             (strcmp(res[1], "2210") == 0) &&
             (strcmp(res[2], "1*10") == 0) &&
             (strcmp(res[3], "1110") == 0);

    printf("%s: UVa 10189 - Minesweeper\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
