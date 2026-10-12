/*
 * ==========================================================================
 * UVa 579 - Clock Hands
 * Title-CN: 時鐘時針與分針夾角
 * Difficulty: UVa Star 1
 * Tags: math, geometry
 * ==========================================================================
 * [EN] Problem: Find minimal angle between hour and minute hands.
 * [中文] 題目說明: 給定時間 H:M，計算時針與分針之間的最小夾角（<= 180 度）。
 * [EN] Approach: hour_deg = 30*H + 0.5*M, min_deg = 6*M. Angle = abs(hour_deg - min_deg).
 * [中文] 思路: 時針角度 30*H + 0.5*M，分針 6*M，相減絕對值若大於 180 則取 360 - 角度。
 * ==========================================================================
 */
#include <stdio.h>
#include <math.h>

double solve_uva579(int h, int m) {
    double h_deg = h * 30.0 + m * 0.5;
    double m_deg = m * 6.0;
    double diff = fabs(h_deg - m_deg);
    if (diff > 180.0) diff = 360.0 - diff;
    return diff;
}

int main(void) {
    double deg = solve_uva579(12, 0);
    int ok = (fabs(deg - 0.0) < 1e-4);
    double deg2 = solve_uva579(3, 0);
    ok = ok && (fabs(deg2 - 90.0) < 1e-4);
    printf("%s: UVa 579 - Clock Hands\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
