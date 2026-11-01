/*
 * ==========================================================================
 * UVa 12704 - Little Masters
 * Title-CN: 小大師 (圓內點到圓周最短與最長距離)
 * Difficulty: Easy
 * Tags: Geometry, Math
 * URL: https://onlinejudge.org/external/127/12704.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given a point (x, y) strictly inside a circle of radius r centered at the origin, find the shortest and longest distances to the circle boundary.
 *
 * [中文] 題目說明:
 *     給定以原點為圓心、半徑為 r 的圓內一點 (x, y)，求該點到圓周的最短與最長距離。
 *
 * [EN] Approach:
 *     Distance from origin d = sqrt(x^2 + y^2). Shortest distance = r - d, longest distance = r + d.
 * [中文] 思路:
 *     點到原點距離 d = sqrt(x^2 + y^2)。到圓周的最短距離為 r - d，最長距離為 r + d。
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

void circle_distances(double x, double y, double r, double *d_min, double *d_max) {
    double d = sqrt(x * x + y * y);
    *d_min = r - d;
    *d_max = r + d;
}

int main(void) {

    double mn, mx;
    circle_distances(3.0, 4.0, 10.0, &mn, &mx); // d = 5 -> mn = 5, mx = 15
    int ok = (fabs(mn - 5.0) < 1e-4 && fabs(mx - 15.0) < 1e-4);
    printf("%s: UVa 12704 - Little Masters\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
