/*
 * ==========================================================================
 * UVa 343 - What Base Is This?
 * Title-CN: 這是幾進位？(任意進位等值搜尋)
 * Difficulty: UVa Star 2
 * Tags: math, base-conversion, brute-force
 * URL: https://onlinejudge.org/external/3/343.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find smallest bases B1 and B2 (2 <= B <= 36) such that string X in base B1 equals string Y in base B2.
 *
 * [中文] 題目說明:
 *     尋找最小進位 B1 與 B2 (2 <= B <= 36)，使得字串 X 在 B1 進位下的數值等於字串 Y 在 B2 進位下的數值。
 *
 * [EN] Approach:
 *     Determine min valid base for both strings. Loop B1 and B2 from min base to 36, parse to base 10 and compare.
 * [中文] 思路:
 *     找出兩字串字元決定的最小合法基底，雙層迴圈枚舉 B1 與 B2 (2..36)，轉為十進位比對數值是否相等。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

static int char_val(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'Z') return c - 'A' + 10;
    return -1;
}

long long to_decimal(const char *s, int b) {
    long long v = 0;
    for (int i = 0; s[i]; i++) {
        int d = char_val(s[i]);
        if (d >= b) return -1;
        v = v * b + d;
    }
    return v;
}

int solve_uva343(const char *s1, const char *s2, int *b1, int *b2) {
    int min_b1 = 2, min_b2 = 2;
    for (int i = 0; s1[i]; i++) if (char_val(s1[i]) + 1 > min_b1) min_b1 = char_val(s1[i]) + 1;
    for (int i = 0; s2[i]; i++) if (char_val(s2[i]) + 1 > min_b2) min_b2 = char_val(s2[i]) + 1;
    for (int i = min_b1; i <= 36; i++) {
        long long v1 = to_decimal(s1, i);
        if (v1 < 0) continue;
        for (int j = min_b2; j <= 36; j++) {
            long long v2 = to_decimal(s2, j);
            if (v1 == v2) { *b1 = i; *b2 = j; return 1; }
        }
    }
    return 0;
}

int main(void) {

    int b1, b2;
    int ok = solve_uva343("12", "5", &b1, &b2) && (b1 == 3 && b2 == 6);
    printf("%s: UVa 343 - What Base Is This?\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
