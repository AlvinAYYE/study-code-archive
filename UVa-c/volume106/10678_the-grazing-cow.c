/*
 * ==========================================================================
 * UVa 10678 - The Grazing Cow
 * Title-CN: 吃草的牛橢圓幾何面積計算
 * Difficulty: UVa Star 1
 * Tags: geometry, math
 * URL: https://onlinejudge.org/external/106/10678.pdf
 * ==========================================================================
 * [EN] Problem:
 *     A cow is tethered to a rope of length L tied between two posts distance D apart. Calculate the total grazing area (an ellipse).
 *
 * [中文] 題目概述:
 *     母牛被繩子拴在相距 D 的兩根木樁之間，繩長為 L，求母牛能吃草的最大活動範圍面積 (橢圓形面積)。
 *
 * [EN] Approach:
 *     Foci distance 2c = D, major axis 2a = L, minor axis b = sqrt(a^2 - c^2). Ellipse area = pi * a * b.
 * [中文] 解題思路:
 *     兩木樁為橢圓焦點 2c = D，長軸 2a = L，短軸半長 b = sqrt(a^2 - c^2)，橢圓面積公式為 pi * a * b。
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

double solve_uva10678(double d, double l) {
    double a = l * 0.5;
    double c = d * 0.5;
    double b = sqrt(a * a - c * c);
    double pi = 2.0 * acos(0.0);
    return pi * a * b;
}

int main(void) {

    double area = solve_uva10678(10.0, 10.0); // circle when d=0 or line when l=d -> 0
    double a2 = solve_uva10678(6.0, 10.0); // a=5, c=3, b=4 -> pi*20 = 62.8318
    int ok = (fabs(a2 - 62.8318) < 1e-2);
    printf("%s: UVa 10678 - The Grazing Cow\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
