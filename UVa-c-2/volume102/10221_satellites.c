/*
 * ==========================================================================
 * UVa 10221 - Satellites
 * Title-CN: 人造衛星
 * Difficulty: UVa Star 1 / CPE 49 顆星必考題
 * Tags: geometry, math, trigonometry
 * URL: https://onlinejudge.org/external/102/10221.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given distance s and angle a, find arc distance and chord distance.
 *
 * [中文] 題目說明:
 *     計算軌道高度 s 與夾角 a 下，兩衛星的軌道弧長與直線弦長。
 *
 * [EN] Approach:
 *     R = 6440 + s; angle normalized to <= 180 deg; arc = R * theta, chord = 2 * R * sin(theta / 2).
 * [中文] 思路: 幾何公式推導：弧長 = r * 弧度；弦長 = 2 * r * sin(弧度 / 2)。
 * ==========================================================================
 */
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6440.0

void solve_uva10221(double s, double a, int is_min, double *arc, double *chord) {
    double r = EARTH_RADIUS + s;
    if (is_min) a /= 60.0;
    while (a > 360.0) a -= 360.0;
    if (a > 180.0) a = 360.0 - a;

    double rad = a * PI / 180.0;
    *arc = r * rad;
    *chord = 2.0 * r * sin(rad / 2.0);
}

int main(void) {
    double arc, chord;
    solve_uva10221(500.0, 30.0, 0, &arc, &chord);
    int ok = (fabs(arc - 3633.7755) < 0.1) && (fabs(chord - 3592.4087) < 0.1);
    printf("%s: UVa 10221 - Satellites\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
