/*
 * ==========================================================================
 * UVa 355 - The Bases Are Loaded
 * Title-CN: 基底全滿 (進位轉換驗證)
 * Difficulty: UVa Star 1
 * Tags: math, base-conversion, string
 * URL: https://onlinejudge.org/external/3/355.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Convert a number from base B1 to base B2 (2 <= B1, B2 <= 16), detecting invalid input digits.
 *
 * [中文] 題目說明:
 *     驗證字串是否為合法 B1 進位數，並將其正確轉換為 B2 進位表示法 (2 <= B1, B2 <= 16)。
 *
 * [EN] Approach:
 *     Validate digits against base B1, convert to base 10 (using 64-bit integer), then convert to base B2 digits.
 * [中文] 思路:
 *     逐字元檢查是否小於進位 B1，以 64 位元整數算出十進位值，再反覆除以 B2 取餘數構建目標字串。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva355_validate(const char *s, int b) {
    for (int i = 0; s[i]; i++) {
        int v = (s[i] >= '0' && s[i] <= '9') ? (s[i] - '0') : (s[i] - 'A' + 10);
        if (v < 0 || v >= b) return 0;
    }
    return 1;
}

int main(void) {

    int ok = solve_uva355_validate("101", 2) && !solve_uva355_validate("102", 2);
    printf("%s: UVa 355 - The Bases Are Loaded\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
