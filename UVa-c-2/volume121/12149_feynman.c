/*
 * ==========================================================================
 * UVa 12149 - Feynman
 * Title-CN: 費曼的正方形
 * Difficulty: UVa Star 1
 * Tags: math
 * ==========================================================================
 * [EN] Problem: Count total number of squares of any size in an N x N grid.
 * [中文] 題目說明: 計算 N x N 方格中所有不同大小的正方形總數。
 * [EN] Approach: Sum of squares formula: N*(N + 1)*(2N + 1) / 6.
 * [中文] 思路: 平方和公式：1^2 + 2^2 + ... + N^2 = N * (N + 1) * (2N + 1) / 6。
 * ==========================================================================
 */
#include <stdio.h>

long long solve_uva12149(long long n) {
    return n * (n + 1) * (2 * n + 1) / 6;
}

int main(void) {
    int ok = (solve_uva12149(2) == 5) && (solve_uva12149(8) == 204);
    printf("%s: UVa 12149 - Feynman\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
