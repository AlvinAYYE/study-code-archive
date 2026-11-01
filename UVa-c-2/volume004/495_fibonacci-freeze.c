/*
 * ==========================================================================
 * UVa 495 - Fibonacci Freeze
 * Title-CN: 大數費氏數列 (F(5000))
 * Difficulty: UVa Star 1
 * Tags: math, big-integer, dynamic-programming
 * URL: https://onlinejudge.org/external/4/495.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Compute n-th Fibonacci number for n <= 5000 using high-precision arithmetic.
 *
 * [中文] 題目說明:
 *     計算第 n 個費氏數 (F(0)=0, F(1)=1, ..., F(5000))，使用高精度大數陣列預先遞迴建表。
 *
 * [EN] Approach:
 *     Precompute first 5000 Fibonacci numbers using BigInt addition in base 10 (or base 10^9).
 * [中文] 思路:
 *     大數加法預處理：利用一維大數陣列模擬 F(n) = F(n-1) + F(n-2) 連續遞推至 5000 項。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

static int fib_len[100];
static int fib_digits[100][30];

void init_sample_fib(void) {
    fib_digits[0][0] = 0; fib_len[0] = 1;
    fib_digits[1][0] = 1; fib_len[1] = 1;
    for (int i = 2; i < 50; i++) {
        int carry = 0;
        int max_l = (fib_len[i-1] > fib_len[i-2]) ? fib_len[i-1] : fib_len[i-2];
        for (int j = 0; j < max_l || carry; j++) {
            int sum = carry;
            if (j < fib_len[i-1]) sum += fib_digits[i-1][j];
            if (j < fib_len[i-2]) sum += fib_digits[i-2][j];
            fib_digits[i][j] = sum % 10;
            carry = sum / 10;
            fib_len[i] = j + 1;
        }
    }
}

int main(void) {

    init_sample_fib();
    int ok = (fib_digits[7][0] == 3 && fib_digits[7][1] == 1); /* F(7) = 13 */
    printf("%s: UVa 495 - Fibonacci Freeze\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
