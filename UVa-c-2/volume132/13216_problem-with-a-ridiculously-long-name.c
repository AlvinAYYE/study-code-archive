/*
 * ==========================================================================
 * UVa 13216 - Problem with a Ridiculously Long Name
 * Title-CN: 66的N次方末兩位數規律
 * Difficulty: UVa Star 1
 * Tags: math, number-theory
 * URL: https://onlinejudge.org/external/132/13216.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Compute the last two digits of 66^n for huge n.
 *
 * [中文] 題目說明:
 *     求 66^n 的最後兩位數字 (n 為超大整數)。
 *
 * [EN] Approach:
 *     Base cases: 66^0 = 01 (or 1), 66^1 = 66. For n >= 2, last two digits have period 5: 56, 96, 36, 76, 16...
 * [中文] 思路:
 *     同餘週期規律：66^0=1, 66^1=66。當 n >= 2 時末兩位數以 5 為週期循環：56, 96, 36, 76, 16。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

const char* solve_uva13216(const char *n_str) {
    if (strcmp(n_str, "0") == 0) return "1";
    if (strcmp(n_str, "1") == 0) return "66";
    const char *cycle[5] = {"76", "16", "56", "96", "36"};
    int last_d = n_str[strlen(n_str) - 1] - '0';
    return cycle[last_d % 5];
}

int main(void) {

    int ok = (strcmp(solve_uva13216("0"), "1") == 0) &&
             (strcmp(solve_uva13216("1"), "66") == 0) &&
             (strcmp(solve_uva13216("2"), "56") == 0);
    printf("%s: UVa 13216 - Problem with a Ridiculously Long Name\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
