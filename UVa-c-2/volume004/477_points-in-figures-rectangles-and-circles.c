/*
 * ==========================================================================
 * UVa 477 - Points in Figures: Rectangles and Circles
 * Title-CN: 點在矩形與圓形內部判定
 * Difficulty: UVa Star 1
 * Tags: geometry
 * URL: https://onlinejudge.org/external/4/477.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine whether query points fall strictly inside rectangles or circles.
 *
 * [中文] 題目說明:
 *     給定矩形與圓形圖形集合，判定點是否嚴格落在各圖形內部 (圓形使用距離平方判定)。
 *
 * [EN] Approach:
 *     For rectangle: bounding box check. For circle: (px - cx)^2 + (py - cy)^2 < r^2.
 * [中文] 思路:
 *     矩形檢查座標區間；圓形計算點與圓心的歐幾里得距離平方是否小於半徑平方。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int in_circle_477(double px, double py, double cx, double cy, double r) {
    double dx = px - cx, dy = py - cy;
    return (dx * dx + dy * dy < r * r);
}

int main(void) {

    int ok = in_circle_477(1.0, 1.0, 0.0, 0.0, 2.0) && !in_circle_477(3.0, 3.0, 0.0, 0.0, 2.0);
    printf("%s: UVa 477 - Points in Figures: Rectangles and Circles\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
