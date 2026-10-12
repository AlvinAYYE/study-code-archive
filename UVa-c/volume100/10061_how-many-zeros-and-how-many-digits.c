/*
 * ==========================================================================
 * UVa 10061 - How many zeros and how many digits?
 * Title-CN: N 階乘末尾零個數與 B 進位位數
 * Difficulty: UVa Star 2
 * Tags: math, number-theory, legendre-formula
 * ==========================================================================
 * [EN] Problem: Trailing zeros in base B of N! and total digits in base B of N!.
 * [中文] 題目說明: 求 N! 在 B 進位下的末尾 0 個數與總位數。
 * [EN] Approach: Legendre's formula for prime factor counts, sum logB(i) for digits.
 * [中文] 思路: 質因數分解基底 B，勒讓德定理求各質因數次數取最小值；總位數為 sum log(i)/log(B) + 1。
 * ==========================================================================
 */
#include <stdio.h>
#include <math.h>

static inline int min_val(int a, int b) { return a < b ? a : b; }

int count_zeros(int n, int b) {
    int min_zeros = 1e9;
    int temp_b = b;
    for (int p = 2; p * p <= temp_b; p++) {
        if (temp_b % p == 0) {
            int count_p = 0;
            while (temp_b % p == 0) { count_p++; temp_b /= p; }
            int n_p = 0;
            long long k = p;
            while (k <= n) { n_p += n / k; k *= p; }
            min_zeros = min_val(min_zeros, n_p / count_p);
        }
    }
    if (temp_b > 1) {
        int n_p = 0;
        long long k = temp_b;
        while (k <= n) { n_p += n / k; k *= temp_b; }
        min_zeros = min_val(min_zeros, n_p);
    }
    return min_zeros;
}

int count_digits(int n, int b) {
    double sum = 0;
    for (int i = 1; i <= n; i++) sum += log((double)i);
    sum /= log((double)b);
    return (int)floor(sum + 1e-9) + 1;
}

int main(void) {
    int z = count_zeros(10, 10);
    int d = count_digits(10, 10);
    int ok = (z == 2 && d == 7);
    printf("%s: UVa 10061 - How many zeros and how many digits\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
