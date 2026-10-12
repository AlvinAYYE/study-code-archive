/*
 * ==========================================================================
 * UVa 11185 - Ternary
 * Title-CN: 三進位制轉換
 * Difficulty: UVa Star 1
 * Tags: math, base-conversion
 * ==========================================================================
 * [EN] Problem: Convert decimal N to base 3 string.
 * [中文] 題目說明: 十進位轉三進位。
 * [EN] Approach: Repeated division by 3, reverse digits.
 * [中文] 思路: 連續除以 3 取餘數並反轉字串。
 * ==========================================================================
 */
#include <stdio.h>
#include <string.h>

void solve_uva11185(long long n, char *out) {
    if (n == 0) { strcpy(out, "0"); return; }
    char buf[64];
    int len = 0;
    while (n > 0) {
        buf[len++] = (char)('0' + (n % 3));
        n /= 3;
    }
    for (int i = 0; i < len; i++) out[i] = buf[len - 1 - i];
    out[len] = '\0';
}

int main(void) {
    char out[64];
    solve_uva11185(10, out);
    int ok = (strcmp(out, "101") == 0);
    printf("%s: UVa 11185 - Ternary\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
