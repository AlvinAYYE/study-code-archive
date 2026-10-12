/*
 * ==========================================================================
 * UVa 11854 - Egypt
 * Title-CN: 埃及金字塔
 * Difficulty: UVa Star 1
 * Tags: geometry, math
 * ==========================================================================
 * [EN] Problem: Check if 3 side lengths form right-angled triangle.
 * [中文] 題目說明: 檢驗三邊長是否為直角三角形。
 * [EN] Approach: Sort 3 sides, verify a^2 + b^2 == c^2.
 * [中文] 思路: 排序邊長後比對畢氏定理。
 * ==========================================================================
 */
#include <stdio.h>

int solve_uva11854(long long a, long long b, long long c) {
    long long s1 = a * a, s2 = b * b, s3 = c * c;
    return (s1 + s2 == s3) || (s1 + s3 == s2) || (s2 + s3 == s1);
}

int main(void) {
    int ok = solve_uva11854(6, 8, 10) && !solve_uva11854(25, 52, 60);
    printf("%s: UVa 11854 - Egypt\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
