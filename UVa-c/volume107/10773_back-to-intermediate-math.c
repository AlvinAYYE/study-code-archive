/*
 * ==========================================================================
 * UVa 10773 - Back to Intermediate Math
 * Title-CN: 渡河垂直路徑與最短時間差
 * Difficulty: UVa Star 1
 * Tags: math, physics
 * URL: https://onlinejudge.org/external/107/10773.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Compare time taken to cross river directly perpendicular to current vs taking shortest time path obliquely.
 *
 * [中文] 題目說明:
 *     計算小船以垂直對岸航行與以最短耗時航行渡河時的時間差距，若水流過急無法垂直渡河則標記無效。
 *
 * [EN] Approach:
 *     Shortest path time t1 = d / sqrt(u^2 - v^2). Fastest path time t2 = d / u. Difference is t1 - t2 (valid if u > v and v > 0).
 * [中文] 思路:
 *     垂直路徑時間 t1 = d / sqrt(u^2 - v^2)，最短時間 t2 = d / u，兩者之差即為所求，若 u <= v 或 v = 0 則無有效時間差。
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

double solve_uva10773(double d, double v, double u) {
    if (v >= u || v == 0.0 || u == 0.0) return -1.0;
    double t1 = d / sqrt(u * u - v * v);
    double t2 = d / u;
    return t1 - t2;
}

int main(void) {

    double diff = solve_uva10773(100, 5, 10);
    int ok = (diff > 0.0 && fabs(diff - 1.547) < 1e-2);
    printf("%s: UVa 10773 - Back to Intermediate Math\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
