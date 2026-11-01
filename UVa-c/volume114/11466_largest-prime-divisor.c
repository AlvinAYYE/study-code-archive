/*
 * ==========================================================================
 * UVa 11466 - Largest Prime Divisor
 * Title-CN: 整數最大質因數 (至少含兩個相異質因數)
 * Difficulty: UVa Star 2
 * Tags: math, number-theory
 * URL: https://onlinejudge.org/external/114/11466.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the largest prime divisor of N, with the requirement that N must have at least two distinct prime divisors; otherwise return -1.
 *
 * [中文] 題目概述:
 *     求整數 N 的最大質因數，且 N 必須具有至少兩個相異質因數；若為質數或質數冪則回傳 -1。
 *
 * [EN] Approach:
 *     Trial division by primes up to sqrt(N). Count distinct prime divisors. If distinct >= 2, return maximum prime divisor, else -1.
 * [中文] 解題思路:
 *     試除法質因數分解：統計相異質因數個數，若個數大於等於 2 則回傳最大質因數，否則依題意回傳 -1。
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

long long solve_uva11466(long long n) {
    if (n < 0) n = -n;
    long long max_p = -1;
    int count = 0;
    for (long long d = 2; d * d <= n; d++) {
        if (n % d == 0) {
            count++;
            max_p = d;
            while (n % d == 0) n /= d;
        }
    }
    if (n > 1) {
        count++;
        max_p = n;
    }
    return (count >= 2) ? max_p : -1;
}

int main(void) {

    int ok = (solve_uva11466(10) == 5 && solve_uva11466(8) == -1 && solve_uva11466(7) == -1);
    printf("%s: UVa 11466 - Largest Prime Divisor\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
