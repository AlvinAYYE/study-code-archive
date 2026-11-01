/*
 * ==========================================================================
 * UVa 10083 - Division
 * Title-CN: 指針數整除檢驗
 * Difficulty: UVa Star 2
 * Tags: math, number-theory
 * ==========================================================================
 * [EN] Problem: Check if (t^a - 1)/(t^b - 1) is integer.
 * [中文] 題目說明: 檢查 (t^a - 1)/(t^b - 1) 是否整除。
 * [EN] Approach: Must have t >= 2, a % b == 0, and digit bound (a - b)*log10(t) < 100.
 * [中文] 思路: 數學整除性條件為 a % b == 0，並檢查長度。
 * ==========================================================================
 */
#include <stdio.h>
#include <math.h>

int solve_uva10083(int t, int a, int b) {
    if (t == 1) return 0;
    if (a % b != 0) return 0;
    if ((a - b) * log10(t) > 99.0) return -1; /* too many digits */
    return 1;
}

int main(void) {
    int ok = (solve_uva10083(2, 4, 2) == 1) && (solve_uva10083(2, 5, 2) == 0);
    printf("%s: UVa 10083 - Division\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
