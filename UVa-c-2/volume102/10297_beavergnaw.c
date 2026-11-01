/*
 * ==========================================================================
 * UVa 10297 - Beavergnaw
 * Title-CN: 海狸啃木頭
 * Difficulty: Easy
 * Tags: Geometry, Math
 * URL: https://onlinejudge.org/external/102/10297.pdf
 * ==========================================================================
 * [EN] Problem:
 *     A beaver carves volume V out of a cylinder of diameter D and height D. Find diameter d of inner remaining cylinder.
 *
 * [中文] 題目說明:
 *     海狸從直徑與高度皆為 D 的圓柱體中啃掉體積為 V 的木頭，求中間剩餘圓柱的直徑 d。
 *
 * [EN] Approach:
 *     Carved volume V = Total cylinder - Inner cylinder - 2 * cones. Equation simplifies to d^3 = D^3 - 6V / pi.
 * [中文] 思路:
 *     啃咬掉的體積 V = 總體積 - 內部小圓柱 - 兩側圓台。經代數推導可化簡為 d^3 = D^3 - 6V / pi，故 d = (D^3 - 6V / pi)^(1/3)。
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

double beavergnaw_diameter(double D, double V) {
    double pi = 2.0 * acos(0.0);
    double d3 = D * D * D - (6.0 * V / pi);
    return cbrt(d3);
}

int main(void) {

    double d = beavergnaw_diameter(10.0, 250.0);
    int ok = (fabs(d - 8.05) < 0.05);
    printf("%s: UVa 10297 - Beavergnaw\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
