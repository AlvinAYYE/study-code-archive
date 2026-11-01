/*
 * ==========================================================================
 * UVa 639 - Don't Get Rooked
 * Title-CN: 不要被城堡吃掉 (帶障礙牆之城堡最大放置)
 * Difficulty: UVa Star 1
 * Tags: backtracking, brute-force
 * URL: https://onlinejudge.org/external/6/639.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Place maximum number of rooks on n x n board with walls 'X' such that no two rooks can attack each other.
 *
 * [中文] 題目說明:
 *     在 n x n (n <= 4) 的棋盤上放置互不攻擊的城堡。牆壁 'X' 會阻隔城堡的攻擊視線，求最大擺放數量。
 *
 * [EN] Approach:
 *     Backtracking search: for each empty cell, place rook if not seen by another rook in 4 ray directions; recurse and find max.
 * [中文] 思路:
 *     因棋盤最大僅 4x4，直接回溯搜尋每個方格放或不放，放置前向四個方向掃描檢查在遇牆前是否有其他城堡。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

static int max_rooks_639;

int can_place_rook_639(int r, int c, int n, char board[5][5]) {
    for (int i = r - 1; i >= 0 && board[i][c] != 'X'; i--) if (board[i][c] == 'R') return 0;
    for (int i = r + 1; i < n && board[i][c] != 'X'; i++) if (board[i][c] == 'R') return 0;
    for (int j = c - 1; j >= 0 && board[r][j] != 'X'; j--) if (board[r][j] == 'R') return 0;
    for (int j = c + 1; j < n && board[r][j] != 'X'; j++) if (board[r][j] == 'R') return 0;
    return 1;
}

void dfs_639(int pos, int cnt, int n, char board[5][5]) {
    if (pos == n * n) {
        if (cnt > max_rooks_639) max_rooks_639 = cnt;
        return;
    }
    int r = pos / n, c = pos % n;
    if (board[r][c] == '.' && can_place_rook_639(r, c, n, board)) {
        board[r][c] = 'R';
        dfs_639(pos + 1, cnt + 1, n, board);
        board[r][c] = '.';
    }
    dfs_639(pos + 1, cnt, n, board);
}

int solve_uva639(int n, char board[5][5]) {
    max_rooks_639 = 0;
    dfs_639(0, 0, n, board);
    return max_rooks_639;
}

int main(void) {

    char b[5][5] = {".X..", "....", "XX..", "...."};
    int ok = (solve_uva639(4, b) == 5);
    printf("%s: UVa 639 - Don't Get Rooked\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
