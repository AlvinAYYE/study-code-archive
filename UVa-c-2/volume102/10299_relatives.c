/*
 * ==========================================================================
 * UVa 10299 - Relatives
 * Title-CN: 親戚整數歐拉互質個數
 * Difficulty: UVa Star 2
 * Tags: math, number-theory
 * URL: https://onlinejudge.org/external/102/10299.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given integer N, count positive integers less than N that are coprime to N (Euler's totient function phi(N), with phi(1) = 0).
 *
 * [中文] 題目說明:
 *     給定整數 N，計算小於 N 且與 N 互質之正整數個數 (歐拉函數 phi(N)，特別規定 N=1 時回傳 0)。
 *
 * [EN] Approach:
 *     Euler's totient function phi(n) = n * prod(1 - 1/p) for all prime factors p|n. Special case n=1 gives 0.
 * [中文] 思路:
 *     套用歐拉函數求互質個數，質因數分解試除至 sqrt(n)，特例 n=1 時依題目規範回傳 0。
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

long long solve_uva10299(long long n) {
    if (n == 1) return 0;
    long long ans = n;
    for (long long p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            while (n % p == 0) n /= p;
            ans -= ans / p;
        }
    }
    if (n > 1) ans -= ans / n;
    return ans;
}

int main(void) {

    int ok = (solve_uva10299(1) == 0 && solve_uva10299(7) == 6 && solve_uva10299(12) == 4);
    printf("%s: UVa 10299 - Relatives\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
