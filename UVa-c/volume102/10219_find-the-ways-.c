/*
 * ==========================================================================
 * UVa 10219 - Find the ways !
 * Title-CN: 尋找路徑數
 * Difficulty: UVa Star 1
 * Tags: math, combinatorics
 * ==========================================================================
 * [EN] Problem: Compute number of digits in C(n, k).
 * [中文] 題目說明: 計算組合數 C(n, k) 的十進位總位數。
 * [EN] Approach: Sum log10((n - i + 1) / i) for i = 1..k. Output floor(sum) + 1.
 * [中文] 思路: 對 C(n, k) 拆解項取常用對數 log10 累加後取下高斯加 1。
 * ==========================================================================
 */
#include <stdio.h>
#include <math.h>

long long solve_uva10219(long long n, long long k) {
    if (k > n - k) k = n - k;
    double log_sum = 0.0;
    for (long long i = 1; i <= k; i++) {
        log_sum += log10((double)(n - i + 1)) - log10((double)i);
    }
    return (long long)floor(log_sum) + 1;
}

int main(void) {
    int ok = (solve_uva10219(10, 5) == 3); /* C(10, 5) = 252 (3 digits) */
    printf("%s: UVa 10219 - Find the ways !\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
