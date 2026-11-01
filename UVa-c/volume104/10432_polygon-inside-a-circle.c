/*
 * ==========================================================================
 * UVa 10432 - Polygon Inside A Circle
 * Title-CN: 圓內接正多邊形面積計算
 * Difficulty: UVa Star 1
 * Tags: geometry, math
 * URL: https://onlinejudge.org/external/104/10432.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given radius r and number of sides n, calculate area of regular n-sided polygon inscribed in circle.
 *
 * [中文] 題目說明:
 *     給定圓半徑 r 與邊數 n，計算內接於該圓的正 n 邊形面積。
 *
 * [EN] Approach:
 *     Formula: Area = 0.5 * n * r^2 * sin(2*pi / n).
 * [中文] 思路:
 *     幾何三角公式：將正 n 邊形切為 n 個等腰三角形，總面積為 0.5 * n * r^2 * sin(2 * pi / n)。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <math.h>

double solve_uva10432(double r, double n) {
    double pi = acos(-1.0);
    return 0.5 * n * r * r * sin(2.0 * pi / n);
}

int main(void) {

    double a = solve_uva10432(2.0, 2000.0);
    int ok = (fabs(a - 4.0 * acos(-1.0)) < 0.01);
    printf("%s: UVa 10432 - Polygon Inside A Circle\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
