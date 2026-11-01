/*
 * ==========================================================================
 * UVa 10622 - Perfect P-th Powers
 * Title-CN: 完美 P 次冪
 * Difficulty: Medium
 * Tags: Math, Number Theory, GCD
 * URL: https://onlinejudge.org/external/106/10622.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the largest integer p such that x = b^p for some integer b.
 *
 * [中文] 題目概述:
 *     尋找最大的整數 p 使得 x = b^p（其中 b 為整數）。
 *
 * [EN] Approach:
 *     Factorize |x| into prime powers. p is the gcd of all prime exponents. If x < 0, repeatedly divide p by 2 until it is odd.
 * [中文] 解題思路:
 *     對 |x| 進行質因數分解，各質因數指數的 gcd 即為最大可能 p；若 x 為負數，需將 p 不斷除以 2 直到為奇數。
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

int gcd_int(int a, int b) { return b == 0 ? a : gcd_int(b, a % b); }
int max_power(long long x) {
    int neg = (x < 0);
    if (neg) x = -x;
    int p_gcd = 0;
    for (long long d = 2; d * d <= x; d++) {
        if (x % d == 0) {
            int count = 0;
            while (x % d == 0) { count++; x /= d; }
            p_gcd = (p_gcd == 0 ? count : gcd_int(p_gcd, count));
        }
    }
    if (x > 1) p_gcd = (p_gcd == 0 ? 1 : gcd_int(p_gcd, 1));
    if (neg) {
        while (p_gcd % 2 == 0) p_gcd /= 2;
    }
    return p_gcd;
}

int main(void) {

    int ok = (max_power(17) == 1) && (max_power(1024) == 10) && (max_power(-1024) == 5);
    printf("%s: UVa 10622 - Perfect P-th Powers\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
