/*
 * ==========================================================================
 * UVa 10168 - Summation of Four Primes
 * Title-CN: 四質數之和
 * Difficulty: UVa Star 2
 * Tags: math, number-theory, prime
 * ==========================================================================
 * [EN] Problem: Express integer N as the sum of 4 prime numbers.
 * [中文] 題目說明: 將整數 N 表示為四個質數的和（利用哥德巴赫猜想）。
 * [EN] Approach: If N < 8 impossible. If N even: 2 + 2 + Goldbach(N - 4). If N odd: 2 + 3 + Goldbach(N - 5).
 * [中文] 思路: 若 N 為偶數扣除 2+2=4 後對 N-4 拆解為兩質數；奇數扣除 2+3=5 後對 N-5 拆解兩質數。
 * ==========================================================================
 */
#include <stdio.h>

static int is_p(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) if (n % i == 0) return 0;
    return 1;
}

int solve_uva10168(int n, int ans[4]) {
    if (n < 8) return 0;
    if (n % 2 == 0) {
        ans[0] = 2; ans[1] = 2; n -= 4;
    } else {
        ans[0] = 2; ans[1] = 3; n -= 5;
    }
    for (int i = 2; i <= n / 2; i++) {
        if (is_p(i) && is_p(n - i)) {
            ans[2] = i; ans[3] = n - i;
            return 1;
        }
    }
    return 0;
}

int main(void) {
    int ans[4];
    int ok = solve_uva10168(24, ans) && (ans[0] + ans[1] + ans[2] + ans[3] == 24);
    printf("%s: UVa 10168 - Summation of Four Primes\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
