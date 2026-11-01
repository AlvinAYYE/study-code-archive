/*
 * ==========================================================================
 * UVa 408 - Uniform Generator
 * Title-CN: 均勻隨機產生器 (互質判定 GCD)
 * Difficulty: UVa Star 1
 * Tags: math, number-theory, gcd
 * URL: https://onlinejudge.org/external/4/408.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine if step size STEP and modulus MOD generate all integers 0..MOD-1 via seed = (seed + STEP) % MOD.
 *
 * [中文] 題目說明:
 *     判定線性同餘產生器 step 與 mod 能否生成 0 到 mod-1 的所有整數 (即 gcd(step, mod) == 1 則為 Good Choice)。
 *
 * [EN] Approach:
 *     By number theory, the sequence generates full period iff gcd(step, mod) == 1.
 * [中文] 思路:
 *     由數論同餘理論可知，循環產生完整週期的充分必要條件為 gcd(step, mod) == 1。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

static int gcd_408(int a, int b) {
    while (b) { int t = b; b = a % b; a = t; }
    return a;
}

int solve_uva408(int step, int mod) {
    return (gcd_408(step, mod) == 1);
}

int main(void) {

    int ok = solve_uva408(3, 5) && !solve_uva408(15, 20);
    printf("%s: UVa 408 - Uniform Generator\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
