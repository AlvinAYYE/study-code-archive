/*
 * ==========================================================================
 * UVa 1185 - Big Number
 * Title-CN: 大數階乘位數計算 (Kamenetsky公式/對數)
 * Difficulty: Easy
 * Tags: Math, Stirling Approximation, Logarithms
 * URL: https://onlinejudge.org/external/11/1185.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the number of decimal digits in N! for N up to 10,000,000.
 *
 * [中文] 題目說明:
 *     計算 N! 在十進位表示下的位數長度（N 最大達 10,000,000）。
 *
 * [EN] Approach:
 *     Use Kamenetsky's formula: digits = floor(log10(sqrt(2*pi*n)) + n*log10(n/e)) + 1, or precompute sum of log10.
 * [中文] 思路:
 *     利用史特靈/卡梅涅茨基近似公式：位數 = floor(log10(sqrt(2*pi*n)) + n*log10(n/e)) + 1（n <= 3 時直接查表）。
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

int factorial_digit_count(int n) {
    if (n <= 3) return 1;
    double pi = 2.0 * acos(0.0);
    double e = exp(1.0);
    double d = log10(sqrt(2.0 * pi * n)) + n * log10(n / e);
    return (int)floor(d) + 1;
}

int main(void) {

    int ok = (factorial_digit_count(1) == 1) && (factorial_digit_count(5) == 3); // 5! = 120 (3 digits)
    printf("%s: UVa 1185 - Big Number\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
