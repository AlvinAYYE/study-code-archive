/*
 * ==========================================================================
 * UVa 10473 - Simple Base Conversion
 * Title-CN: 簡單進位轉換
 * Difficulty: UVa Star 1
 * Tags: math, base-conversion, string
 * URL: https://onlinejudge.org/external/104/10473.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Convert hex (prefixed with 0x) to decimal, and decimal to hex (prefixed with 0x).
 *
 * [中文] 題目說明:
 *     輸入以 0x 開頭表示十六進位，需轉為十進位輸出；否則為十進位，需轉為十六進位（帶 0x）輸出。
 *
 * [EN] Approach: Use sscanf / strtol with base 16 and base 10.
 * [中文] 思路: 檢查前綴字元 '0' 與 'x'，使用 sscanf 或 sprintf 進行互轉。
 * ==========================================================================
 */
#include <stdio.h>
#include <string.h>

void solve_uva10473(const char *in, char *out) {
    if (in[0] == '0' && (in[1] == 'x' || in[1] == 'X')) {
        unsigned int val;
        sscanf(in, "%x", &val);
        sprintf(out, "%u", val);
    } else {
        int val;
        sscanf(in, "%d", &val);
        sprintf(out, "0x%X", val);
    }
}

int main(void) {
    char out[32];
    solve_uva10473("0x1A", out);
    int ok1 = (strcmp(out, "26") == 0);
    solve_uva10473("26", out);
    int ok2 = (strcmp(out, "0x1A") == 0);
    int ok = ok1 && ok2;
    printf("%s: UVa 10473 - Simple Base Conversion\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
