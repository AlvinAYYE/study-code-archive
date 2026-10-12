/*
 * ==========================================================================
 * UVa 11461 - Square Numbers
 * Title-CN: 完全平方數計數
 * Difficulty: UVa Star 1 / CPE 49 顆星必考題
 * Tags: math
 * URL: https://onlinejudge.org/external/114/11461.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count square numbers in range [a, b].
 *
 * [中文] 題目說明:
 *     計算區間 [a, b] 內完全平方數的數量。
 *
 * [EN] Approach: floor(sqrt(b)) - ceil(sqrt(a)) + 1.
 * [中文] 思路: 利用開根號取下高斯與上高斯直接 O(1) 求得。
 * ==========================================================================
 */
#include <stdio.h>
#include <math.h>

int solve_uva11461(int a, int b) {
    int r1 = (int)ceil(sqrt((double)a));
    int r2 = (int)floor(sqrt((double)b));
    if (r1 > r2) return 0;
    return r2 - r1 + 1;
}

int main(void) {
    int ok = (solve_uva11461(1, 4) == 2) && (solve_uva11461(1, 10) == 3);
    printf("%s: UVa 11461 - Square Numbers\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
