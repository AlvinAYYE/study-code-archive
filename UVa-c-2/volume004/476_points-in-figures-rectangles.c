/*
 * ==========================================================================
 * UVa 476 - Points in Figures: Rectangles
 * Title-CN: 點在矩形內部幾何判定
 * Difficulty: UVa Star 1
 * Tags: geometry
 * URL: https://onlinejudge.org/external/4/476.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given up to 10 rectangles, determine which rectangles contain given query points (strictly inside, not on border).
 *
 * [中文] 題目說明:
 *     給定最多 10 個矩形，判定輸入的各點嚴格位於哪些矩形內部 (不包含邊界)。
 *
 * [EN] Approach:
 *     Bounding box check: x1 < px < x2 and y2 < py < y1.
 * [中文] 思路:
 *     直接幾何條件判斷：px 介於左上角與右下角的 x 座標之間，py 介於兩者 y 座標之間。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int in_rect_476(double px, double py, double x1, double y1, double x2, double y2) {
    return (px > x1 && px < x2 && py > y2 && py < y1);
}

int main(void) {

    int ok = in_rect_476(1.5, 1.5, 0.0, 2.0, 2.0, 0.0) && !in_rect_476(0.0, 0.0, 0.0, 2.0, 2.0, 0.0);
    printf("%s: UVa 476 - Points in Figures: Rectangles\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
