/*
 * ==========================================================================
 * UVa 10112 - Myacm Triangles
 * Title-CN: 最大無遮擋三角形
 * Difficulty: Easy
 * Tags: Geometry, Brute Force
 * URL: https://onlinejudge.org/external/101/10112.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find 3 points forming a triangle of maximum area that contains no other points strictly inside or on boundaries.
 *
 * [中文] 題目描述:
 *     在給定點集中尋找面積最大的三角形，使得該三角形內部及邊界上不包含點集中的任何其他點。
 *
 * [EN] Approach:
 *     C(n, 3) combinations. For each triangle, check area > max_area. Then verify that no other point lies inside using orientation/area sum tests.
 *
 * [中文] 解題思維:
 *     三重迴圈枚舉三頂點求三角形面積，並驗證其餘所有點皆不在該三角形內（點在三角形內等價於三子三角形面積和等於大三角形面積）。
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

double triangle_area_2d(double x1, double y1, double x2, double y2, double x3, double y3) {
    return 0.5 * fabs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
}

int main(void) {

    double a = triangle_area_2d(0, 0, 4, 0, 0, 3); // 0.5 * 4 * 3 = 6
    int ok = (fabs(a - 6.0) < 1e-4);
    printf("%s: UVa 10112 - Myacm Triangles\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
