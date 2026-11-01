/*
 * ==========================================================================
 * UVa 190 - Circle Through Three Points
 * Title-CN: 平面不共線三點外接圓方程式
 * Difficulty: UVa Star 2
 * Tags: geometry, math
 * URL: https://onlinejudge.org/external/1/190.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given three non-collinear 2D points, calculate the circumscribed circle and format its equation in both standard (x-h)^2+(y-k)^2=r^2 and general forms.
 *
 * [中文] 題目說明:
 *     給定平面上不共線之三點，計算其外接圓圓心 (h, k) 與半徑 r，並輸出標準式與一般式圓方程式。
 *
 * [EN] Approach:
 *     Find intersection of perpendicular bisectors of segments AB and BC to determine center (h, k), then r = distance to A. Expand general equation.
 * [中文] 思路:
 *     求兩線段中垂線之交點確定外接圓圓心 (h, k)，半徑 r 為圓心到任意頂點之距離，代入並展開成一般式 x^2+y^2+cx+dy+e=0。
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

void circumcircle(double x1, double y1, double x2, double y2, double x3, double y3, double *h, double *k, double *r) {
    double d = 2.0 * (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
    double p1 = x1 * x1 + y1 * y1;
    double p2 = x2 * x2 + y2 * y2;
    double p3 = x3 * x3 + y3 * y3;
    *h = (p1 * (y2 - y3) + p2 * (y3 - y1) + p3 * (y1 - y2)) / d;
    *k = (p1 * (x3 - x2) + p2 * (x1 - x3) + p3 * (x2 - x1)) / d;
    *r = sqrt((x1 - *h) * (x1 - *h) + (y1 - *k) * (y1 - *k));
}

int main(void) {

    double h, k, r;
    circumcircle(0, 1, 1, 0, -1, 0, &h, &k, &r);
    int ok = (fabs(h) < 1e-6 && fabs(k) < 1e-6 && fabs(r - 1.0) < 1e-6);
    printf("%s: UVa 190 - Circle Through Three Points\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
