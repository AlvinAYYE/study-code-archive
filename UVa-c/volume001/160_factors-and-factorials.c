/*
 * ==========================================================================
 * UVa 160 - Factors and Factorials
 * Title-CN: 階乘的質因數分解
 * Difficulty: UVa Star 1
 * Tags: math, number-theory, prime
 * ==========================================================================
 * [EN] Problem: Express N! as product of prime powers.
 * [中文] 題目說明: 將 N! 表示為質數冪次乘積形式。
 * [EN] Approach: Legendre's formula count = sum floor(N / p^k) for all primes <= N.
 * [中文] 思路: 勒讓德定理直接計算各質數次數：sum(N / p^k)。
 * ==========================================================================
 */
#include <stdio.h>

static const int primes[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

void solve_uva160(int n, int counts[25], int *prime_num) {
    int idx = 0;
    while (idx < 25 && primes[idx] <= n) {
        int p = primes[idx];
        int c = 0;
        int k = p;
        while (k <= n) { c += n / k; k *= p; }
        counts[idx] = c;
        idx++;
    }
    *prime_num = idx;
}

int main(void) {
    int counts[25], num;
    solve_uva160(5, counts, &num); /* 5! = 2^3 * 3^1 * 5^1 */
    int ok = (num == 3 && counts[0] == 3 && counts[1] == 1 && counts[2] == 1);
    printf("%s: UVa 160 - Factors and Factorials\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
