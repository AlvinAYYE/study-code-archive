/*
 * ==========================================================================
 * UVa 10360 - Rat Attack
 * Title-CN: 滅鼠行動
 * Difficulty: UVa Star 2
 * Tags: 2d-array, prefix-sum
 * URL: https://onlinejudge.org/external/103/10360.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Bomb radius d eliminates all rats in (x-d..x+d, y-d..y+d). Find position maximizing killed rats.
 *
 * [中文] 題目說明:
 *     炸藥威力半徑為 d，可消滅方形範圍 [x-d..x+d, y-d..y+d] 內的所有老鼠。求消滅老鼠總數最大的中心座標與數量。
 *
 * [EN] Approach:
 *     Accumulate rat counts directly onto affected cells or 2D prefix sums.
 * [中文] 思路:
 *     將每窩老鼠的數量累加至其可被影響的 [x-d..x+d][y-d..y+d] 座標中，遍歷求最大值。
 * ==========================================================================
 */
#include <stdio.h>

static int killed[1025][1025];

void solve_uva10360(int d, int n, const int rats[][3], int *bx, int *by, int *bmax) {
    int max_k = -1, ans_x = 0, ans_y = 0;
    for (int i = 0; i < n; i++) {
        int x = rats[i][0], y = rats[i][1], pop = rats[i][2];
        int x1 = (x - d < 0) ? 0 : x - d;
        int x2 = (x + d > 1024) ? 1024 : x + d;
        int y1 = (y - d < 0) ? 0 : y - d;
        int y2 = (y + d > 1024) ? 1024 : y + d;
        for (int r = x1; r <= x2; r++) {
            for (int c = y1; c <= y2; c++) {
                killed[r][c] += pop;
                if (killed[r][c] > max_k) {
                    max_k = killed[r][c];
                    ans_x = r; ans_y = c;
                }
            }
        }
    }
    *bx = ans_x; *by = ans_y; *bmax = max_k;
}

int main(void) {
    int rats[1][3] = {{500, 500, 10}};
    int bx, by, bmax;
    solve_uva10360(1, 1, rats, &bx, &by, &bmax);
    int ok = (bmax == 10);
    printf("%s: UVa 10360 - Rat Attack\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
