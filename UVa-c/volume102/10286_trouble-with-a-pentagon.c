/*
 * ==========================================================================
 * UVa 10286 - Trouble with a Pentagon
 * Title-CN: 正五邊形最大內接正方形邊長三角學
 * Difficulty: UVa Star 1
 * Tags: geometry, math
 * URL: https://onlinejudge.org/external/102/10286.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Calculate the side length of the largest square that can be inscribed inside a regular pentagon of side length F.
 *
 * [中文] 題目說明:
 *     計算可內接於邊長為 F 的正五邊形內部之最大正方形的邊長 (三角函數固定比值)。
 *
 * [EN] Approach:
 *     The side ratio is a constant derived from pentagon interior angles: side = F * sin(108 deg) / sin(63 deg) approx 1.0673956461992414 * F.
 * [中文] 思路:
 *     利用五邊形內角 108 度與正方形角 90 度的正弦定理三角推導：正方形邊長 = F * sin(108°) / sin(63°) ≈ 1.06739565 * F。
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

double solve_uva10286(double f) {
    return f * 1.0673956461992414;
}

int main(void) {

    double s = solve_uva10286(1.0);
    int ok = (fabs(s - 1.0674) < 1e-3);
    printf("%s: UVa 10286 - Trouble with a Pentagon\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
