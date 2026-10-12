/*
 * ==========================================================================
 * UVa 13185 - DPD Numbers
 * Title-CN: 完全數、虧數與盈數分類
 * Difficulty: UVa Star 1
 * Tags: math, number-theory
 * ==========================================================================
 * [EN] Problem: Classify N as deficient, perfect, or abundant based on sum of proper divisors.
 * [中文] 題目說明: 真因數和分類：deficient（小於 N）、perfect（等於 N）、abundant（大於 N）。
 * [EN] Approach: Sum proper divisors up to N/2.
 * [中文] 思路: 遍歷因數求和比對。
 * ==========================================================================
 */
#include <stdio.h>

const char *solve_uva13185(int n) {
    int sum = 0;
    for (int i = 1; i * 2 <= n; i++) if (n % i == 0) sum += i;
    if (sum == n) return "perfect";
    if (sum < n) return "deficient";
    return "abundant";
}

int main(void) {
    int ok = (solve_uva13185(6)[0] == 'p') && (solve_uva13185(12)[0] == 'a');
    printf("%s: UVa 13185 - DPD Numbers\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
