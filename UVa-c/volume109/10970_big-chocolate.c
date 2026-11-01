/*
 * ==========================================================================
 * UVa 10970 - Big Chocolate
 * Title-CN: 大巧克力最少分割刀數
 * Difficulty: UVa Star 1
 * Tags: math
 * URL: https://onlinejudge.org/external/109/10970.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find minimum number of cuts to break an M x N chocolate bar into 1 x 1 pieces.
 *
 * [中文] 題目說明:
 *     將 M x N 大小的巧克力塊切成 1x1 的獨立小方塊，求最少需切割的刀數。
 *
 * [EN] Approach:
 *     Each cut increases total number of pieces by 1. To reach M*N pieces from 1, exactly M*N - 1 cuts are needed.
 * [中文] 思路:
 *     每切一刀使塊數增加 1。由 1 塊分割為 M*N 個單元塊，所需切割刀數恆等於 M*N - 1。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva10970(int m, int n) {
    return m * n - 1;
}

int main(void) {

    int ok = (solve_uva10970(2, 2) == 3) && (solve_uva10970(1, 10) == 9);
    printf("%s: UVa 10970 - Big Chocolate\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
