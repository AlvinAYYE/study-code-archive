/*
 * ==========================================================================
 * UVa 382 - Perfection
 * Title-CN: 完美數、虧數與盈數判定
 * Difficulty: UVa Star 1
 * Tags: math, number-theory
 * ==========================================================================
 * [EN] Problem: Classify positive integer as PERFECT, DEFICIENT, or ABUNDANT based on sum of proper divisors.
 * [中文] 題目說明: 計算正因數和（不含自身），判定為 PERFECT（相等）、DEFICIENT（小於）或 ABUNDANT（大於）。
 * [EN] Approach: Sum proper divisors up to n/2.
 * [中文] 思路: 遍歷 1 到 n/2 累加真因數之和。
 * ==========================================================================
 */
#include <stdio.h>

const char *solve_uva382(int n) {
    if (n == 1) return "DEFICIENT";
    int sum = 0;
    for (int i = 1; i * 2 <= n; i++) {
        if (n % i == 0) sum += i;
    }
    if (sum == n) return "PERFECT";
    if (sum < n) return "DEFICIENT";
    return "ABUNDANT";
}

int main(void) {
    int ok = (solve_uva382(6)[0] == 'P') && (solve_uva382(15)[0] == 'D') && (solve_uva382(12)[0] == 'A');
    printf("%s: UVa 382 - Perfection\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
