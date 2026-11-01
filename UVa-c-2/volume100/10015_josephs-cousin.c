/*
 * ==========================================================================
 * UVa 10015 - Joseph's Cousin
 * Title-CN: 約瑟夫的表弟
 * Difficulty: UVa Star 2
 * Tags: math, simulation, josephus
 * URL: https://onlinejudge.org/external/100/10015.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Josephus problem where the elimination step size at round i is the i-th prime number.
 *
 * [中文] 題目說明:
 *     約瑟夫問題變形：第 i 輪淘汰時，數到第 i 個質數的人出局。求最後倖存的人。
 *
 * [EN] Approach:
 *     Precompute primes using Sieve of Eratosthenes. DP state transition:
 *     f(i) = (f(i - 1) + prime[round]) % i.
 * [中文] 思路:
 *     質數篩法預處理質數表。動態規劃逆推約瑟夫環位置：pos = (pos + prime[k]) % len。
 * ==========================================================================
 */
#include <stdio.h>

static int primes[3505];
static int prime_cnt = 0;

static void init_primes() {
    int is_p[40000];
    for (int i = 0; i < 40000; i++) is_p[i] = 1;
    for (int p = 2; p < 40000 && prime_cnt < 3501; p++) {
        if (is_p[p]) {
            primes[prime_cnt++] = p;
            for (int i = p * 2; i < 40000; i += p) is_p[i] = 0;
        }
    }
}

int solve_uva10015(int n) {
    if (prime_cnt == 0) init_primes();
    int pos = 0; /* 0-indexed survivor in group of 1 */
    for (int i = 2; i <= n; i++) {
        pos = (pos + primes[n - i]) % i;
    }
    return pos + 1; /* 1-indexed */
}

int main(void) {
    init_primes();
    int res6 = solve_uva10015(6);
    int ok = (res6 == 4);
    printf("%s: UVa 10015 - Josephs Cousin\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
