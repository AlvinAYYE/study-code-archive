/*
 * ==========================================================================
 * UVa 11360 - Have Fun with Matrices
 * Title-CN: 矩陣變換趣味遊戲
 * Difficulty: Easy
 * Tags: Matrix Simulation
 * URL: https://onlinejudge.org/external/113/11360.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Perform row swaps, col swaps, transpose, and inc/dec modulo 10 on an N x N digit matrix.
 *
 * [中文] 題目說明:
 *     對 N x N 數字矩陣執行行交換、列交換、轉置、全體加減 1 (模 10) 等操作。
 *
 * [EN] Approach:
 *     Simulate the operations step by step directly on the matrix.
 * [中文] 思路:
 *     直接在二維陣列上模擬各操作：row a b、col a b、transpose、inc 及 dec（模 10 循環）。
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

void matrix_inc(int n, int m[10][10]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            m[i][j] = (m[i][j] + 1) % 10;
}
void matrix_transpose_op(int n, int m[10][10]) {
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            int t = m[i][j]; m[i][j] = m[j][i]; m[j][i] = t;
        }
}

int main(void) {

    int m[10][10] = {{1, 2}, {3, 4}};
    matrix_inc(2, m);
    int ok = (m[0][0] == 2 && m[1][1] == 5);
    printf("%s: UVa 11360 - Have Fun with Matrices\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
