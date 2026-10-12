/*
 * ==========================================================================
 * UVa 10242 - Fourth Point !!
 * Title-CN: 平行四邊形的第四點
 * Difficulty: UVa Star 1 / CPE 49 顆星必考題
 * Tags: geometry, math
 * URL: https://onlinejudge.org/external/102/10242.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given two contiguous sides of a parallelogram (4 endpoints where 2 coincide),
 *     find the fourth point.
 *
 * [中文] 題目說明:
 *     給定平行四邊形的相鄰兩邊（共 4 個端點坐標，其中必有兩個端點重合為共同頂點）。
 *     求平行四邊形的第四個頂點坐標。
 *
 * [EN] Approach:
 *     Identify common vertex C and two endpoints A, B. Fourth vertex D = A + B - C.
 * [中文] 思路:
 *     找出重複的公共頂點 C 與另外兩端點 A、B。平行四邊形第四點坐標為 A + B - C。
 * ==========================================================================
 */
#include <stdio.h>
#include <math.h>

void solve_uva10242(double x1, double y1, double x2, double y2,
                     double x3, double y3, double x4, double y4,
                     double *rx, double *ry) {
    if (x1 == x3 && y1 == y3) { *rx = x2 + x4 - x1; *ry = y2 + y4 - y1; }
    else if (x1 == x4 && y1 == y4) { *rx = x2 + x3 - x1; *ry = y2 + y3 - y1; }
    else if (x2 == x3 && y2 == y3) { *rx = x1 + x4 - x2; *ry = y1 + y4 - y2; }
    else { *rx = x1 + x3 - x2; *ry = y1 + y3 - y2; }
}

int main(void) {
    double rx, ry;
    solve_uva10242(0, 0, 1, 0, 1, 0, 1, 1, &rx, &ry);
    int ok = (fabs(rx - 0.0) < 1e-4 && fabs(ry - 1.0) < 1e-4);
    printf("%s: UVa 10242 - Fourth Point !!\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
