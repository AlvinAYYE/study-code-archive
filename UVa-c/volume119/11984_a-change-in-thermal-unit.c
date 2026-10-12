/*
 * ==========================================================================
 * UVa 11984 - A Change in Thermal Unit
 * Title-CN: 熱力學溫標轉換
 * Difficulty: UVa Star 1
 * Tags: math
 * ==========================================================================
 * [EN] Problem: Initial temperature C (Celsius) increases by d (Fahrenheit degrees). Find final temperature in Celsius.
 * [中文] 題目說明: 初溫為攝氏 C 度，上升了華氏 d 度，求最終的攝氏溫度。
 * [EN] Approach: delta_C = d * 5.0 / 9.0. Final = C + delta_C.
 * [中文] 思路: 華氏溫差轉攝氏溫差：d * 5 / 9，最終溫度為 C + d * 5 / 9。
 * ==========================================================================
 */
#include <stdio.h>
#include <math.h>

double solve_uva11984(double c, double d) {
    return c + d * 5.0 / 9.0;
}

int main(void) {
    double res = solve_uva11984(100.0, 0.0);
    int ok = (fabs(res - 100.0) < 1e-4);
    double res2 = solve_uva11984(0.0, 25.0);
    ok = ok && (fabs(res2 - 13.89) < 0.01);
    printf("%s: UVa 11984 - A Change in Thermal Unit\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
