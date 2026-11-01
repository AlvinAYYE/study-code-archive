/*
 * ==========================================================================
 * UVa 10105 - Polynomial Coefficients
 * Title-CN: 多元多項式展開項係數計算
 * Difficulty: UVa Star 1
 * Tags: math, combinatorics
 * URL: https://onlinejudge.org/external/101/10105.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given n and k exponents n_1, n_2, ..., n_k such that sum(n_i) = n, calculate the multinomial coefficient n! / (n_1! * n_2! * ... * n_k!).
 *
 * [中文] 題目說明:
 *     給定總次數 n 與 k 個項的次數 n_1, ..., n_k (滿足總和為 n)，計算多項式定理展開項之係數 n! / (n_1! * ... * n_k!)。
 *
 * [EN] Approach:
 *     Precompute factorials 0! to 13!. Compute n! / prod(n_i!).
 * [中文] 思路:
 *     預先計算 0! 至 13! 的階乘數值，套用多元展開係數公式計算 n! / (n_1! * ... * n_k!)。
 * ==========================================================================
 * UVa Online Judge Submission Template:
 * #include <stdio.h>
 * #include <stdlib.h>
 * #include <string.h>
 * #include <math.h>
 *
 * int main(void) {
 *     // Read input and call logic function
 *     return 0;
 * }
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

long long solve_uva10105(int n, int k, int *powers) {
    long long fact[15];
    fact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i;
    long long ans = fact[n];
    for (int i = 0; i < k; i++) ans /= fact[powers[i]];
    return ans;
}

int main(void) {

    int p[] = {1, 1};
    long long c = solve_uva10105(2, 2, p); // 2! / (1! * 1!) = 2
    int ok = (c == 2);
    printf("%s: UVa 10105 - Polynomial Coefficients\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
