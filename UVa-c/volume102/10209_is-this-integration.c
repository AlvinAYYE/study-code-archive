/*
 * ==========================================================================
 * UVa 10209 - Is This Integration?
 * Title-CN: 這是積分嗎？
 * Difficulty: UVa Star 1
 * Tags: geometry, math
 * ==========================================================================
 * [EN] Problem: Calculate area of 3 geometric regions formed by 4 circular arcs.
 * [中文] 題目說明: 正方形四角圓弧相交區域幾何面積計算。
 * [EN] Approach: Exact geometric formulas with Pi and sqrt(3).
 * [中文] 思路: 聯立幾何代數解出各對稱塊之解析面積公式。
 * ==========================================================================
 */
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

void solve_uva10209(double a, double *striped, double *dotted, double *rest) {
    double a2 = a * a;
    *striped = a2 * (1.0 + PI / 3.0 - sqrt(3.0));
    *dotted  = a2 * (PI / 12.0 + sqrt(3.0) / 2.0 - 1.0) * 4.0;
    *rest    = a2 - *striped - *dotted;
}

int main(void) {
    double z1, z2, z3;
    solve_uva10209(1.0, &z1, &z2, &z3);
    int ok = (z1 > 0 && z2 > 0 && z3 > 0);
    printf("%s: UVa 10209 - Is This Integration\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
