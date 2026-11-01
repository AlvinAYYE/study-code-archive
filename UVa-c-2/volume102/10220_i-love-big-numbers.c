/*
 * ==========================================================================
 * UVa 10220 - I Love Big Numbers !
 * Title-CN: 大數階乘數字和 (N! 位數加總)
 * Difficulty: UVa Star 1
 * Tags: math, big-integer
 * URL: https://onlinejudge.org/external/102/10220.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Compute the sum of decimal digits of n! for n <= 1000.
 *
 * [中文] 題目說明:
 *     計算大數階乘 n! 的所有十進位數位之和 (n 最大達 1000)。
 *
 * [EN] Approach:
 *     Precompute factorials using BigInt multiplication array. Sum all digits for each n up to 1000.
 * [中文] 思路:
 *     大數高精度乘法連續遞推 1! 至 1000!，每次連乘後加總各位數值存入解答陣列以供 O(1) 查詢。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int sum_digits_factorial(int n) {
    int d[3000] = {1};
    int len = 1;
    for (int i = 2; i <= n; i++) {
        int carry = 0;
        for (int j = 0; j < len; j++) {
            int prod = d[j] * i + carry;
            d[j] = prod % 10;
            carry = prod / 10;
        }
        while (carry) { d[len++] = carry % 10; carry /= 10; }
    }
    int sum = 0;
    for (int i = 0; i < len; i++) sum += d[i];
    return sum;
}

int main(void) {

    int ok = (sum_digits_factorial(3) == 6) && (sum_digits_factorial(4) == 6); /* 3! = 6; 4! = 24 -> 2+4=6 */
    printf("%s: UVa 10220 - I Love Big Numbers !\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
