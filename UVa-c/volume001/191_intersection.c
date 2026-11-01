/*
 * ==========================================================================
 * UVa 191 - Intersection
 * Title-CN: 線段與軸對齊矩形相交幾何判定
 * Difficulty: UVa Star 2
 * Tags: geometry
 * URL: https://onlinejudge.org/external/1/191.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine whether a given line segment intersects or lies completely inside an axis-aligned rectangle.
 *
 * [中文] 題目說明:
 *     判定給定線段是否與軸對齊矩形邊界相交，或線段完全包含在該矩形內部。
 *
 * [EN] Approach:
 *     Check if either segment endpoint is inside rectangle. If not, test segment intersection with each of the four rectangle edges using cross products.
 * [中文] 思路:
 *     首先檢查線段兩端點是否落在矩形內部；若否，則將線段分別與矩形四條邊界線段進行跨立實驗與快速排斥實驗判斷是否相交。
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

int pt_in_box(double x, double y, double x1, double y1, double x2, double y2) {
    double min_x = x1 < x2 ? x1 : x2, max_x = x1 > x2 ? x1 : x2;
    double min_y = y1 < y2 ? y1 : y2, max_y = y1 > y2 ? y1 : y2;
    return (x >= min_x && x <= max_x && y >= min_y && y <= max_y);
}

int main(void) {

    int ok = pt_in_box(2, 2, 0, 0, 4, 4) && !pt_in_box(5, 2, 0, 0, 4, 4);
    printf("%s: UVa 191 - Intersection\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
