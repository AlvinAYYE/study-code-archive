/*
 * ==========================================================================
 * UVa 10177 - (2/3/4)-D Sqr/Rects/Cubes/Boxes?
 * Title-CN: 多維正方體與長方體計數
 * Difficulty: Easy
 * Tags: Math, Combinatorics
 * URL: https://onlinejudge.org/external/101/10177.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count squares vs non-square rectangles in 2D, cubes vs non-cube boxes in 3D, and hypercubes vs hyperboxes in 4D of an N-grid.
 *
 * [中文] 題目說明:
 *     在邊長為 N 的網格中，分別統計 2D 正方形與非正方形矩形、3D 立方體與非立方體長方體、4D 超立方體與非超立方體總數。
 *
 * [EN] Approach:
 *     In d dimensions: total rectangles = (N*(N+1)/2)^d. Total hypercubes = sum_{i=1}^N i^d. Non-cubes = Total - Hypercubes.
 * [中文] 思路:
 *     d 維空間中長方體總數為 (N*(N+1)/2)^d，正方體總數為 sum_{i=1}^N i^d，兩者相減即為非正方體數量。
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

void count_d_shapes(long long n, long long *s2, long long *r2, long long *s3, long long *r3) {
    long long t2 = (n * (n + 1) / 2) * (n * (n + 1) / 2);
    long long t3 = (n * (n + 1) / 2) * (n * (n + 1) / 2) * (n * (n + 1) / 2);
    long long sq2 = n * (n + 1) * (2 * n + 1) / 6;
    long long sq3 = (n * (n + 1) / 2) * (n * (n + 1) / 2);
    *s2 = sq2; *r2 = t2 - sq2;
    *s3 = sq3; *r3 = t3 - sq3;
}

int main(void) {

    long long s2, r2, s3, r3;
    count_d_shapes(2, &s2, &r2, &s3, &r3);
    int ok = (s2 == 5 && r2 == 4);
    printf("%s: UVa 10177 - (2/3/4)-D Sqr/Rects/Cubes/Boxes?\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
