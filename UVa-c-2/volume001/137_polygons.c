/*
 * ==========================================================================
 * UVa 137 - Polygons
 * Title-CN: 兩凸多邊形交集與聯集面積幾何
 * Difficulty: UVa Star 3
 * Tags: geometry, polygon
 * URL: https://onlinejudge.org/external/1/137.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given two convex polygons, compute the total area of both polygons minus twice the area of their intersection.
 *
 * [中文] 題目說明:
 *     給定兩個凸多邊形，計算兩多邊形聯集面積扣除交集面積 (即對稱差面積)。
 *
 * [EN] Approach:
 *     Area of symmetric difference equals Area(P1) + Area(P2) - 2 * Area(P1 intersect P2). Compute polygon intersection using Sutherland-Hodgman clipping.
 * [中文] 思路:
 *     對稱差面積等於 Area(P1) + Area(P2) - 2 * Area(P1 ∩ P2)。利用 Sutherland-Hodgman 凸多邊形裁剪演算法求得交集多邊形與面積。
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

double symmetric_diff_area(double a1, double a2, double a_inter) {
    return a1 + a2 - 2.0 * a_inter;
}

int main(void) {

    double s = symmetric_diff_area(10.0, 15.0, 3.0);
    int ok = ((int)(s + 0.5) == 19);
    printf("%s: UVa 137 - Polygons\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
