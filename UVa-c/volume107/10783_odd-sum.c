/*
 * ==========================================================================
 * UVa 10783 - Odd Sum
 * Title-CN: 奇數之和
 * Difficulty: UVa Star 1 / CPE 49 顆星必考題
 * Tags: math, elementary
 * URL: https://onlinejudge.org/external/107/10783.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Sum all odd numbers between a and b inclusive.
 *
 * [中文] 題目說明:
 *     計算區間 [a, b] 內所有奇數的和。
 *
 * [EN] Approach: Arithmetic loop step by 2.
 * [中文] 思路: 若 a 為偶數則加 1，接著每次遞增 2 累加至 b。
 * ==========================================================================
 */
#include <stdio.h>

int solve_uva10783(int a, int b) {
    if (a % 2 == 0) a++;
    int sum = 0;
    for (int i = a; i <= b; i += 2) {
        sum += i;
    }
    return sum;
}

int main(void) {
    int ok = (solve_uva10783(1, 5) == 9) && (solve_uva10783(3, 5) == 8);
    printf("%s: UVa 10783 - Odd Sum\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
