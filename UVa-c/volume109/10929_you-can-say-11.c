/*
 * ==========================================================================
 * UVa 10929 - You can say 11
 * Title-CN: 你能說 11 嗎？
 * Difficulty: UVa Star 1 / CPE 49 顆星必考題
 * Tags: math, number-theory, divisibility
 * URL: https://onlinejudge.org/external/109/10929.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine whether a huge integer (up to 1000 digits) is divisible by 11.
 *
 * [中文] 題目說明:
 *     判斷超長整數字串是否為 11 的倍數。
 *
 * [EN] Approach: Alternating sum of digits modulo 11.
 * [中文] 思路: 奇數位數字和減去偶數位數字和，若差能被 11 整除則為 11 的倍數。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>

int solve_uva10929(const char *s) {
    int diff = 0;
    for (int i = 0; s[i]; i++) {
        if (i % 2 == 0) diff += (s[i] - '0');
        else diff -= (s[i] - '0');
    }
    return (abs(diff) % 11 == 0);
}

int main(void) {
    int ok = solve_uva10929("112233") && solve_uva10929("30800") && !solve_uva10929("123");
    printf("%s: UVa 10929 - You can say 11\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
