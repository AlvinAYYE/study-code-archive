/*
 * ==========================================================================
 * UVa 106 - Fermat vs. Pythagoras
 * Title-CN: 費馬對畢氏 (互質畢氏三元數)
 * Difficulty: UVa Star 2
 * Tags: math, number-theory, pythagorean-triples
 * URL: https://onlinejudge.org/external/1/106.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count primitive Pythagorean triples with z <= N, and count numbers <= N not in any triple.
 *
 * [中文] 題目說明:
 *     計算斜邊 z <= N 的本原畢氏三元組數量，以及在 1..N 中未包含在任何畢氏三元組中的整數數量。
 *
 * [EN] Approach:
 *     Generate triples using Euclid formula: x = m^2 - n^2, y = 2mn, z = m^2 + n^2 with gcd(m, n) = 1.
 * [中文] 思路:
 *     利用歐幾里得公式枚舉 m > n，gcd(m, n) == 1 且奇偶互異，統計本原組並標記倍數以計數未使用的數。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

static int gcd_int(int a, int b) { while (b) { int t = b; b = a % b; a = t; } return a; }

void solve_uva106(int n, int *out_prim, int *out_unused) {
    static char used[1000001];
    for (int i = 1; i <= n; i++) used[i] = 0;
    int prim = 0;
    for (int m = 2; m * m <= n; m++) {
        for (int k = 1; k < m; k++) {
            if ((m - k) % 2 == 1 && gcd_int(m, k) == 1) {
                int z = m * m + k * k;
                if (z > n) break;
                int x = m * m - k * k;
                int y = 2 * m * k;
                prim++;
                for (int c = 1; c * z <= n; c++) {
                    used[c * x] = 1; used[c * y] = 1; used[c * z] = 1;
                }
            }
        }
    }
    int unused = 0;
    for (int i = 1; i <= n; i++) if (!used[i]) unused++;
    *out_prim = prim;
    *out_unused = unused;
}

int main(void) {

    int p = 0, u = 0;
    solve_uva106(10, &p, &u);
    int ok = (p == 1 && u == 4);
    printf("%s: UVa 106 - Fermat vs. Pythagoras\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
