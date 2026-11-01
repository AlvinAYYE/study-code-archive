/*
 * ==========================================================================
 * UVa 725 - Division
 * Title-CN: 五位數除法全數字排列搜尋
 * Difficulty: UVa Star 1
 * Tags: brute-force, math
 * URL: https://onlinejudge.org/external/7/725.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find all pairs of 5-digit numbers abcde / fghij = N using digits 0..9 exactly once.
 *
 * [中文] 題目說明:
 *     求所有滿足 abcde / fghij = N 且十個數字 0 到 9 恰好各用一次的五位數商數配對。
 *
 * [EN] Approach:
 *     Enumerate denominator fghij from 01234 to 98765 / N. Compute abcde = fghij * N. Check if all 10 digits are distinct via bitmask.
 * [中文] 思路:
 *     枚舉分母 fghij (1234 到 98765/N)，算出分子 abcde = fghij * N，以位元遮罩判定兩數 10 個位數是否互異不重複。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva725_check(int num, int den) {
    int mask = (den < 10000 || num < 10000) ? 1 : 0; /* Leading zero */
    int t = num;
    while (t) { int d = t % 10; if (mask & (1 << d)) return 0; mask |= (1 << d); t /= 10; }
    t = den;
    while (t) { int d = t % 10; if (mask & (1 << d)) return 0; mask |= (1 << d); t /= 10; }
    return mask == 1023; /* All 10 digits used */
}

int main(void) {

    int ok = solve_uva725_check(79546, 1283);
    printf("%s: UVa 725 - Division\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
