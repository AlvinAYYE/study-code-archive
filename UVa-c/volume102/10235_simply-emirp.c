/*
 * ==========================================================================
 * UVa 10235 - Simply Emirp
 * Title-CN: 反轉質數
 * Difficulty: UVa Star 1 / CPE 49 顆星必考題
 * Tags: math, number-theory, prime
 * URL: https://onlinejudge.org/external/102/10235.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Check if N is not prime, prime, or emirp (prime whose reverse is a different prime).
 *
 * [中文] 題目說明:
 *     判斷整數 N 是非質數、普通質數還是 Emirp（反轉後也是不同質數）。
 *
 * [EN] Approach: Trial division prime check and digit reversal.
 * [中文] 思路: 寫 is_prime() 檢查自身與反轉數。
 * ==========================================================================
 */
#include <stdio.h>

static int is_prime(long long n) {
    if (n < 2) return 0;
    if (n == 2 || n == 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return 0;
    }
    return 1;
}

static long long rev(long long n) {
    long long r = 0;
    while (n) { r = r * 10 + n % 10; n /= 10; }
    return r;
}

int solve_uva10235(long long n) {
    if (!is_prime(n)) return 0; /* not prime */
    long long r = rev(n);
    if (r != n && is_prime(r)) return 2; /* emirp */
    return 1; /* prime */
}

int main(void) {
    int ok = (solve_uva10235(17) == 2) && (solve_uva10235(19) == 1) && (solve_uva10235(4) == 0);
    printf("%s: UVa 10235 - Simply Emirp\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
