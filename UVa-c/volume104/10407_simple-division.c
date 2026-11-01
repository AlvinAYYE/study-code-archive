/*
 * ==========================================================================
 * UVa 10407 - Simple division
 * Title-CN: 簡單除法同餘公因數 (GCD of Differences)
 * Difficulty: UVa Star 1
 * Tags: math, number-theory, gcd
 * URL: https://onlinejudge.org/external/104/10407.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find largest integer d such that all numbers in list have the same remainder when divided by d.
 *
 * [中文] 題目說明:
 *     給定一組非零整數序列，求最大的整數 d 使得所有整數除以 d 具有相同的餘數。
 *
 * [EN] Approach:
 *     If a_i = r (mod d), then d divides (a_i - a_1). Compute GCD of all absolute differences |a_i - a_1|.
 * [中文] 思路:
 *     同餘性質：兩數同餘則其差必為 d 的倍數。計算所有數與第一個數之差的絕對值的最大公因數 (GCD)。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

static int gcd_10407(int a, int b) { while (b) { int t = b; b = a % b; a = t; } return a; }

int solve_uva10407(int n, const int *a) {
    int g = 0;
    for (int i = 1; i < n; i++) {
        int diff = abs(a[i] - a[0]);
        g = gcd_10407(g, diff);
    }
    return g;
}

int main(void) {

    int a[4] = {701, 1059, 1417, 2312};
    int ok = (solve_uva10407(4, a) == 179);
    printf("%s: UVa 10407 - Simple division\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
