/*
 * ==========================================================================
 * UVa 10566 - Crossed Ladders
 * Title-CN: 交叉梯子 (二分搜尋與相似三角形)
 * Difficulty: Medium
 * Tags: Geometry, Binary Search, Math
 * URL: https://onlinejudge.org/external/105/10566.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Two ladders of lengths x and y cross in an alley. Their intersection is at height c. Find the alley width w.
 *
 * [中文] 題目說明:
 *     兩架長度為 x 與 y 的梯子在窄巷中交叉架在兩側牆上，交叉點距地面高度為 c，求窄巷寬度 w。
 *
 * [EN] Approach:
 *     Height of left wall h1 = sqrt(x^2 - w^2), right wall h2 = sqrt(y^2 - w^2). Harmonic mean: 1/h1 + 1/h2 = 1/c. Binary search w in [0, min(x, y)].
 * [中文] 思路:
 *     兩側牆高分別為 h1 = sqrt(x^2 - w^2) 與 h2 = sqrt(y^2 - w^2)，由相似三角形得 1/h1 + 1/h2 = 1/c。在 [0, min(x,y)] 內對巷寬 w 進行二分搜尋。
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

double solve_crossed_ladders(double x, double y, double c) {
    double l = 0.0, r = (x < y ? x : y);
    for (int it = 0; it < 60; it++) {
        double mid = (l + r) / 2.0;
        double h1 = sqrt(x * x - mid * mid);
        double h2 = sqrt(y * y - mid * mid);
        double c_calc = (h1 * h2) / (h1 + h2);
        if (c_calc > c) l = mid;
        else r = mid;
    }
    return (l + r) / 2.0;
}

int main(void) {

    double w = solve_crossed_ladders(30.0, 40.0, 10.0);
    int ok = (fabs(w - 26.0328) < 0.01);
    printf("%s: UVa 10566 - Crossed Ladders\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
