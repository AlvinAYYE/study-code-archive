/*
 * ==========================================================================
 * UVa 460 - Overlapping Rectangles
 * Title-CN: 重疊矩形面積計算
 * Difficulty: Easy
 * Tags: Geometry
 * URL: https://onlinejudge.org/external/4/460.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given two axis-aligned rectangles, determine if their intersection is a valid rectangle with positive area, and find its coordinates.
 *
 * [中文] 題目說明:
 *     給定兩個與坐標軸平行的矩形，判斷其交集是否為具有正面積的合法矩形，並求其左下與右上座標。
 *
 * [EN] Approach:
 *     Intersection: x_ll = max(x1_ll, x2_ll), y_ll = max(y1_ll, y2_ll), x_ur = min(x1_ur, x2_ur), y_ur = min(y1_ur, y2_ur). Area positive if x_ll < x_ur and y_ll < y_ur.
 * [中文] 思路:
 *     交集矩形邊界為左下座標取 max，右上座標取 min；若 x_ll < x_ur 且 y_ll < y_ur 則存在重疊矩形。
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

bool rect_intersection(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int *rx1, int *ry1, int *rx2, int *ry2) {
    *rx1 = (x1 > x3 ? x1 : x3);
    *ry1 = (y1 > y3 ? y1 : y3);
    *rx2 = (x2 < x4 ? x2 : x4);
    *ry2 = (y2 < y4 ? y2 : y4);
    return (*rx1 < *rx2 && *ry1 < *ry2);
}

int main(void) {

    int rx1, ry1, rx2, ry2;
    bool ok = rect_intersection(0, 0, 10, 10, 5, 5, 15, 15, &rx1, &ry1, &rx2, &ry2);
    ok = ok && (rx1 == 5 && ry1 == 5 && rx2 == 10 && ry2 == 10);
    printf("%s: UVa 460 - Overlapping Rectangles\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
