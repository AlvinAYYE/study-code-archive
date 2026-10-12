/*
 * ==========================================================================
 * UVa 438 - The Circumference of the Circle
 * Title-CN: 三角形外接圓周長
 * Difficulty: UVa Star 1
 * Tags: geometry, math
 * ==========================================================================
 * [EN] Problem: Find circumference of circle passing through 3 non-collinear points.
 * [中文] 題目說明: 給定不共線三點座標，求通過此三點的外接圓周長。
 * [EN] Approach: R = a*b*c / (4*Area) via Heron's formula. Circumference = 2*PI*R.
 * [中文] 思路: 海龍公式求三角形面積，外接圓半徑 R = a*b*c / (4*Area)，周長 = 2*PI*R。
 * ==========================================================================
 */
#include <stdio.h>
#include <math.h>

#define PI 3.141592653589793

double solve_uva438(double x1, double y1, double x2, double y2, double x3, double y3) {
    double a = hypot(x1 - x2, y1 - y2);
    double b = hypot(x2 - x3, y2 - y3);
    double c = hypot(x3 - x1, y3 - y1);
    double s = (a + b + c) / 2.0;
    double area = sqrt(s * (s - a) * (s - b) * (s - c));
    double r = (a * b * c) / (4.0 * area);
    return 2.0 * PI * r;
}

int main(void) {
    double circ = solve_uva438(0, 0, 2, 0, 1, 1);
    int ok = (circ > 0.0);
    printf("%s: UVa 438 - The Circumference of the Circle\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
