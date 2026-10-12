/*
 * ==========================================================================
 * UVa 12578 - 10:6:2
 * Title-CN: 孟加拉國旗紅綠面積比例
 * Difficulty: UVa Star 1
 * Tags: geometry, math
 * ==========================================================================
 * [EN] Problem: Given flag length L, width is 0.6*L, red circle radius is 0.2*L. Compute red and green areas.
 * [中文] 題目說明: 孟加拉國旗長寬比為 10:6，紅圓半徑為 2（L:0.6L:0.2L）。求紅圓面積與剩餘綠地面積。
 * [EN] Approach: red = PI * r^2, green = L * W - red.
 * [中文] 思路: 紅色面積 = PI * (0.2L)^2，綠色面積 = L * 0.6L - 紅色面積。
 * ==========================================================================
 */
#include <stdio.h>
#include <math.h>

#define PI acos(-1.0)

void solve_uva12578(double l, double *red, double *green) {
    double w = l * 0.6;
    double r = l * 0.2;
    *red = PI * r * r;
    *green = l * w - *red;
}

int main(void) {
    double r, g;
    solve_uva12578(10.0, &r, &g);
    int ok = (fabs(r - 12.57) < 0.01) && (fabs(g - 47.43) < 0.01);
    printf("%s: UVa 12578 - 10 6 2\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
