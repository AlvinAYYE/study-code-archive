/*
 * ==========================================================================
 * UVa 167 - The Sultan's Successors
 * Title-CN: 蘇丹的繼承人 (八皇后加權最大值)
 * Difficulty: UVa Star 1
 * Tags: backtracking, recursion, chess
 * URL: https://onlinejudge.org/external/1/167.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Place 8 non-attacking queens on 8x8 weighted chessboard to maximize sum of occupied square scores.
 *
 * [中文] 題目說明:
 *     在 8x8 的加權棋盤上放置 8 個互不攻擊的西洋棋皇后，求佔據方格權重和的最大值。
 *
 * [EN] Approach:
 *     Backtracking search over 92 standard 8-queens solutions. Sum board values for each valid configuration and find max.
 * [中文] 思路:
 *     利用行、主對角線、次對角線衝突陣列回溯搜尋八皇后的 92 種合法擺法，取棋盤分數總和的最大值。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

static int max_score_167;
static int board_167[8][8];
static int col_used_167[8], diag1_167[16], diag2_167[16];

void dfs_167(int row, int cur_sum) {
    if (row == 8) {
        if (cur_sum > max_score_167) max_score_167 = cur_sum;
        return;
    }
    for (int c = 0; c < 8; c++) {
        if (!col_used_167[c] && !diag1_167[row + c] && !diag2_167[row - c + 7]) {
            col_used_167[c] = diag1_167[row + c] = diag2_167[row - c + 7] = 1;
            dfs_167(row + 1, cur_sum + board_167[row][c]);
            col_used_167[c] = diag1_167[row + c] = diag2_167[row - c + 7] = 0;
        }
    }
}

int solve_uva167(int b[8][8]) {
    max_score_167 = 0;
    for (int i = 0; i < 8; i++) {
        col_used_167[i] = 0;
        for (int j = 0; j < 8; j++) board_167[i][j] = b[i][j];
    }
    for (int i = 0; i < 16; i++) diag1_167[i] = diag2_167[i] = 0;
    dfs_167(0, 0);
    return max_score_167;
}

int main(void) {

    int b[8][8] = {0};
    for (int i = 0; i < 8; i++) for (int j = 0; j < 8; j++) b[i][j] = 10;
    int ok = (solve_uva167(b) >= 80);
    printf("%s: UVa 167 - The Sultan's Successors\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
