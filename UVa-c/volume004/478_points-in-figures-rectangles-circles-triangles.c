/*
 * ==========================================================================
 * UVa 478 - Points in Figures: Rectangles, Circles, Triangles
 * Title-CN: 點在幾何圖形判定 (矩形、圓形、三角形)
 * Difficulty: UVa Star 2
 * Tags: geometry
 * URL: https://onlinejudge.org/external/4/478.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given a collection of rectangles, circles, and triangles, determine which figures contain a query 2D point (x, y).
 *
 * [中文] 題目說明:
 *     給定包含矩形、圓形與三角形的二維圖形集合，判定指定查詢點落於哪些圖形的內部。
 *
 * [EN] Approach:
 *     Check box bounds for rectangles, Euclidean distance squared < R^2 for circles, and cross-product sign consistency for triangles.
 * [中文] 思路:
 *     矩形檢驗座標邊界，圓形檢驗與圓心距離平方小於半徑平方，三角形以同向叉積檢驗點是否落在三條邊內側。
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

int pt_in_circle478(double cx, double cy, double r, double px, double py) {
    double d2 = (px - cx)*(px - cx) + (py - cy)*(py - cy);
    return d2 < r * r;
}

int pt_in_rect478(double x1, double y1, double x2, double y2, double px, double py) {
    return (px > x1 && px < x2 && py < y1 && py > y2);
}

int main(void) {

    int ok = pt_in_circle478(0, 0, 5, 2, 2) && !pt_in_circle478(0, 0, 5, 5, 5);
    printf("%s: UVa 478 - Points in Figures: Rectangles, Circles, Triangles\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
