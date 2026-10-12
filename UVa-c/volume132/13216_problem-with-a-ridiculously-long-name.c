/*
 * ==========================================================================
 * UVa 13216 - Problem with a ridiculously long name...
 * Title-CN: 66 的 N 次方末兩位循環規律
 * Difficulty: UVa Star 1
 * Tags: math
 * ==========================================================================
 * [EN] Problem: Find last two digits of 66^N for huge N.
 * [中文] 題目說明: 求 66^N 的最後兩位數字（N 可為任意超大數）。
 * [EN] Approach: For N=0: 01; N=1: 66; N >= 2: cycles with period 5 on last digit of N: {2:56, 3:96, 4:36, 5:76, 0:16}.
 * [中文] 思路: 66^N 末兩位數自 N >= 2 起以 5 為週期循環：56, 96, 36, 76, 16。
 * ==========================================================================
 */
#include <stdio.h>
#include <string.h>

static const int cycle[5] = {76, 16, 56, 96, 36};

int solve_uva13216(const char *s) {
    if (strcmp(s, "0") == 0) return 1;
    if (strcmp(s, "1") == 0) return 66;
    int last_d = s[strlen(s) - 1] - '0';
    return cycle[last_d % 5];
}

int main(void) {
    int ok = (solve_uva13216("2") == 56) && (solve_uva13216("3") == 96);
    printf("%s: UVa 13216 - Problem with a ridiculously long name\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
