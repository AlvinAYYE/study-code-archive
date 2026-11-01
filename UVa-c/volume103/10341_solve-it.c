/*
 * ==========================================================================
 * UVa 10341 - Solve It
 * Title-CN: 微積分方程數值求根 (二分搜尋法)
 * Difficulty: UVa Star 2
 * Tags: binary-search, math
 * URL: https://onlinejudge.org/external/103/10341.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find solution x in [0, 1] for p*e^-x + q*sin(x) + r*cos(x) + s*tan(x) + t*x^2 + u = 0.
 *
 * [中文] 題目說明:
 *     在 [0, 1] 區間求解連續非遞增函數 f(x) = 0 的實數根 (二分搜尋法迭代精確到 4 位小數)。
 *
 * [EN] Approach:
 *     Bisection method: evaluate f(x). Since f(x) is monotonically decreasing in [0, 1], bisect 80 times.
 * [中文] 思路:
 *     因函數在 [0, 1] 區間單調遞減，檢驗 f(0) 與 f(1) 是否異號，若有根則執行 80 次二分逼近求得精確解。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <math.h>

double f_10341(double p, double q, double r, double s, double t, double u, double x) {
    return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

int solve_uva10341(double p, double q, double r, double s, double t, double u, double *ans) {
    double f0 = f_10341(p, q, r, s, t, u, 0.0);
    double f1 = f_10341(p, q, r, s, t, u, 1.0);
    if (f0 * f1 > 0.0) return 0; /* No solution */
    double low = 0.0, high = 1.0;
    for (int iter = 0; iter < 50; iter++) {
        double mid = (low + high) / 2.0;
        if (f_10341(p, q, r, s, t, u, mid) > 0.0) low = mid;
        else high = mid;
    }
    *ans = (low + high) / 2.0;
    return 1;
}

int main(void) {

    double sol;
    int has = solve_uva10341(0, 0, 0, 0, -2, 1, &sol); /* -2 x^2 + 1 = 0 -> x = sqrt(0.5) */
    int ok = has && (fabs(sol - 0.7071) < 0.001);
    printf("%s: UVa 10341 - Solve It\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
