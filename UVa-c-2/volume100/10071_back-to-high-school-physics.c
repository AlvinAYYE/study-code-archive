/*
 * ==========================================================================
 * UVa 10071 - Back to High School Physics
 * Title-CN: 回到高中物理
 * Difficulty: UVa Star 1 / CPE 49 顆星必考題
 * Tags: math, physics
 * URL: https://onlinejudge.org/external/100/10071.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given velocity v at time t with constant acceleration, find displacement at 2t.
 *
 * [中文] 題目說明:
 *     等加速度運動中，在時間 t 時速度為 v，求在時間 2t 時的位移。
 *
 * [EN] Approach: S = 2 * v * t.
 * [中文] 思路: 根據等加速度運動公式推導，位移恰為 2 * v * t。
 * ==========================================================================
 */
#include <stdio.h>

long long solve_uva10071(long long v, long long t) {
    return 2LL * v * t;
}

int main(void) {
    int ok = (solve_uva10071(0, 3) == 0) && (solve_uva10071(5, 12) == 120);
    printf("%s: UVa 10071 - Back to High School Physics\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
