/*
 * ==========================================================================
 * UVa 10302 - Summation of Polynomials
 * Title-CN: 立方和多項式級數求和
 * Difficulty: UVa Star 1
 * Tags: math
 * URL: https://onlinejudge.org/external/103/10302.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Compute the sum of cubes 1^3 + 2^3 + ... + x^3 for a given integer x.
 *
 * [中文] 題目說明:
 *     給定整數 x，計算前 x 個正整數的立方和 1^3 + 2^3 + ... + x^3。
 *
 * [EN] Approach:
 *     Use the closed-form formula: Sum = (x * (x + 1) / 2)^2. Use long long to avoid overflow.
 * [中文] 思路:
 *     使用經典恆等式：1^3 + ... + x^3 = (x*(x+1)/2)^2，以 64 位元整數進行計算防止溢位。
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

long long solve_uva10302(long long x) {
    long long s = x * (x + 1) / 2;
    return s * s;
}

int main(void) {

    int ok = (solve_uva10302(3) == 36 && solve_uva10302(5) == 225);
    printf("%s: UVa 10302 - Summation of Polynomials\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
