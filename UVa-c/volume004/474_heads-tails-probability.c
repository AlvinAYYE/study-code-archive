/*
 * ==========================================================================
 * UVa 474 - Heads / Tails Probability
 * Title-CN: 連續拋硬幣機率 (科學記號表示)
 * Difficulty: Easy
 * Tags: Math, Logarithms
 * URL: https://onlinejudge.org/external/4/474.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Calculate 2^(-n) in scientific notation: 2^(-n) = a * 10^(-b) where 1 <= a < 10.
 *
 * [中文] 題目說明:
 *     將拋擲 n 次硬幣均為正面的機率 2^(-n) 表示為 a * 10^(-b) 的科學記號形式。
 *
 * [EN] Approach:
 *     Let x = -n * log10(2). Then b = floor(-x) + 1 = ceil(n * log10(2)), a = 10^(x + b).
 * [中文] 思路:
 *     取對數 x = -n * log10(2)，則指數 b = ceil(n * log10(2))，係數 a = 10^(x + b)。
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

void heads_tails_prob(int n, double *a, int *b) {
    double log10_2 = log10(2.0);
    double x = n * log10_2;
    *b = (int)ceil(x);
    *a = pow(10.0, *b - x);
    if (*a >= 10.0) { *a /= 10.0; (*b)--; }
}

int main(void) {

    double a; int b;
    heads_tails_prob(6, &a, &b); // 2^-6 = 1/64 = 0.015625 = 1.562e-2
    int ok = (b == 2 && fabs(a - 1.562) < 0.01);
    printf("%s: UVa 474 - Heads / Tails Probability\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
