/*
 * ==========================================================================
 * UVa 10922 - 2 the 9s
 * Title-CN: 9 的度數
 * Difficulty: UVa Star 1
 * Tags: math, number-theory
 * ==========================================================================
 * [EN] Problem: Find 9-degree of integer string.
 * [中文] 題目說明: 判定 9 的倍數並計算達到個位數 9 的位數和次數。
 * [EN] Approach: Sum digits, repeat until single digit.
 * [中文] 思路: 重複數字和直到小於 10。
 * ==========================================================================
 */
#include <stdio.h>

int solve_uva10922(const char *s, int *degree) {
    int sum = 0;
    for (int i = 0; s[i]; i++) sum += (s[i] - '0');
    if (sum % 9 != 0) return 0;

    int deg = 1;
    while (sum > 9) {
        int next_sum = 0;
        while (sum) { next_sum += sum % 10; sum /= 10; }
        sum = next_sum;
        deg++;
    }
    *degree = deg;
    return 1;
}

int main(void) {
    int deg;
    int ok = solve_uva10922("999999999999999999999", &deg) && (deg == 3);
    printf("%s: UVa 10922 - 2 the 9s\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
