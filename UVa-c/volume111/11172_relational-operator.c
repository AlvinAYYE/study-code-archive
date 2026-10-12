/*
 * ==========================================================================
 * UVa 11172 - Relational Operator
 * Title-CN: 關係運算子比較
 * Difficulty: UVa Star 1
 * Tags: math, basic-io
 * ==========================================================================
 * [EN] Problem: Compare a and b. Print '>', '<', or '='.
 * [中文] 題目說明: 比較兩數大小。
 * [EN] Approach: Standard if-else relational checks.
 * [中文] 思路: 直接以三向條件分支比較。
 * ==========================================================================
 */
#include <stdio.h>

char solve_uva11172(long long a, long long b) {
    if (a > b) return '>';
    if (a < b) return '<';
    return '=';
}

int main(void) {
    int ok = (solve_uva11172(10, 20) == '<') && (solve_uva11172(20, 10) == '>') && (solve_uva11172(5, 5) == '=');
    printf("%s: UVa 11172 - Relational Operator\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
