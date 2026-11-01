/*
 * ==========================================================================
 * UVa 11172 - Relational Operator
 * Title-CN: 關係運算子大小比較
 * Difficulty: UVa Star 1
 * Tags: simulation
 * URL: https://onlinejudge.org/external/111/11172.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Compare two integers a and b, outputting '>', '<', or '='.
 *
 * [中文] 題目說明:
 *     比較兩整數 a 與 b 的大小關係，輸出相應的大於、小於或等於運算子。
 *
 * [EN] Approach:
 *     Simple if-else branching.
 * [中文] 思路:
 *     基礎條件判斷分支：a > b 輸出 '>'，a < b 輸出 '<'，否則輸出 '='。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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
