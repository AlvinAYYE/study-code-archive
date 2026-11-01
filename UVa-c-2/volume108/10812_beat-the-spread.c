/*
 * ==========================================================================
 * UVa 10812 - Beat the Spread!
 * Title-CN: 二元一次聯立得分方程
 * Difficulty: UVa Star 1
 * Tags: math
 * URL: https://onlinejudge.org/external/108/10812.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given sum s and difference d of two team scores, find original scores or determine impossible.
 *
 * [中文] 題目說明:
 *     給定兩隊得分之和 s 與差 d，求兩隊的原始得分 (若無整數非負解則判定不可能)。
 *
 * [EN] Approach:
 *     x = (s + d) / 2, y = (s - d) / 2. Valid iff s >= d, (s + d) % 2 == 0, and y >= 0.
 * [中文] 思路:
 *     由 x + y = s 與 x - y = d 解得 x = (s+d)/2, y = (s-d)/2。須滿足 s >= d 且 s+d 為偶數。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva10812(long long s, long long d, long long *x, long long *y) {
    if (s < d || (s + d) % 2 != 0) return 0;
    *x = (s + d) / 2;
    *y = (s - d) / 2;
    return 1;
}

int main(void) {

    long long x, y;
    int ok = solve_uva10812(40, 20, &x, &y) && (x == 30 && y == 10);
    printf("%s: UVa 10812 - Beat the Spread!\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
