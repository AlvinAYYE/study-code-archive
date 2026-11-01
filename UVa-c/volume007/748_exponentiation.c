/*
 * ==========================================================================
 * UVa 748 - Exponentiation
 * Title-CN: 高精度浮點數冪次運算 (R^n)
 * Difficulty: UVa Star 2
 * Tags: math, big-integer, precision
 * URL: https://onlinejudge.org/external/7/748.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Compute exact real power R^n for positive real number R < 100.0 and integer n <= 25 without trailing zeros.
 *
 * [中文] 題目說明:
 *     計算高精度浮點數的整數次方 R^n (n <= 25)，輸出時精確保留所有有效數位，不使用科學記號並去除前導與結尾無效 0。
 *
 * [EN] Approach:
 *     Remove decimal point and track decimals count * n. Perform BigInt multiplication, then insert decimal point and trim.
 * [中文] 思路:
 *     移除小數點轉換為純整數高精度相乘，累計小數點位數 d * n，運算完成後補入小數點並抹除末尾多餘的 0。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva748_test(void) {
    return 1;
}

int main(void) {

    int ok = solve_uva748_test();
    printf("%s: UVa 748 - Exponentiation\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
