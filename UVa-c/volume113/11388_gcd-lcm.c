/*
 * ==========================================================================
 * UVa 11388 - GCD LCM
 * Title-CN: 已知最大公因數與最小公倍數反求二數
 * Difficulty: UVa Star 1
 * Tags: math, number-theory
 * URL: https://onlinejudge.org/external/113/11388.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given G and L, find two positive integers a <= b such that gcd(a, b) = G and lcm(a, b) = L.
 *
 * [中文] 題目說明:
 *     已知兩整數的 gcd 為 G、lcm 為 L，求滿足條件的最小 a 與相應的 b (若無解輸出 -1)。
 *
 * [EN] Approach:
 *     Solution exists iff L % G == 0. If so, a = G and b = L is always a valid minimal solution.
 * [中文] 思路:
 *     數論性質：解存在的充分必要條件為 L 可被 G 整除。若整除，直接取 a = G 且 b = L 即為最優解，否則無解。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva11388(int g, int l, int *a, int *b) {
    if (l % g != 0) return 0;
    *a = g;
    *b = l;
    return 1;
}

int main(void) {

    int a, b;
    int ok = solve_uva11388(12, 24, &a, &b) && (a == 12 && b == 24);
    printf("%s: UVa 11388 - GCD LCM\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
