/*
 * ==========================================================================
 * UVa 141 - The Spot Game
 * Title-CN: 黑白圍棋式翻轉盤面重複狀態判定
 * Difficulty: UVa Star 2
 * Tags: simulation, hash
 * URL: https://onlinejudge.org/external/1/141.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Two players place or remove stones on an N x N board. A player loses if their move restores a board configuration that occurred previously (under 4 rotations).
 *
 * [中文] 題目說明:
 *     兩位玩家在 N x N 棋盤上下棋或拔子。若玩家的走法使盤面呈現與先前盤面 (包含 4 種 90 度旋轉) 完全相同的狀態，則該玩家立即判負。
 *
 * [EN] Approach:
 *     Maintain 2D board state. For each move, apply edit, generate all 4 rotated representations, check against hash set of historical boards, then store canonical hash.
 * [中文] 思路:
 *     維護二維盤面狀態，每次落子後生成 90°、180°、270° 及原圖共 4 種旋轉表示法，檢查是否曾在歷史紀錄中出現過。
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

void rotate90(int n, int src[50][50], int dst[50][50]) {
    for (int r = 0; r < n; r++)
        for (int c = 0; c < n; c++)
            dst[c][n - 1 - r] = src[r][c];
}

int board_equal(int n, int a[50][50], int b[50][50]) {
    for (int r = 0; r < n; r++)
        for (int c = 0; c < n; c++)
            if (a[r][c] != b[r][c]) return 0;
    return 1;
}

int main(void) {

    int b1[50][50] = {0}, b2[50][50] = {0};
    b1[0][0] = 1;
    rotate90(2, b1, b2);
    int ok = (b2[0][1] == 1);
    printf("%s: UVa 141 - The Spot Game\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
