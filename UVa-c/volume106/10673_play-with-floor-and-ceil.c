/*
 * ==========================================================================
 * UVa 10673 - Play with Floor and Ceil
 * Title-CN: 天花板與地板整數線性組合
 * Difficulty: UVa Star 1
 * Tags: math
 * URL: https://onlinejudge.org/external/106/10673.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given x and k, find integers p and q such that p * floor(x / k) + q * ceil(x / k) = x.
 *
 * [中文] 題目概述:
 *     給定正整數 x 與 k，求一組整數解 (p, q) 滿足 p * floor(x / k) + q * ceil(x / k) = x。
 *
 * [EN] Approach:
 *     Let a = floor(x/k), b = ceil(x/k). If a == b, p = 0, q = k. Otherwise rem = x % k, take p = k - rem, q = rem.
 * [中文] 解題思路:
 *     令 a = floor(x/k), b = ceil(x/k)。若 a == b 則 p = 0, q = k；否則令 rem = x % k，解為 p = k - rem, q = rem。
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

void solve_uva10673(long long x, long long k, long long *p, long long *q) {
    long long rem = x % k;
    if (rem == 0) {
        *p = 0;
        *q = k;
    } else {
        *p = k - rem;
        *q = rem;
    }
}

int main(void) {

    long long p, q;
    solve_uva10673(10, 3, &p, &q); // floor=3, ceil=4 -> p=2, q=1: 2*3 + 1*4 = 10
    int ok = (p == 2 && q == 1);
    printf("%s: UVa 10673 - Play with Floor and Ceil\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
