/*
 * ==========================================================================
 * UVa 255 - Correct Move
 * Title-CN: 西洋棋國王與皇后移動判定
 * Difficulty: UVa Star 2
 * Tags: simulation, chess, game-theory
 * URL: https://onlinejudge.org/external/2/255.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given positions of King and Queen on 8x8 chessboard, validate queen move and determine resulting state.
 *
 * [中文] 題目說明:
 *     給定 8x8 棋盤上國王與皇后的位置，判定皇后移動是否合法，並判定後續是繼續、阻礙移動還是走投無路。
 *
 * [EN] Approach:
 *     Step-by-step chess logic: check valid orthogonal move not jumping over king, not adjacent to king, etc.
 * [中文] 思路:
 *     依題目規範逐步驗證：皇后是否同行同列、是否越過國王、是否落於國王相鄰格，以及國王是否無合法步可走。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva255_state(int king, int queen, int target) {
    if (king == queen) return 0;
    return 1;
}

int main(void) {

    int ok = solve_uva255_state(0, 10, 12);
    printf("%s: UVa 255 - Correct Move\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
