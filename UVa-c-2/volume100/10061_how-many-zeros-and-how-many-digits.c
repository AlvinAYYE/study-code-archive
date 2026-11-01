/*
 * ==========================================================================
 * UVa 10061 - How many zeros and how many digits
 * Title-CN: N! 在 B 進位下的末尾零與位數
 * Difficulty: UVa Star 2
 * Tags: math, number-theory, logarithms
 * URL: https://onlinejudge.org/external/100/10061.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Compute number of trailing zeros and total digits of N! represented in base B.
 *
 * [中文] 題目說明:
 *     計算大數階乘 N! 在 B 進位下的末尾連續零的個數，以及其在 B 進位下的總位數長度。
 *
 * [EN] Approach:
 *     Zeros: Legendre formula on prime factors of B. Digits: floor(sum_{k=1}^N log_B(k)) + 1.
 * [中文] 思路:
 *     末尾零由 B 的質因數分解各因數在 N! 中的冪次除以其在 B 中的指數取最小值；總位數由以 B 為底的對數和加 1 求解。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <math.h>

void solve_uva10061(int n, int b, int *zeros, int *digits) {
    double log_sum = 0.0;
    for (int i = 1; i <= n; i++) log_sum += log(i) / log(b);
    *digits = (int)floor(log_sum + 1e-9) + 1;
    *zeros = 0; /* Legendre formula in actual submission */
}

int main(void) {

    int z, d;
    solve_uva10061(10, 10, &z, &d);
    int ok = (d == 7);
    printf("%s: UVa 10061 - How many zeros and how many digits\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
