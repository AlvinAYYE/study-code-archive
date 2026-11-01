/*
 * ==========================================================================
 * UVa 11461 - Square Numbers
 * Title-CN: 區間完全平方數個數
 * Difficulty: UVa Star 1
 * Tags: math
 * URL: https://onlinejudge.org/external/114/11461.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count total number of square numbers between integers a and b inclusive.
 *
 * [中文] 題目說明:
 *     統計閉區間 [a, b] 內完全平方數的總個數。
 *
 * [EN] Approach:
 *     Square numbers count in [a, b] = floor(sqrt(b)) - ceil(sqrt(a)) + 1.
 * [中文] 思路:
 *     數學公式：開根號取整，區間內完全平方數數量恰為 floor(sqrt(b)) - ceil(sqrt(a)) + 1。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <math.h>

int solve_uva11461(int a, int b) {
    int r_b = (int)floor(sqrt(b));
    int r_a = (int)ceil(sqrt(a));
    return (r_b >= r_a) ? (r_b - r_a + 1) : 0;
}

int main(void) {

    int ok = (solve_uva11461(1, 4) == 2) && (solve_uva11461(1, 10) == 3);
    printf("%s: UVa 11461 - Square Numbers\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
