/*
 * ==========================================================================
 * UVa 11727 - Cost Cutting
 * Title-CN: 裁員精簡成本
 * Difficulty: UVa Star 1
 * Tags: sorting, math
 * ==========================================================================
 * [EN] Problem: Find the median of 3 integers.
 * [中文] 題目說明: 求三個整數的中位數。
 * [EN] Approach: Sort 3 elements or min/max exclusions.
 * [中文] 思路: 排除最大與最小值即為中位數。
 * ==========================================================================
 */
#include <stdio.h>

int solve_uva11727(int a, int b, int c) {
    if ((a > b && a < c) || (a < b && a > c)) return a;
    if ((b > a && b < c) || (b < a && b > c)) return b;
    return c;
}

int main(void) {
    int ok = (solve_uva11727(1000, 2000, 3000) == 2000);
    printf("%s: UVa 11727 - Cost Cutting\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
