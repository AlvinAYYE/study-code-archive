/*
 * ==========================================================================
 * UVa 10812 - Beat the Spread!
 * Title-CN: 美式足球比分預測
 * Difficulty: UVa Star 1 / CPE 49 顆星必考題
 * Tags: math
 * URL: https://onlinejudge.org/external/108/10812.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find two non-negative integer scores x, y given x + y = s and x - y = d.
 *
 * [中文] 題目說明:
 *     已知兩數之和 s 與差 d，求解兩非負整數。
 *
 * [EN] Approach: x = (s+d)/2, y = (s-d)/2. Must satisfy s >= d and (s+d) % 2 == 0.
 * [中文] 思路: 判斷 s >= d 且 (s+d) 為偶數。
 * ==========================================================================
 */
#include <stdio.h>

int solve_uva10812(long long s, long long d, long long *x, long long *y) {
    if (s < d || (s + d) % 2 != 0) return 0;
    *x = (s + d) / 2;
    *y = (s - d) / 2;
    return 1;
}

int main(void) {
    long long x, y;
    int ok1 = solve_uva10812(40, 20, &x, &y) && (x == 30 && y == 10);
    int ok2 = !solve_uva10812(20, 40, &x, &y);
    int ok = ok1 && ok2;
    printf("%s: UVa 10812 - Beat the Spread!\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
