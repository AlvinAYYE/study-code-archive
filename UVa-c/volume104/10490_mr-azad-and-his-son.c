/*
 * ==========================================================================
 * UVa 10490 - Mr. Azad and his Son!!!!!
 * Title-CN: 阿扎德先生與他的兒子 (完全數)
 * Difficulty: Easy
 * Tags: Math, Number Theory, Mersenne Primes
 * URL: https://onlinejudge.org/external/104/10490.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine if 2^(p-1) * (2^p - 1) is a perfect number using Euclid-Euler theorem.
 *
 * [中文] 題目概述:
 *     利用歐幾里得-歐拉定理，判斷 2^(p-1) * (2^p - 1) 是否為完全數。
 *
 * [EN] Approach:
 *     If 2^p - 1 is prime, then 2^(p-1) * (2^p - 1) is a perfect number. If p is prime but 2^p - 1 is not, it's not perfect. If p is not prime, neither.
 * [中文] 解題思路:
 *     若 2^p - 1 為質數（梅森質數），則其構成完全數；若 p 是質數但 2^p - 1 不是，則非完全數；若 p 本身不是質數則兩者皆非。
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

bool is_prime_azad(long long x) {
    if (x < 2) return false;
    for (long long d = 2; d * d <= x; d++) if (x % d == 0) return false;
    return true;
}
int azad_status(int p) {
    if (!is_prime_azad(p)) return 0; // given number is NOT prime
    long long m = (1LL << p) - 1;
    if (is_prime_azad(m)) return 1; // Perfect number!
    return 2; // Given number is prime, but, NO perfect number..
}

int main(void) {

    int ok = (azad_status(2) == 1) && (azad_status(3) == 1) && (azad_status(11) == 2);
    printf("%s: UVa 10490 - Mr. Azad and his Son!!!!!\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
