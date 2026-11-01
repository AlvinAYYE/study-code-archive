/*
 * ==========================================================================
 * UVa 412 - Pi
 * Title-CN: 由互質機率估算圓周率 Pi
 * Difficulty: UVa Star 1
 * Tags: math, number-theory, probability
 * URL: https://onlinejudge.org/external/4/412.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given a set of integers, estimate pi using probability of randomly chosen pair being coprime (P = 6 / pi^2).
 *
 * [中文] 題目說明:
 *     給定一組整數，計算任選兩數互質的機率 P，並利用蒙地卡羅數論公式 P = 6 / pi^2 估算圓周率 pi 的近似值。
 *
 * [EN] Approach:
 *     Count all pairs (i, j) with gcd(a[i], a[j]) == 1. Then pi approx = sqrt(6 * total_pairs / coprime_pairs).
 * [中文] 思路:
 *     雙重迴圈枚舉所有數對計算最大公因數，統計互質數對數量，帶入公式 sqrt(6.0 * total / coprime) 求解。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <math.h>

static int gcd_412(int a, int b) { while (b) { int t = b; b = a % b; a = t; } return a; }

double solve_uva412(int n, const int *a) {
    int coprime = 0, total = n * (n - 1) / 2;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (gcd_412(a[i], a[j]) == 1) coprime++;
        }
    }
    if (coprime == 0) return -1.0;
    return sqrt(6.0 * total / coprime);
}

int main(void) {

    int a[5] = {2, 3, 4, 5, 6};
    double res = solve_uva412(5, a);
    int ok = (res > 3.0 && res < 3.5);
    printf("%s: UVa 412 - Pi\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
