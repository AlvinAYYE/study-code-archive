/*
 * ==========================================================================
 * UVa 913 - Joana and the Odd Numbers
 * Title-CN: 奇數金字塔第 N 行末三數之和
 * Difficulty: UVa Star 1
 * Tags: math
 * URL: https://onlinejudge.org/external/9/913.pdf
 * ==========================================================================
 * [EN] Problem:
 *     In pyramid of odd numbers (row 1 has 1, row 2 has 3, row k has 2k-1 odds), sum the last 3 odd numbers of row N.
 *
 * [中文] 題目說明:
 *     在奇數排列成的三角金字塔中 (第 k 行有 2k-1 個奇數)，求第 N 行最後 3 個奇數的總和。
 *
 * [EN] Approach:
 *     Total odds up to row N is M = ((N + 1) / 2)^2. Last odd is 2*M - 1. Sum of last three is 3*(2*M - 1) - 6.
 * [中文] 思路:
 *     等差級數求出到第 N 行為止的奇數總個數 M = ((N+1)/2)^2，該行最後一個奇數為 2M-1，最後三數之和為 3*(2M-1) - 6。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long long solve_uva913(long long n) {
    long long k = (n + 1) / 2;
    long long m = k * k;
    long long last = 2 * m - 1;
    return 3 * last - 6;
}

int main(void) {

    int ok = (solve_uva913(3) == 15) && (solve_uva913(5) == 45);
    printf("%s: UVa 913 - Joana and the Odd Numbers\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
