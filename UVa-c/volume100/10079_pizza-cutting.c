/*
 * ==========================================================================
 * UVa 10079 - Pizza Cutting
 * Title-CN: 切披薩問題
 * Difficulty: UVa Star 1
 * Tags: math
 * ==========================================================================
 * [EN] Problem: Max pizza pieces with N straight cuts.
 * [中文] 題目說明: N 刀直線切披薩，最多可分割的塊數。
 * [EN] Approach: Formula n*(n + 1)/2 + 1 using 64-bit integer.
 * [中文] 思路: 經典直線分割平面公式：n * (n + 1) / 2 + 1。
 * ==========================================================================
 */
#include <stdio.h>

long long solve_uva10079(long long n) {
    return n * (n + 1) / 2 + 1;
}

int main(void) {
    int ok = (solve_uva10079(5) == 16) && (solve_uva10079(10) == 56);
    printf("%s: UVa 10079 - Pizza Cutting\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
