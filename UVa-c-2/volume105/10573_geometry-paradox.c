/*
 * ==========================================================================
 * UVa 10573 - Geometry Paradox
 * Title-CN: 幾何悖論 (雙互切圓環面積)
 * Difficulty: Easy
 * Tags: Geometry, Math
 * URL: https://onlinejudge.org/external/105/10573.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Two mutually tangent circles are tangent to an enclosing circle. Calculate the area between the large circle and the two small circles given either radii r1, r2 or chord length t.
 *
 * [中文] 題目說明:
 *     兩相切小圓內切於大圓，求大圓與兩小圓之間的區域面積（已知兩小圓半徑 r1, r2 或切線弦長 t）。
 *
 * [EN] Approach:
 *     Area = pi * (r1+r2)^2 - pi*r1^2 - pi*r2^2 = 2 * pi * r1 * r2. If given t, 2*r1*r2 = t^2 / 8, so Area = pi * t^2 / 8.
 * [中文] 思路:
 *     兩圓半徑為 r1, r2 時面積為 2 * pi * r1 * r2；若僅給切線長 t 則面積為 pi * t^2 / 8。
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

double geometry_paradox_r(double r1, double r2) {
    double pi = 2.0 * acos(0.0);
    return 2.0 * pi * r1 * r2;
}
double geometry_paradox_t(double t) {
    double pi = 2.0 * acos(0.0);
    return pi * t * t / 8.0;
}

int main(void) {

    double a1 = geometry_paradox_r(10.0, 10.0);
    double a2 = geometry_paradox_t(40.0); // t = 4 * sqrt(r1*r2) = 40 -> same!
    int ok = (fabs(a1 - a2) < 1e-4);
    printf("%s: UVa 10573 - Geometry Paradox\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
