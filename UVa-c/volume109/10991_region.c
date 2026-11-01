/*
 * ==========================================================================
 * UVa 10991 - Region
 * Title-CN: 三圓相切封閉區域面積
 * Difficulty: Medium
 * Tags: Geometry, Trigonometry, Area
 * URL: https://onlinejudge.org/external/109/10991.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Calculate the area of the region bounded by three pairwise mutually externally tangent circles.
 *
 * [中文] 題目描述:
 *     給定三個兩兩外切圓的半徑 r1, r2, r3，計算由三圓所圍出的中央封閉區域面積。
 *
 * [EN] Approach:
 *     Sides of triangle formed by circle centers are a=r2+r3, b=r1+r3, c=r1+r2. Area = Heron's area - sum of 3 circular sector areas.
 *
 * [中文] 解題思維:
 *     以三圓心形成的三角形邊長為 a=r2+r3, b=r1+r3, c=r1+r2，用海龍公式求三角形面積，扣除三個圓心角對應的扇形面積。
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

double area_between_three_circles(double r1, double r2, double r3) {
    double a = r2 + r3;
    double b = r1 + r3;
    double c = r1 + r2;
    double s = (a + b + c) / 2.0;
    double tri_area = sqrt(s * (s - a) * (s - b) * (s - c));

    double angle1 = acos((b * b + c * c - a * a) / (2.0 * b * c));
    double angle2 = acos((a * a + c * c - b * b) / (2.0 * a * c));
    double angle3 = acos((a * a + b * b - c * c) / (2.0 * a * b));

    double sec1 = 0.5 * angle1 * r1 * r1;
    double sec2 = 0.5 * angle2 * r2 * r2;
    double sec3 = 0.5 * angle3 * r3 * r3;

    return tri_area - (sec1 + sec2 + sec3);
}

int main(void) {

    double a = area_between_three_circles(1.0, 1.0, 1.0);
    // equilateral triangle of side 2: area = sqrt(3), 3 sectors of 60 deg = pi/2
    double expected = sqrt(3.0) - 3.141592653589793 / 2.0;
    int ok = (fabs(a - expected) < 1e-4);
    printf("%s: UVa 10991 - Region\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
