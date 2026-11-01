/*
 * ==========================================================================
 * UVa 10783 - Odd Sum
 * Title-CN: 區間奇數總和
 * Difficulty: UVa Star 1
 * Tags: math
 * URL: https://onlinejudge.org/external/107/10783.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Compute the sum of all odd integers in range [a, b].
 *
 * [中文] 題目說明:
 *     計算區間 [a, b] 內所有奇數的總和。
 *
 * [EN] Approach:
 *     Loop through odd numbers from (a % 2 ? a : a + 1) to b with step 2.
 * [中文] 思路:
 *     將區間起點調整至奇數，每次遞增 2 累加至 b，直接輸出奇數和。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva10783(int a, int b) {
    int sum = 0;
    int start = (a % 2 != 0) ? a : a + 1;
    for (int x = start; x <= b; x += 2) sum += x;
    return sum;
}

int main(void) {

    int ok = (solve_uva10783(1, 5) == 9) && (solve_uva10783(3, 5) == 8);
    printf("%s: UVa 10783 - Odd Sum\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
