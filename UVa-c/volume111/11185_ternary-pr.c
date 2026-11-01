/*
 * ==========================================================================
 * UVa 11185 - Ternary
 * Title-CN: 三進位制轉換
 * Difficulty: UVa Star 1
 * Tags: base-conversion, math
 * URL: https://onlinejudge.org/external/111/11185.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Convert non-negative decimal integer N into base 3 (ternary).
 *
 * [中文] 題目說明:
 *     將非負十進位整數 N 轉換為三進位制字串輸出。
 *
 * [EN] Approach:
 *     Standard base conversion: repeatedly take N % 3, divide N by 3, reverse digits.
 * [中文] 思路:
 *     除以 3 取餘數法：反覆將數值除以 3 並收集餘數，最後將數位倒序輸出 (N=0 特判為 "0")。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void solve_uva11185(long long n, char *out) {
    if (n == 0) { strcpy(out, "0"); return; }
    char buf[50];
    int len = 0;
    while (n) {
        buf[len++] = (n % 3) + '0';
        n /= 3;
    }
    for (int i = 0; i < len; i++) out[i] = buf[len - 1 - i];
    out[len] = '\0';
}

int main(void) {

    char res[50];
    solve_uva11185(10, res);
    int ok = (strcmp(res, "101") == 0); /* 10 in base 3 = 101 */
    printf("%s: UVa 11185 - Ternary\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
