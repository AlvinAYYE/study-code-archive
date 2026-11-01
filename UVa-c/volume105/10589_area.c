/*
 * ==========================================================================
 * UVa 10589 - Area
 * Title-CN: 四圓交集面積 (蒙地卡羅與解析判定)
 * Difficulty: Easy
 * Tags: Geometry, Math
 * URL: https://onlinejudge.org/external/105/10589.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine if randomly generated points in a square [0, a] x [0, a] fall within the intersection of four circular discs centered at the corners.
 *
 * [中文] 題目說明:
 *     判斷單位正方形 [0, a] x [0, a] 內的隨機點是否位於以四個角為圓心、邊長 a 為半徑的四個圓盤的交集內部。
 *
 * [EN] Approach:
 *     Check if (x - cx)^2 + (y - cy)^2 <= a^2 for all four corners (0,0), (a,0), (0,a), (a,a).
 * [中文] 思路:
 *     驗證點 (x, y) 到四個角落頂點的歐氏距離是否均小於等於 a，即 (x-cx)^2 + (y-cy)^2 <= a^2。
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

bool in_four_circles(double x, double y, double a) {
    double a2 = a * a + 1e-7;
    if (x * x + y * y > a2) return false;
    if ((x - a) * (x - a) + y * y > a2) return false;
    if (x * x + (y - a) * (y - a) > a2) return false;
    if ((x - a) * (x - a) + (y - a) * (y - a) > a2) return false;
    return true;
}

int main(void) {

    int ok = in_four_circles(5.0, 5.0, 10.0); // center is always inside
    printf("%s: UVa 10589 - Area\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
