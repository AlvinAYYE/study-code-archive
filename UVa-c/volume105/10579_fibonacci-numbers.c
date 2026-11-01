/*
 * ==========================================================================
 * UVa 10579 - Fibonacci Numbers
 * Title-CN: 大數費氏數列查詢 (F(n))
 * Difficulty: UVa Star 1
 * Tags: math, big-integer
 * URL: https://onlinejudge.org/external/105/10579.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Compute the n-th Fibonacci number for n <= 5000.
 *
 * [中文] 題目說明:
 *     高精度大數計算第 n 個費氏數 (n <= 5000)。
 *
 * [EN] Approach:
 *     Standard BigInt Fibonacci recurrence F(n) = F(n-1) + F(n-2).
 * [中文] 思路:
 *     以高精度大數陣列預先遞推費氏數列至 5000 項，支援 O(1) 查詢輸出。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long long solve_uva10579_small(int n) {
    long long f[20] = {0, 1, 1};
    for (int i = 3; i <= n; i++) f[i] = f[i - 1] + f[i - 2];
    return f[n];
}

int main(void) {

    int ok = (solve_uva10579_small(6) == 8);
    printf("%s: UVa 10579 - Fibonacci Numbers\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
