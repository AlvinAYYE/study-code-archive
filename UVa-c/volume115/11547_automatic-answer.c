/*
 * ==========================================================================
 * UVa 11547 - Automatic Answer
 * Title-CN: 自動答案
 * Difficulty: UVa Star 1
 * Tags: math
 * ==========================================================================
 * [EN] Problem: Evaluate expression and return absolute tens digit.
 * [中文] 題目說明: 依題目公式計算並回傳結果十位數之絕對值。
 * [EN] Approach: abs(((n * 63 + 7492) * 5 - 498) / 10) % 10.
 * [中文] 思路: 化簡乘除運算後除以 10 取模 10。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>

int solve_uva11547(long long n) {
    long long ans = (n * 63 + 7492) * 5 - 498;
    return (int)(abs(ans / 10) % 10);
}

int main(void) {
    int ok = (solve_uva11547(637) == 1) && (solve_uva11547(-234) == 4);
    printf("%s: UVa 11547 - Automatic Answer\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
