/*
 * ==========================================================================
 * UVa 10929 - You can say 11
 * Title-CN: 11的倍數檢測 (奇偶位數交替和)
 * Difficulty: UVa Star 1
 * Tags: math, big-integer
 * URL: https://onlinejudge.org/external/109/10929.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine whether a huge integer up to 1000 digits is divisible by 11.
 *
 * [中文] 題目說明:
 *     判定最多 1000 位數的超大整數是否能被 11 整除 (奇數位與偶數位數字交替和之差為 11 的倍數)。
 *
 * [EN] Approach:
 *     Sum alternating digits: (d_0 - d_1 + d_2 - d_3 ...) % 11 == 0.
 * [中文] 思路:
 *     利用 11 的同餘整除法則：奇數位數字和與偶數位數字和的差值若能被 11 整除，則原數能被 11 整除。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva10929(const char *s) {
    int diff = 0;
    for (int i = 0; s[i]; i++) {
        int d = s[i] - '0';
        if (i % 2 == 0) diff += d;
        else diff -= d;
    }
    return (diff % 11 == 0);
}

int main(void) {

    int ok = solve_uva10929("112233") && !solve_uva10929("112234");
    printf("%s: UVa 10929 - You can say 11\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
