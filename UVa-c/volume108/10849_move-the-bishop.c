/*
 * ==========================================================================
 * UVa 10849 - Move the bishop
 * Title-CN: 移動主教
 * Difficulty: Easy
 * Tags: Math, Chess Simulation
 * URL: https://onlinejudge.org/external/108/10849.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the minimum number of moves for a bishop on an N x N chessboard to move from (r1, c1) to (r2, c2).
 *
 * [中文] 題目說明:
 *     在 N x N 棋盤上，求主教從 (r1, c1) 移動到 (r2, c2) 的最少步數（0、1、2 或不可達）。
 *
 * [EN] Approach:
 *     If (r1,c1)==(r2,c2) -> 0. If (r1+c1)%2 != (r2+c2)%2 -> impossible (no move). If on same diagonal |r1-r2| == |c1-c2| -> 1. Otherwise -> 2.
 * [中文] 思路:
 *     若同格為 0 步；若兩格奇偶性不同（顏色不同）則不可達；若在同一對角線上為 1 步；否則最多 2 步必可轉向抵達。
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

int min_bishop_moves(int n, int r1, int c1, int r2, int c2) {
    if (r1 == r2 && c1 == c2) return 0;
    if ((r1 + c1) % 2 != (r2 + c2) % 2) return -1; // impossible
    if (abs(r1 - r2) == abs(c1 - c2)) return 1;
    return 2;
}

int main(void) {

    int ok = (min_bishop_moves(8, 1, 1, 1, 1) == 0) &&
             (min_bishop_moves(8, 1, 1, 2, 2) == 1) &&
             (min_bishop_moves(8, 1, 1, 1, 3) == 2) &&
             (min_bishop_moves(8, 1, 1, 1, 2) == -1);
    printf("%s: UVa 10849 - Move the bishop\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
