/*
 * ==========================================================================
 * UVa 11029 - Leading and Trailing
 * Title-CN: 前三位與後三位數字 (快速冪與對數)
 * Difficulty: Medium
 * Tags: Math, Fast Exponentiation, Logarithms
 * URL: https://onlinejudge.org/external/110/11029.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the first 3 digits and the last 3 digits of n^k.
 *
 * [中文] 題目說明:
 *     求 n^k 的前三位數字與後三位數字。
 *
 * [EN] Approach:
 *     Trailing: fast modular exponentiation n^k mod 1000. Leading: k * log10(n) = int_part + frac_part, leading digits = floor(10^(frac_part + 2)).
 * [中文] 思路:
 *     後三位：快速冪計算 n^k mod 1000。前三位：利用對數取小數部分 frac = fmod(k * log10(n), 1.0)，前三位為 floor(pow(10, frac + 2))。
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

void leading_and_trailing(long long n, long long k, int *lead, int *trail) {
    // Trailing: n^k mod 1000
    long long base = n % 1000, exp = k, res = 1;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % 1000;
        base = (base * base) % 1000;
        exp >>= 1;
    }
    *trail = (int)res;
    // Leading:
    double x = k * log10((double)n);
    double frac = x - floor(x);
    *lead = (int)floor(pow(10.0, frac + 2.0));
}

int main(void) {

    int l, t;
    leading_and_trailing(123456, 1, &l, &t);
    int ok = (l == 123 && t == 456);
    printf("%s: UVa 11029 - Leading and Trailing\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
