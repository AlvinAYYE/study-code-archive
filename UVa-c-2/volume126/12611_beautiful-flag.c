/*
 * ==========================================================================
 * UVa 12611 - Beautiful Flag
 * Title-CN: 美麗的孟加拉國旗坐標計算
 * Difficulty: Easy
 * Tags: Geometry, Math
 * URL: https://onlinejudge.org/external/126/12611.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given the radius of the red circle in a Bangladesh flag, compute the coordinates of the rectangular flag corners centered relative to the circle.
 *
 * [中文] 題目說明:
 *     給定孟加拉國旗中紅色圓的半徑 R，計算國旗四個頂點的相對坐標（圓心位於原點 (0, 0)）。
 *
 * [EN] Approach:
 *     Dimensions: Length L = 5*R, Width W = 3*R. Circle center is at 45% of length from left: left = -0.45*L = -2.25*R, right = 0.55*L = 2.75*R, y = +/- 1.5*R.
 * [中文] 思路:
 *     依國旗比例：長度 L = 5*R，寬度 W = 3*R。圓心距左側 45%，故左 x = -2.25*R，右 x = 2.75*R，上 y = 1.5*R，下 y = -1.5*R。
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

void flag_corners(int r, int *x1, int *y1, int *x2, int *y2, int *x3, int *y3, int *x4, int *y4) {
    int left = -45 * r / 20;  // -2.25 * r
    int right = 55 * r / 20;  // 2.75 * r
    int half_w = 30 * r / 20; // 1.5 * r
    *x1 = left;  *y1 = half_w;  // top-left
    *x2 = right; *y2 = half_w;  // top-right
    *x3 = right; *y3 = -half_w; // bottom-right
    *x4 = left;  *y4 = -half_w; // bottom-left
}

int main(void) {

    int x1, y1, x2, y2, x3, y3, x4, y4;
    flag_corners(20, &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
    int ok = (x1 == -45 && y1 == 30 && x2 == 55 && y2 == 30);
    printf("%s: UVa 12611 - Beautiful Flag\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
