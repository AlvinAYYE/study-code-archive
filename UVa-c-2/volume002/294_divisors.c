/*
 * ==========================================================================
 * UVa 294 - Divisors
 * Title-CN: 區間最多正因數之數
 * Difficulty: UVa Star 1
 * Tags: math, number-theory, prime-factorization
 * URL: https://onlinejudge.org/external/2/294.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the integer between L and U with the maximum number of divisors.
 *
 * [中文] 題目說明:
 *     找出區間 [L, U] 之中正因數數量最多的整數及其因數總數。
 *
 * [EN] Approach:
 *     Precompute primes up to sqrt(10^9) = 31622. Prime factorization gives tau(n) = prod(e_i + 1).
 * [中文] 思路:
 *     質數篩預處理至 31622。對區間內整數質因數分解，利用公式 (e1 + 1)(e2 + 1)... 計算正因數個數求最大值。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int count_divisors(long long n) {
    int cnt = 0;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            cnt++;
            if (i * i != n) cnt++;
        }
    }
    return cnt;
}

void solve_uva294(long long L, long long U, long long *best_num, int *best_cnt) {
    *best_num = L;
    *best_cnt = 0;
    for (long long x = L; x <= U; x++) {
        int c = count_divisors(x);
        if (c > *best_cnt) { *best_cnt = c; *best_num = x; }
    }
}

int main(void) {

    long long num; int cnt;
    solve_uva294(1, 10, &num, &cnt);
    int ok = (num == 6 || num == 8 || num == 10) && (cnt == 4);
    printf("%s: UVa 294 - Divisors\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
