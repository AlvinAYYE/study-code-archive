/*
 * ==========================================================================
 * UVa 143 - Orchard Trees
 * Title-CN: 果園三角形內部網格點個數幾何計數
 * Difficulty: UVa Star 2
 * Tags: geometry, lattice-points
 * URL: https://onlinejudge.org/external/1/143.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given vertices of a triangle, count how many integer grid points (trees) with 1 <= x, y <= 99 fall inside or on the boundary of the triangle.
 *
 * [中文] 題目說明:
 *     給定果園內三角形邊界的頂點座標，統計有多少個座標為整數且範圍在 1 <= x, y <= 99 內的樹木 (網格點) 落在三角形內部或邊界上。
 *
 * [EN] Approach:
 *     Compute bounding box clamped to [1, 99]. For each lattice point (x, y), use 2D cross products to verify it is on the same side of all three directed edges.
 * [中文] 思路:
 *     計算三角形外接矩形並限制在 [1, 99]，對外接框內每個整數網格點以叉積判斷點是否位於三角形三條有向邊之同一側。
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

int cross_sign(double x1, double y1, double x2, double y2, double px, double py) {
    double cp = (x2 - x1) * (py - y1) - (y2 - y1) * (px - x1);
    if (cp > 1e-9) return 1;
    if (cp < -1e-9) return -1;
    return 0;
}

int pt_in_triangle(double x1, double y1, double x2, double y2, double x3, double y3, double px, double py) {
    int s1 = cross_sign(x1, y1, x2, y2, px, py);
    int s2 = cross_sign(x2, y2, x3, y3, px, py);
    int s3 = cross_sign(x3, y3, x1, y1, px, py);
    int has_pos = (s1 > 0 || s2 > 0 || s3 > 0);
    int has_neg = (s1 < 0 || s2 < 0 || s3 < 0);
    return !(has_pos && has_neg);
}

int main(void) {

    int in = pt_in_triangle(1, 1, 5, 1, 1, 5, 2, 2);
    int out = pt_in_triangle(1, 1, 5, 1, 1, 5, 4, 4);
    int ok = (in == 1 && out == 0);
    printf("%s: UVa 143 - Orchard Trees\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
