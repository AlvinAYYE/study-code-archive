/*
 * ==========================================================================
 * UVa 11195 - Another n-Queen Problem
 * Title-CN: 帶障礙格的 N 皇后問題
 * Difficulty: Medium
 * Tags: Backtracking, Bitmask, N-Queens
 * URL: https://onlinejudge.org/external/111/11195.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count the number of valid n-Queens arrangements on an n x n board with some squares blocked.
 *
 * [中文] 題目描述:
 *     在有部分格子為障礙物 '*' 的 n x n 棋盤上，計算可放置 n 個互不攻擊皇后的總方案數。
 *
 * [EN] Approach:
 *     Use fast bitmask backtracking: track column, left-diagonal, and right-diagonal availability along with row obstacle mask.
 *
 * [中文] 解題思維:
 *     使用經典位元運算回溯：利用位元遮罩維護列、主對角線、副對角線佔用狀態與該列障礙物遮罩。
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

static int nq_total, nq_all_mask;
static int nq_bad[20];

static void nq_solve(int row, int ld, int rd, int col) {
    if (col == nq_all_mask) {
        nq_total++;
        return;
    }
    int pos = nq_all_mask & (~(ld | rd | col | nq_bad[row]));
    while (pos) {
        int p = pos & (-pos);
        pos -= p;
        nq_solve(row + 1, (ld | p) << 1, (rd | p) >> 1, col | p);
    }
}

int count_n_queens_obstacles(int n, const char board[20][20]) {
    nq_total = 0;
    nq_all_mask = (1 << n) - 1;
    for (int r = 0; r < n; r++) {
        nq_bad[r] = 0;
        for (int c = 0; c < n; c++) {
            if (board[r][c] == '*') nq_bad[r] |= (1 << c);
        }
    }
    nq_solve(0, 0, 0, 0);
    return nq_total;
}

int main(void) {

    char b[20][20] = {
        "....",
        "....",
        "....",
        "...."
    };
    int res4 = count_n_queens_obstacles(4, b); // Standard 4-queens has 2 solutions
    int ok = (res4 == 2);
    printf("%s: UVa 11195 - Another n-Queen Problem\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
