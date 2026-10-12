/*
 * ==========================================================================
 * UVa 389 - Basically Speaking
 * Title-CN: 基本進位制轉換
 * Difficulty: UVa Star 1
 * Tags: math, base-conversion
 * ==========================================================================
 * [EN] Problem: Convert number from base A to base B. If result exceeds 7 characters, print ERROR.
 * [中文] 題目說明: 將 A 進位整數字串轉為 B 進位字串（2 <= A, B <= 16），若超過 7 位輸出 ERROR。
 * [EN] Approach: Parse base A string to decimal, format to base B, check length <= 7.
 * [中文] 思路: 先轉為十進位，再轉為 B 進位字串並檢查長度。
 * ==========================================================================
 */
#include <stdio.h>
#include <string.h>

static const char digits[] = "0123456789ABCDEF";

void solve_uva389(const char *in, int base_from, int base_to, char *out) {
    long long dec = 0;
    for (int i = 0; in[i]; i++) {
        char c = in[i];
        int val = (c >= 'A') ? (c - 'A' + 10) : (c - '0');
        dec = dec * base_from + val;
    }
    if (dec == 0) { strcpy(out, "0"); return; }
    char buf[64];
    int len = 0;
    while (dec > 0) {
        buf[len++] = digits[dec % base_to];
        dec /= base_to;
    }
    if (len > 7) { strcpy(out, "ERROR"); return; }
    for (int i = 0; i < len; i++) out[i] = buf[len - 1 - i];
    out[len] = '\0';
}

int main(void) {
    char out[16];
    solve_uva389("1111000", 2, 10, out);
    int ok = (strcmp(out, "120") == 0);
    printf("%s: UVa 389 - Basically Speaking\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
