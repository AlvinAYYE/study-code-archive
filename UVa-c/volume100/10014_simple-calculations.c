/*
 * ==========================================================================
 * UVa 10014 - Simple Calculations
 * Title-CN: 簡單計算
 * Difficulty: UVa Star 2
 * Tags: math, linear-algebra
 * URL: https://onlinejudge.org/external/100/10014.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given recurrence a_i = (a_{i-1} + a_{i+1})/2 - c_i, with a_0 and a_{n+1}, find a_1.
 *
 * [中文] 題目說明:
 *     給定遞迴關係 a_i = (a_{i-1} + a_{i+1})/2 - c_i，已知邊界 a_0 與 a_{n+1}，求 a_1。
 *
 * [EN] Approach:
 *     Formula: (n + 1)*a_1 = n*a_0 + a_{n+1} - 2 * sum_{i=1}^n (n + 1 - i)*c_i.
 * [中文] 思路:
 *     透過相鄰項累加消除中間項，推導得出一元一次封閉公式直接解 a_1。
 * ==========================================================================
 */
#include <stdio.h>
#include <math.h>

double solve_uva10014(int n, double a0, double an1, const double *c) {
    double sum = 0.0;
    for (int i = 1; i <= n; i++) {
        sum += (n + 1 - i) * c[i - 1];
    }
    return (n * a0 + an1 - 2.0 * sum) / (n + 1);
}

int main(void) {
    double c[] = {2.0};
    double res = solve_uva10014(1, 50.0, 50.0, c);
    int ok = (fabs(res - 48.0) < 1e-4);
    printf("%s: UVa 10014 - Simple Calculations\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
