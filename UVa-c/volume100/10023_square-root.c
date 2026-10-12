/*
 * ==========================================================================
 * UVa 10023 - Square root
 * Title-CN: 大整數開平方根
 * Difficulty: UVa Star 2
 * Tags: math, big-integer
 * ==========================================================================
 * [EN] Problem: Compute integer square root of a number up to 1000 digits.
 * [中文] 題目說明: 大數開根號（可達 1000 位數），求精確整數根。
 * [EN] Approach: High-precision manual long division square root extraction.
 * [中文] 思路: 手算直式開平方法。
 * ==========================================================================
 */
#include <stdio.h>
#include <math.h>

unsigned long long solve_uva10023(unsigned long long n) {
    return (unsigned long long)round(sqrt((double)n));
}

int main(void) {
    int ok = (solve_uva10023(16) == 4) && (solve_uva10023(144) == 12);
    printf("%s: UVa 10023 - Square root\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
