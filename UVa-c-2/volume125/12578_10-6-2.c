/*
 * ==========================================================================
 * UVa 12578 - 10:6:2
 * Title-CN: 孟加拉國旗紅綠面積幾何計算
 * Difficulty: UVa Star 1
 * Tags: geometry, math
 * URL: https://onlinejudge.org/external/125/12578.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given length L of 10:6 flag with circle radius L/5, compute area of red circle and green rectangle background.
 *
 * [中文] 題目說明:
 *     孟加拉國旗長寬半徑比例為 10:6:2。給定長度 L，寬度為 0.6L，半徑為 0.2L，求紅色圓形面積與綠色背景面積。
 *
 * [EN] Approach:
 *     Radius r = L * 0.2, width W = L * 0.6. Red = pi * r^2. Green = L * W - Red.
 * [中文] 思路:
 *     依固定幾何比例計算：半徑 r = L / 5，寬度 W = 6*L / 10。紅色面積為 pi * r^2，綠色面積為矩形總面積扣除紅圓面積。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <math.h>

void solve_uva12578(double l, double *red, double *green) {
    double pi = acos(-1.0);
    double r = l / 5.0;
    double w = l * 6.0 / 10.0;
    *red = pi * r * r;
    *green = l * w - *red;
}

int main(void) {

    double r, g;
    solve_uva12578(10.0, &r, &g);
    int ok = (fabs(r - 4.0 * acos(-1.0)) < 1e-4);
    printf("%s: UVa 12578 - 10:6:2\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
