/*
 * ==========================================================================
 * UVa 10179 - Irreducable Basic Fractions
 * Title-CN: 不可約真分數與歐拉函數
 * Difficulty: UVa Star 2
 * Tags: math, number-theory
 * URL: https://onlinejudge.org/external/101/10179.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Compute the number of irreducible proper fractions with denominator n, which equals Euler's totient phi(n).
 *
 * [中文] 題目說明:
 *     計算分母為 n 且分子小於 n 的不可約最簡真分數個數，即歐拉函數 phi(n)。
 *
 * [EN] Approach:
 *     Euler's totient formula: phi(n) = n * product_{p|n} (1 - 1/p).
 * [中文] 思路:
 *     以試除法求出 n 的相異質因數 p，套用歐拉公式 phi(n) = n * prod(1 - 1/p)。
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

long long solve_uva10179(long long n) {
    long long res = n;
    for (long long p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            while (n % p == 0) n /= p;
            res -= res / p;
        }
    }
    if (n > 1) res -= res / n;
    return res;
}

int main(void) {

    int ok = (solve_uva10179(12) == 4 && solve_uva10179(1) == 1);
    printf("%s: UVa 10179 - Irreducable Basic Fractions\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
