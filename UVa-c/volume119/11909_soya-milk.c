/*
 * ==========================================================================
 * UVa 11909 - Soya Milk
 * Title-CN: 豆漿倒出體積計算
 * Difficulty: Easy
 * Tags: Geometry, Math
 * URL: https://onlinejudge.org/external/119/11909.pdf
 * ==========================================================================
 * [EN] Problem:
 *     A milk carton of size l x w x h is tilted by angle theta. Find the remaining volume of milk in mL.
 *
 * [中文] 題目說明:
 *     長寬高為 l x w x h 的豆漿盒傾斜 theta 度，求盒中剩餘的豆漿體積（毫升）。
 *
 * [EN] Approach:
 *     If tilted water surface cuts the bottom (tan(theta) <= h/l): lost volume is a triangular prism 0.5 * l * (l*tan(theta)) * w. Otherwise, remaining volume is 0.5 * h * (h/tan(theta)) * w.
 * [中文] 思路:
 *     若液面未觸及底面（l * tan(theta) <= h），倒出部分為直角三角柱 0.5 * l^2 * tan(theta) * w；否則剩餘部分為三角柱 0.5 * h^2 / tan(theta) * w。
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

double remaining_soya_milk(double l, double w, double h, double theta_deg) {
    double pi = 2.0 * acos(0.0);
    double rad = theta_deg * pi / 180.0;
    double d = l * tan(rad);
    if (d <= h) {
        double lost = 0.5 * l * d * w;
        return (l * w * h) - lost;
    } else {
        return 0.5 * h * (h / tan(rad)) * w;
    }
}

int main(void) {

    double v = remaining_soya_milk(10.0, 9.0, 10.0, 45.0);
    // d = 10*tan(45)=10 <= 10 -> lost = 0.5*10*10*9 = 450 -> rem = 900 - 450 = 450
    int ok = (fabs(v - 450.0) < 1e-3);
    printf("%s: UVa 11909 - Soya Milk\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
