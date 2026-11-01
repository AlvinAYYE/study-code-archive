/*
 * ==========================================================================
 * UVa 11479 - Is this the easiest problem?
 * Title-CN: 三角形三邊關係與種類判定
 * Difficulty: UVa Star 1
 * Tags: geometry, math
 * URL: https://onlinejudge.org/external/114/11479.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine if three sides form a valid triangle and classify as Equilateral, Isosceles, or Scalene.
 *
 * [中文] 題目說明:
 *     檢驗三邊長能否構成合法三角形 (兩邊之和大於第三邊)，並判定為正三角形、等腰三角形或不等邊三角形。
 *
 * [EN] Approach:
 *     Check positivity and triangle inequality (use 64-bit integers to prevent overflow). Classify by edge equality.
 * [中文] 思路:
 *     注意使用 64 位元整數相加防止溢位。先判定兩較小邊之和大於最大邊，再依三邊相等、兩邊相等或皆不相等分類。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva11479(long long a, long long b, long long c) {
    if (a <= 0 || b <= 0 || c <= 0) return 0; /* Invalid */
    if (a + b <= c || a + c <= b || b + c <= a) return 0; /* Invalid */
    if (a == b && b == c) return 1; /* Equilateral */
    if (a == b || b == c || a == c) return 2; /* Isosceles */
    return 3; /* Scalene */
}

int main(void) {

    int ok = (solve_uva11479(3, 3, 3) == 1) && (solve_uva11479(3, 3, 4) == 2) && (solve_uva11479(3, 4, 5) == 3);
    printf("%s: UVa 11479 - Is this the easiest problem?\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
