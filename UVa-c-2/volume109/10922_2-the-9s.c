/*
 * ==========================================================================
 * UVa 10922 - 2 the 9s
 * Title-CN: 9的度數 (9-degree 數位和倍數遞歸)
 * Difficulty: UVa Star 1
 * Tags: math, recursion
 * URL: https://onlinejudge.org/external/109/10922.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine if number is multiple of 9 by digital root and compute its 9-degree.
 *
 * [中文] 題目說明:
 *     判斷大整數是否為 9 的倍數，並計算反覆求數位和直到為個位數 9 所需的遞迴次數 (9-degree)。
 *
 * [EN] Approach:
 *     Sum digits of string. If sum % 9 == 0, count recursive steps to reach 9.
 * [中文] 思路:
 *     初次加總字串各位數字。若總和不能被 9 整除則非 9 的倍數；否則反覆求各位和，遞增度數計數直到值為 9。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva10922(const char *s, int *degree) {
    int sum = 0;
    for (int i = 0; s[i]; i++) sum += s[i] - '0';
    if (sum % 9 != 0) return 0;
    int deg = 1;
    while (sum > 9) {
        int nxt = 0;
        while (sum) { nxt += sum % 10; sum /= 10; }
        sum = nxt;
        deg++;
    }
    *degree = deg;
    return 1;
}

int main(void) {

    int deg;
    int is9 = solve_uva10922("999999999999999999999", &deg);
    int ok = is9 && (deg >= 2);
    printf("%s: UVa 10922 - 2 the 9s\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
