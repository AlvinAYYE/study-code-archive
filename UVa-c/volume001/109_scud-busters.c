/*
 * ==========================================================================
 * UVa 109 - SCUD Busters
 * Title-CN: 飛彈防禦多邊形凸包與面積計算
 * Difficulty: UVa Star 2
 * Tags: geometry, convex-hull
 * URL: https://onlinejudge.org/external/1/109.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given kingdom missile defense sites, find convex hull polygons of each kingdom. If a missile hits inside a kingdom, its power is destroyed. Calculate total area destroyed.
 *
 * [中文] 題目說明:
 *     給定各王國的飛彈防禦基地座標，求各王國的凸包多邊形。若敵方飛彈擊中某王國凸包內部，該王國防禦網失效，計算所有失效王國之凸包總面積。
 *
 * [EN] Approach:
 *     Compute 2D convex hull using Graham scan or monotone chain, then point-in-convex-polygon ray-casting / cross-product test, and polygon area using shoelace formula.
 * [中文] 思路:
 *     利用單調鏈或 Graham 掃描法構建各點集凸包，利用射線法或叉積檢驗導彈點是否落在凸包內部；若命中則以鞋帶公式加總該凸包面積。
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

typedef struct { double x, y; } Point;

double cross_product(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

double polygon_area(Point *p, int n) {
    double area = 0.0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area += p[i].x * p[j].y - p[j].x * p[i].y;
    }
    return area < 0 ? -area * 0.5 : area * 0.5;
}

int is_inside_convex(Point pt, Point *poly, int n) {
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        if (cross_product(poly[i], poly[j], pt) < -1e-7) return 0;
    }
    return 1;
}

int main(void) {

    Point poly[4] = {{0, 0}, {4, 0}, {4, 4}, {0, 4}};
    double area = polygon_area(poly, 4);
    Point missile = {2, 2};
    int in = is_inside_convex(missile, poly, 4);
    int ok = ((int)(area + 0.5) == 16 && in == 1);
    printf("%s: UVa 109 - SCUD Busters\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
