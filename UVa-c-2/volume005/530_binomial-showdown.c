/*
 * ==========================================================================
 * UVa 530 - Binomial Showdown
 * Title-CN: 二項式係數精準計算
 * Difficulty: UVa Star 1
 * Tags: math, combinatorics
 * ==========================================================================
 * [EN] Problem: Compute combination C(n, k) fitting within 32-bit unsigned int without overflow during multiplication.
 * [中文] 題目說明: 計算組合數 C(n, k)，乘除交替防止中途溢位。
 * [EN] Approach: ans = ans * (n - i + 1) / i for i in 1..k where k = min(k, n-k).
 * [中文] 思路: k = min(k, n-k)，依序邊乘邊除保證每步皆能整除且不溢位。
 * ==========================================================================
 */
#include <stdio.h>

unsigned long long solve_uva530(unsigned long long n, unsigned long long k) {
    if (k > n - k) k = n - k;
    unsigned long long ans = 1;
    for (unsigned long long i = 1; i <= k; i++) {
        ans = ans * (n - i + 1) / i;
    }
    return ans;
}

int main(void) {
    int ok = (solve_uva530(4, 2) == 6) && (solve_uva530(10, 5) == 252);
    printf("%s: UVa 530 - Binomial Showdown\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
