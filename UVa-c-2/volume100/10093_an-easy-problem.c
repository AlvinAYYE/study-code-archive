/*
 * ==========================================================================
 * UVa 10093 - An Easy Problem!
 * Title-CN: 簡單的問題！
 * Difficulty: UVa Star 1 / CPE 49 顆星必考題
 * Tags: math, number-theory, base-conversion
 * URL: https://onlinejudge.org/external/100/10093.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find minimum base N (2 <= N <= 62) such that R in base N is divisible by N - 1.
 *
 * [中文] 題目說明:
 *     找出最小進位制 N，使得 R 在 N 進位下的數值能被 (N - 1) 整除。
 *
 * [EN] Approach:
 *     Digit sum must be divisible by (N - 1), where base N > max_digit.
 * [中文] 思路:
 *     由同餘性質，各位數值之和 mod (N - 1) == 0。N 至少大於字串中最大字元值。
 * ==========================================================================
 */
#include <stdio.h>
#include <ctype.h>

static int char_val(char c) {
    if (isdigit((unsigned char)c)) return c - '0';
    if (isupper((unsigned char)c)) return c - 'A' + 10;
    if (islower((unsigned char)c)) return c - 'a' + 36;
    return -1;
}

int solve_uva10093(const char *s) {
    int max_digit = 1;
    long long sum = 0;
    for (int i = 0; s[i]; i++) {
        int v = char_val(s[i]);
        if (v >= 0) {
            sum += v;
            if (v > max_digit) max_digit = v;
        }
    }
    for (int base = max_digit + 1; base <= 62; base++) {
        if (sum % (base - 1) == 0) return base;
    }
    return -1;
}

int main(void) {
    int ok = (solve_uva10093("3") == 4) && (solve_uva10093("5") == 6) && (solve_uva10093("A") == 11);
    printf("%s: UVa 10093 - An Easy Problem!\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
