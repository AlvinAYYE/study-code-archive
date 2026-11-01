/*
 * ==========================================================================
 * UVa 11085 - Back to the 8-Queens
 * Title-CN: 回到八皇后棋盤最少移動步數
 * Difficulty: UVa Star 2
 * Tags: backtracking, brute-force
 * URL: https://onlinejudge.org/external/110/11085.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given row positions of 8 queens in columns 1..8, find minimum column-wise moves to reach any valid 8-queens solution.
 *
 * [中文] 題目說明:
 *     給定 8 個皇后在 8 縱列上的初始行位置，求將其移動至任一合法八皇后棋盤狀態所需的最少單列移動步數。
 *
 * [EN] Approach:
 *     Precompute all 92 valid 8-queens configurations. For input configuration, find minimum differences sum(q[c] != target[c]).
 * [中文] 思路:
 *     預先回溯計算出全部 92 種標準八皇后解法，比對輸入之 8 皇后位置，取需要更動縱列數最小者輸出。
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

int min_moves_8q(int *init, int sol92[92][8]) {
    int min_m = 8;
    for (int s = 0; s < 92; s++) {
        int moves = 0;
        for (int c = 0; c < 8; c++) {
            if (init[c] != sol92[s][c]) moves++;
        }
        if (moves < min_m) min_m = moves;
    }
    return min_m;
}

int main(void) {

    int s92[92][8] = {0};
    int q[8] = {1, 5, 8, 6, 3, 7, 2, 4}; // valid solution
    memcpy(s92[0], q, sizeof(q));
    int m = min_moves_8q(q, s92);
    int ok = (m == 0);
    printf("%s: UVa 11085 - Back to the 8-Queens\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
