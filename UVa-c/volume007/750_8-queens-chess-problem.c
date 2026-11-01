/*
 * ==========================================================================
 * UVa 750 - 8 Queens Chess Problem
 * Title-CN: 定點八皇后問題 (指定起點回溯)
 * Difficulty: UVa Star 1
 * Tags: backtracking, chess
 * URL: https://onlinejudge.org/external/7/750.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Output all valid 8-queens board solutions where one queen is fixed at given square (r, c).
 *
 * [中文] 題目說明:
 *     在 8x8 棋盤上擺放 8 個皇后互不衝突，其中指定位置 (r, c) 已預先固定一個皇后，輸出所有合法解。
 *
 * [EN] Approach:
 *     Standard 8-queens backtracking search across 8 columns. Force column c to place queen at row r.
 * [中文] 思路:
 *     8 列回溯擺放皇后，遇到給定的指定行時強制選擇指定列，其餘行枚舉所有無衝突位置，字典序輸出解答。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

static int ans_count_750;
static int row_750[9];

void dfs_750(int col, int fix_r, int fix_c) {
    if (col == 9) { ans_count_750++; return; }
    if (col == fix_c) {
        /* Check fix_r valid */
        for (int prev = 1; prev < col; prev++) {
            if (row_750[prev] == fix_r || abs(row_750[prev] - fix_r) == abs(prev - fix_c)) return;
        }
        row_750[col] = fix_r;
        dfs_750(col + 1, fix_r, fix_c);
        return;
    }
    for (int r = 1; r <= 8; r++) {
        int ok = 1;
        for (int prev = 1; prev < col; prev++) {
            if (row_750[prev] == r || abs(row_750[prev] - r) == abs(prev - col)) { ok = 0; break; }
        }
        if (ok) {
            row_750[col] = r;
            dfs_750(col + 1, fix_r, fix_c);
        }
    }
}

int solve_uva750(int fix_r, int fix_c) {
    ans_count_750 = 0;
    dfs_750(1, fix_r, fix_c);
    return ans_count_750;
}

int main(void) {

    int ok = (solve_uva750(1, 1) == 4);
    printf("%s: UVa 750 - 8 Queens Chess Problem\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
