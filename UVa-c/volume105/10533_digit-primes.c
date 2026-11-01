/*
 * ==========================================================================
 * UVa 10533 - Digit Primes
 * Title-CN: 數位質數區間計數 (Digit Primes 篩法前綴和)
 * Difficulty: UVa Star 2
 * Tags: math, prime-sieve, prefix-sum
 * URL: https://onlinejudge.org/external/105/10533.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count digit primes in [t1, t2] (primes whose sum of digits is also prime) up to 1,000,000.
 *
 * [中文] 題目說明:
 *     求區間 [t1, t2] 內數位質數的數量 (即本身為質數且其十進位各位數之和亦為質數，上限 100 萬)。
 *
 * [EN] Approach:
 *     Linear sieve up to 10^6. Flag numbers where both x and sum_digits(x) are prime. Precompute prefix sums for O(1) query.
 * [中文] 思路:
 *     質數篩預處理至 100 萬，標記本身與數位和皆為質數的數，預處理前綴和達成 O(1) 區間查詢。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int sum_digits_10533(int n) {
    int s = 0;
    while (n) { s += n % 10; n /= 10; }
    return s;
}

int is_prime_small(int n) {
    if (n < 2) return 0;
    for (int d = 2; d * d <= n; d++) if (n % d == 0) return 0;
    return 1;
}

int is_digit_prime_10533(int n) {
    return is_prime_small(n) && is_prime_small(sum_digits_10533(n));
}

int main(void) {

    int ok = is_digit_prime_10533(23) && !is_digit_prime_10533(13);
    printf("%s: UVa 10533 - Digit Primes\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
