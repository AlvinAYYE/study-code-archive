/*
 * ==========================================================================
 * UVa 332 - Rational Numbers from Repeating Fractions
 * Title-CN: 循環小數化分數
 * Difficulty: Easy
 * Tags: Math, Number Theory, GCD
 * URL: https://onlinejudge.org/external/3/332.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Convert a decimal fraction with k repeating digits and (d - k) non-repeating digits into an irreducible fraction p / q.
 *
 * [中文] 題目說明:
 *     將末尾含 k 位循環節的十進位小數（前含 d-k 位非循環節）化為最簡分數 p / q。
 *
 * [EN] Approach:
 *     Numerator = floor(X * 10^d) - floor(X * 10^(d-k)). Denominator = 10^d - 10^(d-k). If k == 0: X * 10^d / 10^d. Simplify by gcd.
 * [中文] 思路:
 *     分子為乘以 10^d 與乘以 10^(d-k) 的整數部分之差，分母為 10^d - 10^(d-k)（k=0 時分母為 10^d），以 gcd 約分。
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

long long gcd_rn(long long a, long long b) { return b == 0 ? a : gcd_rn(b, a % b); }
void repeating_to_fraction(int j_nonrep, int k_rep, const char *frac_str, long long *num, long long *den) {
    long long full = atoll(frac_str);
    int total_digits = strlen(frac_str);
    if (k_rep == 0) {
        *num = full;
        *den = 1;
        for (int i = 0; i < total_digits; i++) *den *= 10;
    } else {
        long long p1 = full;
        long long p2 = 0;
        int non_rep = total_digits - k_rep;
        char non_buf[20];
        if (non_rep > 0) {
            strncpy(non_buf, frac_str, non_rep);
            non_buf[non_rep] = '\0';
            p2 = atoll(non_buf);
        }
        long long d1 = 1, d2 = 1;
        for (int i = 0; i < total_digits; i++) d1 *= 10;
        for (int i = 0; i < non_rep; i++) d2 *= 10;
        *num = p1 - p2;
        *den = d1 - d2;
    }
    long long g = gcd_rn(*num, *den);
    *num /= g;
    *den /= g;
}

int main(void) {

    long long n, d;
    repeating_to_fraction(0, 1, "3", &n, &d); // 0.(3) = 1/3
    int ok = (n == 1 && d == 3);
    printf("%s: UVa 332 - Rational Numbers from Repeating Fractions\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
