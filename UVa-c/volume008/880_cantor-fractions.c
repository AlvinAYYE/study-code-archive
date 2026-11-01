/*
 * ==========================================================================
 * UVa 880 - Cantor Fractions
 * Title-CN: 康托分數編號 (反對角線二分)
 * Difficulty: Easy
 * Tags: Math, Binary Search
 * URL: https://onlinejudge.org/external/8/880.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the fraction at position n in Cantor's enumeration of fractions along anti-diagonals.
 *
 * [中文] 題目說明:
 *     求康托對角線枚舉序列中第 n 個位置所對應的分數 a / b。
 *
 * [EN] Approach:
 *     Find diagonal k where k*(k+1)/2 >= n. Let offset = n - k*(k-1)/2. The fraction is (k - offset + 1) / offset.
 * [中文] 思路:
 *     以二分或解二次方程求所處對角線編號 k：k*(k+1)/2 >= n，在該對角線上推算分子與分母。
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

void cantor_fraction(long long n, long long *a, long long *b) {
    long long k = (long long)ceil((-1.0 + sqrt(1.0 + 8.0 * (double)n)) / 2.0);
    long long prev = k * (k - 1) / 2;
    long long offset = n - prev;
    *a = k - offset + 1;
    *b = offset;
}

int main(void) {

    long long a, b;
    cantor_fraction(1, &a, &b);
    int ok = (a == 1 && b == 1);
    cantor_fraction(2, &a, &b);
    ok = ok && (a == 2 && b == 1);
    printf("%s: UVa 880 - Cantor Fractions\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
