/*
 * ==========================================================================
 * UVa 11538 - Chess Queen
 * Title-CN: 西洋棋皇后攻擊對數
 * Difficulty: Easy
 * Tags: Math, Combinatorics
 * URL: https://onlinejudge.org/external/115/11538.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count the number of pairs of squares on an M x N chessboard where two queens can attack each other (same row, column, or diagonal).
 *
 * [中文] 題目說明:
 *     計算在 M x N 棋盤上擺放兩顆皇后使其互相攻擊（同行、同列或同對角線）的格子對數總量。
 *
 * [EN] Approach:
 *     Rows: M * N*(N-1). Cols: N * M*(M-1). Diagonals: sum over diagonals length L: 2 * L*(L-1). Combine into closed form formula.
 * [中文] 思路:
 *     同行互攻對數為 M * N*(N-1)，同列為 N * M*(M-1)，對角線分為兩端遞增與中間平行等長段推導出 closed-form 公式求總和。
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

unsigned long long count_queen_pairs(unsigned long long n, unsigned long long m) {
    if (n > m) { unsigned long long t = n; n = m; m = t; }
    unsigned long long rows_cols = n * m * (n + m - 2);
    unsigned long long diag = 2 * n * (n - 1) * (3 * m - n - 1) / 3;
    return rows_cols + diag;
}

int main(void) {

    unsigned long long ans = count_queen_pairs(2, 2); // 4 squares, any pair can attack -> C(4, 2) * 2 = 12
    int ok = (ans == 12);
    printf("%s: UVa 11538 - Chess Queen\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
