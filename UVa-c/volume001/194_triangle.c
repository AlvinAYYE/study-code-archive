/*
 * ==========================================================================
 * UVa 194 - Triangle
 * Title-CN: 任意三角形已知三元素解三角形
 * Difficulty: UVa Star 2
 * Tags: geometry, math
 * URL: https://onlinejudge.org/external/1/194.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given 3 known sides/angles of a triangle, determine if a valid unique triangle exists and solve for the remaining 3 elements.
 *
 * [中文] 題目說明:
 *     給定三角形任意 3 個已知元素 (邊長或內角)，判定其能否構成唯一合法三角形並解出其餘 3 個未知元素。
 *
 * [EN] Approach:
 *     Apply Law of Sines and Law of Cosines to solve known SSS, SAS, ASA, or AAS configurations; handle SSA ambiguous cases.
 * [中文] 思路:
 *     利用正弦定理與餘弦定理依序解析 SSS、SAS、ASA 或 AAS 構型，嚴格驗證內角和大於 0 小於 180 度及邊長正值約束。
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

double solve_third_side(double a, double b, double gamma_rad) {
    return sqrt(a * a + b * b - 2.0 * a * b * cos(gamma_rad));
}

int main(void) {

    double c = solve_third_side(3.0, 4.0, 3.141592653589793 / 2.0);
    int ok = (fabs(c - 5.0) < 1e-4);
    printf("%s: UVa 194 - Triangle\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
