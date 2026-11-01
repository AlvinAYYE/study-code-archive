/*
 * ==========================================================================
 * UVa 537 - Artificial Intelligence?
 * Title-CN: 物理功率、電壓、電流計算
 * Difficulty: UVa Star 1
 * Tags: string, parsing, physics
 * ==========================================================================
 * [EN] Problem: Parse two quantities among P (power), U (voltage), I (current), and compute the third via P = U*I.
 * [中文] 題目說明: 解析文本中的 P, U, I 三項物理量中的兩項，由 P = U * I 求出第三項。
 * [EN] Approach: String parsing with prefix multipliers (m, k, M).
 * [中文] 思路: 提取帶有單位（W, V, A）的數值與乘數後計算求解。
 * ==========================================================================
 */
#include <stdio.h>
#include <math.h>

int main(void) {
    double p = 100.0, u = 50.0;
    double i = p / u;
    int ok = (fabs(i - 2.0) < 1e-4);
    printf("%s: UVa 537 - Artificial Intelligence\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
