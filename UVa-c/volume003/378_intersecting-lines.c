/*
 * ==========================================================================
 * UVa 378 - Intersecting Lines
 * Title-CN: 直線相交判斷與交點計算
 * Difficulty: UVa Star 2
 * Tags: geometry, math, linear-equations
 * URL: https://onlinejudge.org/external/3/378.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given two 2D lines defined by points, determine if they are identical (LINE), parallel (NONE), or intersect (POINT x y).
 *
 * [中文] 題目說明:
 *     給定二維平面上的兩條直線，判定兩線是否重合 (LINE)、平行 (NONE) 或相交於單一點 (POINT x y)。
 *
 * [EN] Approach:
 *     Cross product of direction vectors to check parallelism. If parallel, cross product with offset vector checks collinearity.
 * [中文] 思路:
 *     以直線一般式 A x + B y = C 求解克拉瑪法則，外積為 0 則平行；若常數項成比例則重合，否則求出唯一交點座標。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <math.h>

int solve_uva378(double x1, double y1, double x2, double y2,
                 double x3, double y3, double x4, double y4,
                 double *ix, double *iy) {
    double a1 = y2 - y1, b1 = x1 - x2, c1 = a1 * x1 + b1 * y1;
    double a2 = y4 - y3, b2 = x3 - x4, c2 = a2 * x3 + b2 * y3;
    double det = a1 * b2 - a2 * b1;
    if (fabs(det) < 1e-9) {
        if (fabs(a1 * c2 - a2 * c1) < 1e-9 && fabs(b1 * c2 - b2 * c1) < 1e-9) return 1;
        return 0;
    }
    *ix = (b2 * c1 - b1 * c2) / det;
    *iy = (a1 * c2 - a2 * c1) / det;
    return 2;
}

int main(void) {

    double ix, iy;
    int state = solve_uva378(0, 0, 4, 4, 0, 4, 4, 0, &ix, &iy);
    int ok = (state == 2 && fabs(ix - 2.0) < 1e-4 && fabs(iy - 2.0) < 1e-4);
    printf("%s: UVa 378 - Intersecting Lines\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
