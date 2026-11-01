/*
 * ==========================================================================
 * UVa 10195 - The Knights Of The Round Table
 * Title-CN: 圓桌騎士最大內切圓半徑
 * Difficulty: UVa Star 1
 * Tags: geometry, math
 * URL: https://onlinejudge.org/external/101/10195.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the radius of the largest circular table (inscribed circle) that can fit inside a triangular room with side lengths a, b, c.
 *
 * [中文] 題目說明:
 *     計算可置入三邊長為 a, b, c 的三角形大廳內之最大圓形會議桌 (內切圓) 半徑。
 *
 * [EN] Approach:
 *     Radius r = Area / semiperimeter s. Area via Heron's formula sqrt(s*(s-a)*(s-b)*(s-c)). If s == 0, r = 0.
 * [中文] 思路:
 *     利用海龍公式計算三角形面積 Area = sqrt(s(s-a)(s-b)(s-c))，內切圓半徑 r = Area / s。
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

double solve_uva10195(double a, double b, double c) {
    if (a <= 0 || b <= 0 || c <= 0) return 0.0;
    double s = (a + b + c) * 0.5;
    double area_sq = s * (s - a) * (s - b) * (s - c);
    if (area_sq <= 0) return 0.0;
    return sqrt(area_sq) / s;
}

int main(void) {

    double r = solve_uva10195(12.0, 12.0, 8.0);
    int ok = (r > 0.0 && fabs(r - 2.8284) < 1e-2);
    printf("%s: UVa 10195 - The Knights Of The Round Table\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
