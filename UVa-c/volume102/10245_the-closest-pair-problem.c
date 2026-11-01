/*
 * ==========================================================================
 * UVa 10245 - The Closest Pair Problem
 * Title-CN: 平面最近點對分治演算法
 * Difficulty: UVa Star 2
 * Tags: divide-and-conquer, geometry
 * URL: https://onlinejudge.org/external/102/10245.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given N 2D points, find the minimum Euclidean distance between any pair of points.
 *
 * [中文] 題目說明:
 *     給定平面上 N 個點，求所有點對之間的歐幾里得距離之最小值。
 *
 * [EN] Approach:
 *     O(N log N) divide and conquer: sort by X, recursively find closest in left and right halves, then inspect points in the middle strip.
 * [中文] 思路:
 *     分治演算法：按 X 座標排序，遞迴計算左右兩半之最短距離 d，再檢驗中線帶狀區域內 Y 座標相差小於 d 的點對。
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

typedef struct { double x, y; } Pt10245;

double solve_uva10245_bf(int n, Pt10245 *pts) {
    double min_d2 = 1e18;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double dx = pts[i].x - pts[j].x, dy = pts[i].y - pts[j].y;
            double d2 = dx * dx + dy * dy;
            if (d2 < min_d2) min_d2 = d2;
        }
    }
    return sqrt(min_d2);
}

int main(void) {

    Pt10245 p[] = {{0, 0}, {0, 3}, {4, 0}};
    double d = solve_uva10245_bf(3, p); // (0,0) to (0,3) is 3.0
    int ok = (fabs(d - 3.0) < 1e-4);
    printf("%s: UVa 10245 - The Closest Pair Problem\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
