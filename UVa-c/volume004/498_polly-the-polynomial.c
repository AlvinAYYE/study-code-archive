/*
 * ==========================================================================
 * UVa 498 - Polly the Polynomial
 * Title-CN: 多項式霍納法則快速求值
 * Difficulty: UVa Star 1
 * Tags: math
 * URL: https://onlinejudge.org/external/4/498.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given polynomial coefficients c_n, c_{n-1}, ..., c_0 and an array of values x, evaluate P(x) at each x using Horner's rule.
 *
 * [中文] 題目說明:
 *     給定多項式係數與若干個整數 x，利用霍納法則 (Horner's rule) 快速求出多項式在各 x 處的函數值 P(x)。
 *
 * [EN] Approach:
 *     Horner's method: res = res * x + c[i] iteratively from highest degree to constant term.
 * [中文] 思路:
 *     霍納計算法：令初始值為最高次係數，每次乘上 x 並加上下一項係數，時間複雜度 O(N)。
 * ==========================================================================
 * UVa Online Judge Submission Template:
 * #include <stdio.h>
 * #include <stdlib.h>
 * #include <string.h>
 * #include <math.h>
 *
 * int main(void) {
 *     // Read input and call logic function
 *     return 0;
 * }
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

long long solve_uva498(int deg, long long *c, long long x) {
    long long res = c[0];
    for (int i = 1; i <= deg; i++) {
        res = res * x + c[i];
    }
    return res;
}

int main(void) {

    long long c[] = {1, -2, 1}; // x^2 - 2x + 1
    long long v = solve_uva498(2, c, 3); // 9 - 6 + 1 = 4
    int ok = (v == 4);
    printf("%s: UVa 498 - Polly the Polynomial\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
