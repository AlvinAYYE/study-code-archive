/*
 * ==========================================================================
 * UVa 10703 - Free spots
 * Title-CN: 空白方格計數 (二維網格覆蓋)
 * Difficulty: UVa Star 1
 * Tags: simulation, 2d-grid
 * URL: https://onlinejudge.org/external/107/10703.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given W x H board and multiple subrectangles, count number of grid spots not covered by any rectangle.
 *
 * [中文] 題目說明:
 *     在 W x H 的棋盤上標記多個子矩形區域，求未被任何矩形覆蓋的空白格總數。
 *
 * [EN] Approach:
 *     Maintain 2D boolean array covered[w][h]. Mark cells inside each given rectangle. Count unmarked cells.
 * [中文] 思路:
 *     二維陣列標記法：對每個輸入矩形將範圍內各格子設為 1，最後統計陣列中為 0 的格子總數。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva10703(int w, int h, int n, int rects[][4]) {
    char board[505][505] = {0};
    for (int i = 0; i < n; i++) {
        int x1 = (rects[i][0] < rects[i][2]) ? rects[i][0] : rects[i][2];
        int x2 = (rects[i][0] > rects[i][2]) ? rects[i][0] : rects[i][2];
        int y1 = (rects[i][1] < rects[i][3]) ? rects[i][1] : rects[i][3];
        int y2 = (rects[i][1] > rects[i][3]) ? rects[i][1] : rects[i][3];
        for (int x = x1; x <= x2; x++) {
            for (int y = y1; y <= y2; y++) board[x][y] = 1;
        }
    }
    int empty_cnt = 0;
    for (int x = 1; x <= w; x++) {
        for (int y = 1; y <= h; y++) if (!board[x][y]) empty_cnt++;
    }
    return empty_cnt;
}

int main(void) {

    int r[1][4] = {{1, 1, 2, 2}};
    int ok = (solve_uva10703(3, 3, 1, r) == 5); /* 9 - 4 = 5 */
    printf("%s: UVa 10703 - Free spots\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
