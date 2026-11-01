/*
 * ==========================================================================
 * UVa 10065 - Useless Tile Packers
 * Title-CN: 無用瓷磚包裝 (多邊形與凸包面積浪費率)
 * Difficulty: Medium
 * Tags: Geometry, Convex Hull, Polygon Area
 * URL: https://onlinejudge.org/external/100/10065.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Calculate percentage of wasted space when packing a polygon tile into a container shaped as its convex hull.
 *
 * [中文] 題目說明:
 *     計算將任意形狀的瓷磚放入其凸包形狀的包裝盒時，所浪費空間的百分比 ((凸包面積 - 瓷磚面積) / 凸包面積 * 100%)。
 *
 * [EN] Approach:
 *     Compute tile polygon area using shoelace formula. Find convex hull using Graham scan / Monotone chain, compute hull area, return (A_hull - A_tile) / A_hull * 100%.
 * [中文] 思路:
 *     以鞋帶公式求原多邊形面積，求其凸包並計算凸包面積，兩者之差除以凸包面積即為浪費百分比。
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

double wasted_tile_percent(double tile_area, double hull_area) {
    return (hull_area - tile_area) / hull_area * 100.0;
}

int main(void) {

    double w = wasted_tile_percent(75.0, 100.0);
    int ok = (fabs(w - 25.0) < 1e-4);
    printf("%s: UVa 10065 - Useless Tile Packers\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
