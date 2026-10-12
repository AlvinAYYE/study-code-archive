/*
 * ==========================================================================
 * UVa 10215 - The Largest/Smallest Box ...
 * Title-CN: 最大最小紙盒容積
 * Difficulty: UVa Star 1
 * Tags: math, calculus
 * ==========================================================================
 * [EN] Problem: Cut square of side x from 4 corners of W x L cardboard to maximize box volume.
 * [中文] 題目說明: 在 W x L 的硬紙板四角切除邊長 x 的正方形，折成紙盒求容積最大與最小時的 x。
 * [EN] Approach: V(x) = x*(W - 2x)*(L - 2x). V'(x) = 12x^2 - 4(W + L)x + WL = 0. Quadratic formula gives x.
 * [中文] 思路: 對體積函式求導數等於 0，一元二次方程求解 x。
 * ==========================================================================
 */
#include <stdio.h>
#include <math.h>

void solve_uva10215(double w, double l, double *max_x, double *min1, double *min2) {
    double b = -4.0 * (w + l);
    double c = w * l;
    *max_x = (-b - sqrt(b * b - 48.0 * c)) / 24.0;
    *min1 = 0.0;
    *min2 = (w < l ? w : l) / 2.0;
}

int main(void) {
    double mx, m1, m2;
    solve_uva10215(1.0, 1.0, &mx, &m1, &m2);
    int ok = (fabs(mx - 1.0/6.0) < 1e-4);
    printf("%s: UVa 10215 - The Largest Smallest Box\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
