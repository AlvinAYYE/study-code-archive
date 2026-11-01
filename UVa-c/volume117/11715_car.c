/*
 * ==========================================================================
 * UVa 11715 - Car
 * Title-CN: 等加速度直線運動物理運動學公式
 * Difficulty: UVa Star 1
 * Tags: physics, math
 * URL: https://onlinejudge.org/external/117/11715.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Compute missing kinematic quantities given 3 out of 5 variables (u, v, t, a, s) under constant acceleration.
 *
 * [中文] 題目說明:
 *     在等加速度直線運動中，已知初速 u、末速 v、時間 t、加速度 a、位移 s 中的三項，求出其餘兩項未知量。
 *
 * [EN] Approach:
 *     Apply standard equations: v = u + at, s = (u + v)/2 * t, v^2 = u^2 + 2as.
 * [中文] 思路:
 *     依據題意代入等加速度運動學四公式分別求解位移與時間等相應物理量。
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

void solve_uva11715(int type, double p1, double p2, double p3, double *ans1, double *ans2) {
    if (type == 1) { // u, v, t -> s, a
        *ans1 = (p1 + p2) * 0.5 * p3;
        *ans2 = (p2 - p1) / p3;
    } else if (type == 2) { // u, v, a -> s, t
        *ans1 = (p2 * p2 - p1 * p1) / (2.0 * p3);
        *ans2 = (p2 - p1) / p3;
    }
}

int main(void) {

    double s, a;
    solve_uva11715(1, 5, 15, 2, &s, &a); // s=20, a=5
    int ok = (fabs(s - 20.0) < 1e-4 && fabs(a - 5.0) < 1e-4);
    printf("%s: UVa 11715 - Car\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
