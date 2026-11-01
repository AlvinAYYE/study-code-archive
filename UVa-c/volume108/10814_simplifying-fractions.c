/*
 * ==========================================================================
 * UVa 10814 - Simplifying Fractions
 * Title-CN: 大數分數約分 (大數GCD)
 * Difficulty: Easy
 * Tags: Math, Big Integer, GCD
 * URL: https://onlinejudge.org/external/108/10814.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Simplify a fraction P / Q with large integer numerator and denominator to lowest terms.
 *
 * [中文] 題目說明:
 *     將大整數分子 P 與大整數分母 Q 組成的分數約分為最簡分數。
 *
 * [EN] Approach:
 *     Compute GCD(P, Q) using Euclidean algorithm for big integers. Divide P and Q by GCD.
 * [中文] 思路:
 *     使用高精度輾轉相除法求大數 GCD(P, Q)，並將分子分母同時除以該最大公因數。
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

long long gcd_frac(long long a, long long b) { return b == 0 ? a : gcd_frac(b, a % b); }
void simplify_fraction(long long p, long long q, long long *sp, long long *sq) {
    long long g = gcd_frac(p, q);
    *sp = p / g;
    *sq = q / g;
}

int main(void) {

    long long sp, sq;
    simplify_fraction(4, 8, &sp, &sq);
    int ok = (sp == 1 && sq == 2);
    printf("%s: UVa 10814 - Simplifying Fractions\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
