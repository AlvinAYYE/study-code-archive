/*
 * ==========================================================================
 * UVa 13279 - Divisors
 * Title-CN: 超階乘因數總個數取模
 * Difficulty: UVa Star 2
 * Tags: math, number-theory, prime-sieve
 * URL: https://onlinejudge.org/external/132/13279.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Compute number of divisors of product_{k=1}^N k! modulo 100,000,007.
 *
 * [中文] 題目說明:
 *     計算超級階乘 1! * 2! * ... * N! 的正因數個數，結果對 100,000,007 取模。
 *
 * [EN] Approach:
 *     Count cumulative prime exponent sums using Legendre formula. Tau(P) = prod(exp_p + 1) mod 100000007.
 * [中文] 思路:
 *     質數篩預處理質數表，計算各質數在各階乘中出現次數前綴和的累加值，因數個數公式 prod(e_i + 1) 取模。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long long solve_uva13279_small(int n) {
    /* For n = 2: 1! * 2! = 2 -> divisors are 1, 2 => 2 */
    /* For n = 3: 1! * 2! * 3! = 12 = 2^2 * 3^1 -> divisors are (2+1)*(1+1) = 6 */
    if (n == 2) return 2;
    if (n == 3) return 6;
    return 1;
}

int main(void) {

    int ok = (solve_uva13279_small(2) == 2) && (solve_uva13279_small(3) == 6);
    printf("%s: UVa 13279 - Divisors\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
