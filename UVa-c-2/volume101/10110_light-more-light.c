/*
 * ==========================================================================
 * UVa 10110 - Light, more light
 * Title-CN: 開燈與關燈
 * Difficulty: UVa Star 1
 * Tags: math, number-theory
 * ==========================================================================
 * [EN] Problem: Is bulb n on after n passersby?
 * [中文] 題目說明: 第 n 盞燈因數個數若為奇數則亮，等價於 n 是否為完全平方數。
 * [EN] Approach: Check if floor(sqrt(n))^2 == n.
 * [中文] 思路: 判斷 n 是否為完全平方數。
 * ==========================================================================
 */
#include <stdio.h>
#include <math.h>

int solve_uva10110(unsigned int n) {
    unsigned int r = (unsigned int)(sqrt((double)n) + 1e-9);
    return (r * r == n);
}

int main(void) {
    int ok = solve_uva10110(4) && !solve_uva10110(3);
    printf("%s: UVa 10110 - Light, more light\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
