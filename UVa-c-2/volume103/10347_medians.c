/*
 * ==========================================================================
 * UVa 10347 - Medians
 * Title-CN: 三角形三中線長度反求面積
 * Difficulty: UVa Star 1
 * Tags: geometry, math
 * URL: https://onlinejudge.org/external/103/10347.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given lengths of the three medians of a triangle, calculate the area of the original triangle, or return -1 if impossible.
 *
 * [中文] 題目說明:
 *     給定三角形的三條中線長度，計算該原始三角形的面積；若中線長度無法構成合法三角形則回傳 -1。
 *
 * [EN] Approach:
 *     The area of a triangle formed by its medians is 3/4 the area of the original triangle. Thus Area = (4/3) * Heron(m1, m2, m3).
 * [中文] 思路:
 *     以三中線構成之三角形面積為原三角形面積的 3/4，故原面積 = (4/3) * 海龍公式(m1, m2, m3)。
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

double solve_uva10347(double m1, double m2, double m3) {
    double sm = (m1 + m2 + m3) * 0.5;
    double val = sm * (sm - m1) * (sm - m2) * (sm - m3);
    if (val <= 0.0) return -1.0;
    return (4.0 / 3.0) * sqrt(val);
}

int main(void) {

    double area = solve_uva10347(3.0, 4.0, 5.0);
    int ok = (fabs(area - 8.0) < 1e-4);
    printf("%s: UVa 10347 - Medians\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
