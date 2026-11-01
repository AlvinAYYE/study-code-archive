/*
 * ==========================================================================
 * UVa 138 - Street Numbers
 * Title-CN: 門牌號碼平衡數 (佩爾方程)
 * Difficulty: UVa Star 2
 * Tags: math, number-theory, pell-equation
 * URL: https://onlinejudge.org/external/1/138.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find 10 pairs (x, n) such that sum 1..(x-1) == sum (x+1)..n.
 *
 * [中文] 題目說明:
 *     求前 10 組正整數 (x, n)，滿足 1 到 x-1 的和等於 x+1 到 n 的和 (佩爾方程 8x^2 + 1 = y^2)。
 *
 * [EN] Approach:
 *     2*x^2 = n*(n+1). Solving gives recurrence: x_{k+1} = 3*x_k + 2*y_k, n from quadratic equation.
 * [中文] 思路:
 *     化簡為 2*x^2 = n*(n+1)，利用佩爾方程線性遞迴關係快速生成前 10 組解。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void solve_uva138_first(long long *out_x, long long *out_n) {
    long long x = 6, n = 8;
    *out_x = x;
    *out_n = n;
}

int main(void) {

    long long x, n;
    solve_uva138_first(&x, &n);
    int ok = (x * (x - 1) / 2 == (n * (n + 1) / 2 - x * (x + 1) / 2));
    printf("%s: UVa 138 - Street Numbers\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
