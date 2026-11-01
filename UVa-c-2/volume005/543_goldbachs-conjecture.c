/*
 * ==========================================================================
 * UVa 543 - Goldbach's Conjecture
 * Title-CN: 哥德巴赫猜想
 * Difficulty: UVa Star 1
 * Tags: math, number-theory, prime
 * ==========================================================================
 * [EN] Problem: Express even integer n > 4 as sum of two odd primes a + b with b - a maximized.
 * [中文] 題目說明: 將偶數 n 拆解為兩奇質數之和 a + b，使差值 b - a 最大。
 * [EN] Approach: Sieve of Eratosthenes up to 1,000,000. Loop odd prime a, check is_prime[n - a].
 * [中文] 思路: 埃氏篩法建立百萬質數表，枚舉最小奇質數 a 驗證 n - a 是否為質數。
 * ==========================================================================
 */
#include <stdio.h>

static int is_prime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) if (n % i == 0) return 0;
    return 1;
}

int solve_uva543(int n, int *a, int *b) {
    for (int i = 3; i <= n / 2; i += 2) {
        if (is_prime(i) && is_prime(n - i)) {
            *a = i; *b = n - i;
            return 1;
        }
    }
    return 0;
}

int main(void) {
    int a, b;
    int ok = solve_uva543(8, &a, &b) && (a == 3 && b == 5);
    printf("%s: UVa 543 - Goldbachs Conjecture\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
