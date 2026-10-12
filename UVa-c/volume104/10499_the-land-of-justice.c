/*
 * ==========================================================================
 * UVa 10499 - The Land of Justice
 * Title-CN: 正義之國
 * Difficulty: UVa Star 1
 * Tags: math
 * ==========================================================================
 * [EN] Problem: Percentage increase in surface area when sphere cut into N parts.
 * [中文] 題目說明: 球體過球心切成 N 等份，表面積增加百分比。
 * [EN] Approach: If n <= 1 return 0; else return n * 25%.
 * [中文] 思路: 每個剖面均為半圓，總增加面積與原表面積比值恰為 n * 25%。
 * ==========================================================================
 */
#include <stdio.h>

long long solve_uva10499(long long n) {
    if (n <= 1) return 0;
    return n * 25;
}

int main(void) {
    int ok = (solve_uva10499(2) == 50) && (solve_uva10499(1) == 0);
    printf("%s: UVa 10499 - The Land of Justice\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
