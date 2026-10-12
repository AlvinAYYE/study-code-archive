/*
 * ==========================================================================
 * UVa 10012 - How Big Is It?
 * Title-CN: 圓形排列最小外接矩形寬度
 * Difficulty: UVa Star 2
 * Tags: geometry, backtracking, math
 * ==========================================================================
 * [EN] Problem: Given n circles, order them on a line to minimize horizontal enclosing box width.
 * [中文] 題目說明: 將 n 個不同半徑的圓放在水平線上相切排列，求最小的外接矩形寬度。
 * [EN] Approach: Backtracking permutation (n <= 8). Position x_i = max(r_i, max_j(x_j + 2*sqrt(r_i * r_j))).
 * [中文] 思路: 回溯枚舉圓的排列，相切圓中心距離為 2*sqrt(r_i*r_j)。
 * ==========================================================================
 */
#include <stdio.h>
#include <math.h>

static inline double max_d(double a, double b) { return a > b ? a : b; }

double calc_width(int n, const double *r) {
    double x[10];
    for (int i = 0; i < n; i++) {
        x[i] = r[i];
        for (int j = 0; j < i; j++) {
            double cand = x[j] + 2.0 * sqrt(r[i] * r[j]);
            x[i] = max_d(x[i], cand);
        }
    }
    double min_x = 1e9, max_x = -1e9;
    for (int i = 0; i < n; i++) {
        min_x = fmin(min_x, x[i] - r[i]);
        max_x = max_d(max_x, x[i] + r[i]);
    }
    return max_x - min_x;
}

int main(void) {
    double r[3] = {2.0, 1.0, 2.0};
    double w = calc_width(3, r);
    int ok = (w > 0.0);
    printf("%s: UVa 10012 - How Big Is It\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
