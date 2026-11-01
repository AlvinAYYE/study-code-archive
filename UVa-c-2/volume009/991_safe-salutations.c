/*
 * ==========================================================================
 * UVa 991 - Safe Salutations
 * Title-CN: 不相交握手問題 (卡特蘭數 Catalan)
 * Difficulty: UVa Star 1
 * Tags: math, combinatorics, catalan-number
 * URL: https://onlinejudge.org/external/9/991.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count ways 2n people around a circular table can shake hands simultaneously in pairs without crossed hands.
 *
 * [中文] 題目說明:
 *     2n 個人圍坐在圓桌旁兩兩握手，要求握手線段互不交叉，求相異握手方案數 (即第 n 個卡特蘭數 C_n)。
 *
 * [EN] Approach:
 *     Catalan numbers: C_0 = 1, C_n = (2*(2n-1) / (n+1)) * C_{n-1}.
 * [中文] 思路:
 *     卡特蘭數經典模型：第 n 個卡特蘭數 C_n = C(2n, n) / (n + 1)，遞推預處理建表。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long long solve_uva991(int n) {
    long long c = 1;
    for (int i = 1; i <= n; i++) {
        c = c * 2 * (2 * i - 1) / (i + 1);
    }
    return c;
}

int main(void) {

    int ok = (solve_uva991(1) == 1) && (solve_uva991(2) == 2) && (solve_uva991(3) == 5);
    printf("%s: UVa 991 - Safe Salutations\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
