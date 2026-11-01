/*
 * ==========================================================================
 * UVa 278 - Chess
 * Title-CN: 西洋棋棋盤最大獨立放置數
 * Difficulty: UVa Star 1
 * Tags: math, chess, greedy
 * URL: https://onlinejudge.org/external/2/278.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find maximum number of non-attacking pieces of given type (Rook, Knight, Queen, King) on m x n board.
 *
 * [中文] 題目說明:
 *     求在 m x n 棋盤上互不攻擊的城堡、騎士、皇后或國王的最大擺放數量。
 *
 * [EN] Approach:
 *     Math formulas: Rook: min(m, n); Knight: (m*n + 1)/2; King: ((m+1)/2) * ((n+1)/2); Queen: min(m, n).
 * [中文] 思路:
 *     數學公式：城堡為 min(m, n)；騎士為 (m*n + 1)/2；國王為 ((m+1)/2) * ((n+1)/2)；皇后為 min(m, n)。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva278(char piece, int m, int n) {
    if (piece == 'r') return (m < n) ? m : n;
    if (piece == 'k') return (m * n + 1) / 2;
    if (piece == 'Q') return (m < n) ? m : n;
    if (piece == 'K') return ((m + 1) / 2) * ((n + 1) / 2);
    return 0;
}

int main(void) {

    int ok = (solve_uva278('r', 4, 4) == 4) && (solve_uva278('k', 4, 4) == 8);
    printf("%s: UVa 278 - Chess\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
