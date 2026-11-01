/*
 * ==========================================================================
 * UVa 11152 - Colourful Flowers
 * Title-CN: 幾何花朵內切圓與外接圓面積差
 * Difficulty: UVa Star 1
 * Tags: geometry, math
 * URL: https://onlinejudge.org/external/111/11152.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Compute area of sunflowers (circumcircle minus triangle), violets (triangle minus incircle), and roses (incircle) for given side lengths a, b, c.
 *
 * [中文] 題目說明:
 *     給定三角形三邊長 a, b, c，計算向日葵黃色區域 (外接圓扣除三角形)、紫羅蘭藍色區域 (三角形扣除內切圓) 與玫瑰紅色區域 (內切圓) 面積。
 *
 * [EN] Approach:
 *     Semiperimeter s = (a+b+c)/2; Heron's formula for area T; incircle radius r = T/s; circumcircle radius R = abc / (4T). Compute circle areas pi*R^2 and pi*r^2.
 * [中文] 思路:
 *     海龍公式求面積 T，內切圓半徑 r = T/s，外接圓半徑 R = abc/(4T)，面積分別為 pi*R^2 - T、T - pi*r^2 與 pi*r^2。
 * ==========================================================================
 * UVa Online Judge Submission Template:
 * #include <stdio.h>
 * #include <stdlib.h>
 * #include <string.h>
 * #include <math.h>
 *
 * int main(void) {
 *     // Read input and call logic function
 *     return 0;
 * }
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

void solve_uva11152(double a, double b, double c, double *sunflower, double *violet, double *rose) {
    double s = (a + b + c) * 0.5;
    double t = sqrt(s * (s - a) * (s - b) * (s - c));
    double pi = 3.141592653589793;
    double r = t / s;
    double R = (a * b * c) / (4.0 * t);
    *rose = pi * r * r;
    *violet = t - *rose;
    *sunflower = pi * R * R - t;
}

int main(void) {

    double sf, vi, ro;
    solve_uva11152(3, 4, 5, &sf, &vi, &ro);
    int ok = (fabs(ro - 3.14159) < 1e-2 && fabs(vi - (6.0 - 3.14159)) < 1e-2);
    printf("%s: UVa 11152 - Colourful Flowers\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
