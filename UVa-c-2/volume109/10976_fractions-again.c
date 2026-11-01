/*
 * ==========================================================================
 * UVa 10976 - Fractions Again?!
 * Title-CN: 分數拆解 (1/k = 1/x + 1/y 埃及分數列舉)
 * Difficulty: UVa Star 1
 * Tags: math, brute-force
 * URL: https://onlinejudge.org/external/109/10976.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find all positive integer pairs x >= y such that 1/k = 1/x + 1/y.
 *
 * [中文] 題目說明:
 *     給定整數 k，求所有滿足 1/k = 1/x + 1/y 且 x >= y 的正整數對 (x, y)。
 *
 * [EN] Approach:
 *     Since x >= y, we have y in [k + 1, 2k]. From 1/x = 1/k - 1/y = (y - k) / (k*y), x = (k*y) / (y - k). Valid if (k*y) % (y - k) == 0.
 * [中文] 思路:
 *     不等式推導：因 x >= y > k，y 的範圍嚴格落在 [k + 1, 2k]。枚舉 y，當 (k*y) % (y - k) == 0 時求出對應整數 x。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva10976_count(int k) {
    int cnt = 0;
    for (int y = k + 1; y <= 2 * k; y++) {
        if ((long long)k * y % (y - k) == 0) cnt++;
    }
    return cnt;
}

int main(void) {

    int ok = (solve_uva10976_count(2) == 2); /* 1/2 = 1/6 + 1/3 = 1/4 + 1/4 */
    printf("%s: UVa 10976 - Fractions Again?!\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
