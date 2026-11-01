/*
 * ==========================================================================
 * UVa 324 - Factorial Frequencies
 * Title-CN: 階乘數字頻率統計
 * Difficulty: UVa Star 1
 * Tags: math, big-integer
 * URL: https://onlinejudge.org/external/3/324.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Compute n! (up to 366!) using high precision and count frequency of each digit 0-9.
 *
 * [中文] 題目說明:
 *     計算大數階乘 n! (最大 366!)，並統計結果中數字 0 到 9 各自出現的次數。
 *
 * [EN] Approach:
 *     BigInt multiplication simulation using base-10 array. Count digits in resulting big integer.
 * [中文] 思路:
 *     以陣列模擬大數高精度乘法，由 1 連乘到 n。最後線性巡訪每一位數累積統計各數字出現頻率。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void solve_uva324(int n, int counts[10]) {
    for (int i = 0; i < 10; i++) counts[i] = 0;
    int digits[1000] = {1};
    int len = 1;
    for (int i = 2; i <= n; i++) {
        int carry = 0;
        for (int j = 0; j < len; j++) {
            int prod = digits[j] * i + carry;
            digits[j] = prod % 10;
            carry = prod / 10;
        }
        while (carry) {
            digits[len++] = carry % 10;
            carry /= 10;
        }
    }
    for (int i = 0; i < len; i++) counts[digits[i]]++;
}

int main(void) {

    int c[10];
    solve_uva324(10, c);
    int ok = (c[0] == 2 && c[8] == 2);
    printf("%s: UVa 324 - Factorial Frequencies\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
