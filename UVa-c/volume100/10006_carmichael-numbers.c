/*
 * ==========================================================================
 * UVa 10006 - Carmichael Numbers
 * Title-CN: 卡邁克爾數 (費馬偽質數)
 * Difficulty: UVa Star 2
 * Tags: math, number-theory, modular-exponentiation
 * URL: https://onlinejudge.org/external/100/10006.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Check if composite n is a Carmichael number: for all 1 < a < n, a^n = a (mod n).
 *
 * [中文] 題目說明:
 *     判斷合數 n 是否為卡邁克爾數（對所有 1 < a < n 滿足 a^n ≡ a mod n 的費馬偽質數）。
 *
 * [EN] Approach:
 *     Trial division to ensure n is composite. Fast modular exponentiation to test a^n mod n == a.
 * [中文] 思路:
 *     先確認 n 非質數，再以快速冪逐一檢查是否對所有 a 滿足同餘條件。
 * ==========================================================================
 */
#include <stdio.h>

static long long power_mod(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

static int is_prime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int is_carmichael(int n) {
    if (is_prime(n)) return 0;
    for (int a = 2; a < n; a++) {
        if (power_mod(a, n, n) != a) return 0;
    }
    return 1;
}

int main(void) {
    int ok = is_carmichael(561) && is_carmichael(1105) && !is_carmichael(17) && !is_carmichael(15);
    printf("%s: UVa 10006 - Carmichael Numbers\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
