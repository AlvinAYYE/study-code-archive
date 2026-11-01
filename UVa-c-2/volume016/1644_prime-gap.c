/*
 * ==========================================================================
 * UVa 1644 - Prime Gap
 * Title-CN: 質數間隙長度
 * Difficulty: Easy
 * Tags: Math, Prime, Sieve
 * URL: https://onlinejudge.org/external/16/1644.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given composite number k, find length of prime gap containing k (difference between smallest prime > k and largest prime < k). If k is prime, gap is 0.
 *
 * [中文] 題目描述:
 *     給定合數 k，求包含 k 的質數間隙長度（即大於 k 的最小質數減去小於 k 的最大質數；若 k 本身為質數則間隙為 0）。
 *
 * [EN] Approach:
 *     Sieve primes up to 1,300,000. If is_prime[k] return 0; else find adjacent primes p1 < k < p2 and return p2 - p1.
 *
 * [中文] 解題思維:
 *     質數篩預處理，若 k 為質數返回 0；否則向兩側掃描找到小於 k 的最大質數與大於 k 的最小質數，差值即為間隙長度。
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

bool is_p_gap(int x) {
    if (x < 2) return false;
    for (int d = 2; d * d <= x; d++) if (x % d == 0) return false;
    return true;
}
int prime_gap(int k) {
    if (is_p_gap(k)) return 0;
    int p1 = k - 1, p2 = k + 1;
    while (!is_p_gap(p1)) p1--;
    while (!is_p_gap(p2)) p2++;
    return p2 - p1;
}

int main(void) {

    int ok = (prime_gap(10) == 4) && (prime_gap(11) == 0); // 7 to 11 gap is 4
    printf("%s: UVa 1644 - Prime Gap\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
