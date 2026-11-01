/*
 * ==========================================================================
 * UVa 10263 - Railway
 * Title-CN: 鐵路車站選址 (點到折線段最近點)
 * Difficulty: Medium
 * Tags: Geometry, Distance Point to Segment
 * URL: https://onlinejudge.org/external/102/10263.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given point M and a railway broken-line path of N segments, find the point on the railway that is closest to M.
 *
 * [中文] 題目描述:
 *     給定點 M 與一條由 N 段折線構成的鐵路，求鐵路上距離點 M 最近的點坐標。
 *
 * [EN] Approach:
 *     Project M onto each segment AB using dot product: t = dot(AM, AB) / |AB|^2 clamped to [0, 1]. Point P = A + t * AB. Find minimum distance.
 *
 * [中文] 解題思維:
 *     計算點 M 到各線段 AB 的垂直投影參數 t = dot(AM, AB) / |AB|^2，截斷至 [0, 1]，求最近點坐標。
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

void closest_point_on_segment(double px, double py, double ax, double ay, double bx, double by, double *rx, double *ry) {
    double dx = bx - ax, dy = by - ay;
    double len2 = dx * dx + dy * dy;
    if (len2 == 0) { *rx = ax; *ry = ay; return; }
    double t = ((px - ax) * dx + (py - ay) * dy) / len2;
    if (t < 0.0) t = 0.0;
    if (t > 1.0) t = 1.0;
    *rx = ax + t * dx;
    *ry = ay + t * dy;
}

int main(void) {

    double rx, ry;
    closest_point_on_segment(5.0, 5.0, 0.0, 0.0, 10.0, 0.0, &rx, &ry); // project (5,5) onto y=0 from 0 to 10 -> (5,0)
    int ok = (fabs(rx - 5.0) < 1e-4 && fabs(ry - 0.0) < 1e-4);
    printf("%s: UVa 10263 - Railway\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
