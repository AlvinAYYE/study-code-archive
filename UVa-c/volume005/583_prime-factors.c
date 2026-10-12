/*
 * ==========================================================================
 * UVa 583 - Prime Factors
 * Title-CN: 整數質因數分解輸出
 * Difficulty: UVa Star 1
 * Tags: math, number-theory, prime
 * ==========================================================================
 * [EN] Problem: Factorize integer into prime factors format: N = f1 x f2 x ... (include -1 if negative).
 * [中文] 題目說明: 將整數質因數分解輸出（負數需先輸出 -1）。
 * [EN] Approach: Trial division with primes up to sqrt(2^31) = 46340.
 * [中文] 思路: 試除法提取所有質因數。
 * ==========================================================================
 */
#include <stdio.h>

int factorize(long long n, long long *factors) {
    int cnt = 0;
    if (n < 0) { factors[cnt++] = -1; n = -n; }
    for (long long d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            factors[cnt++] = d;
            n /= d;
        }
    }
    if (n > 1) factors[cnt++] = n;
    return cnt;
}

int main(void) {
    long long f[32];
    int c = factorize(-190, f);
    int ok = (c == 4 && f[0] == -1 && f[1] == 2 && f[2] == 5 && f[3] == 19);
    printf("%s: UVa 583 - Prime Factors\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
