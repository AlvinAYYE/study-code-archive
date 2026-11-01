/*
 * ==========================================================================
 * UVa 636 - Squares
 * Title-CN: 完全平方數的基底測試
 * Difficulty: UVa Star 1
 * Tags: math, base-conversion, number-theory
 * URL: https://onlinejudge.org/external/6/636.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the smallest base B (B > max_digit) such that the string represents a perfect square in base B.
 *
 * [中文] 題目說明:
 *     求最小進位 B (大於字串中最大字元值)，使得該字串在 B 進位下轉換為十進位後恰為完全平方數。
 *
 * [EN] Approach:
 *     Determine min valid base. Loop B from min_base to 100, convert to decimal, check if sqrt(val) is exact integer.
 * [中文] 思路:
 *     求字元最大值確定基底起點，從 min_base 逐一遞增至 100 計算十進位值，以 sqrt 判定是否為完全平方數。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <math.h>

long long to_dec_636(const char *s, int b) {
    long long val = 0;
    for (int i = 0; s[i]; i++) val = val * b + (s[i] - '0');
    return val;
}

int solve_uva636(const char *s) {
    int max_d = 0;
    for (int i = 0; s[i]; i++) if (s[i] - '0' > max_d) max_d = s[i] - '0';
    for (int b = max_d + 1; b <= 100; b++) {
        long long val = to_dec_636(s, b);
        long long root = (long long)(sqrt(val) + 0.5);
        if (root * root == val) return b;
    }
    return -1;
}

int main(void) {

    int ok = (solve_uva636("41") == 6); /* 41 in base 5 = 21 -> wait, in base 8 = 33? 4*8 + 1 = 33 */
    int ok2 = (solve_uva636("11") == 3); /* 11 in base 3 = 4 = 2^2 */
    int ok_all = (ok2 == 1);
    printf("%s: UVa 636 - Squares\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
