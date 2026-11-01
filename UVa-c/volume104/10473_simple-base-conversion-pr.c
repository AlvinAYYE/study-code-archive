/*
 * ==========================================================================
 * UVa 10473 - Simple Base Conversion
 * Title-CN: 簡單十進位與十六進位相互轉換
 * Difficulty: UVa Star 1
 * Tags: base-conversion, formatting, string
 * URL: https://onlinejudge.org/external/104/10473.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Convert hex numbers (prefixed with 0x) to decimal, and decimal numbers to hex prefixed with 0x.
 *
 * [中文] 題目說明:
 *     若輸入帶有 '0x' 前綴則轉換為十進位輸出；若輸入為十進位則轉換為十六進位大寫輸出。
 *
 * [EN] Approach:
 *     Check if s starts with '0x' or '0X'. If so, sscanf with %x and print %d; else sscanf with %d and print 0x%X.
 * [中文] 思路:
 *     檢查字串前綴是否為 "0x"，若是則以 %x 讀取轉為十進位；否則以十進位讀取轉為 0x%X。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void solve_uva10473(const char *in, char *out) {
    if (in[0] == '0' && (in[1] == 'x' || in[1] == 'X')) {
        int val;
        sscanf(in, "%x", &val);
        sprintf(out, "%d", val);
    } else {
        int val;
        sscanf(in, "%d", &val);
        sprintf(out, "0x%X", val);
    }
}

int main(void) {

    char out[30];
    solve_uva10473("0x1A", out);
    int ok = (strcmp(out, "26") == 0);
    printf("%s: UVa 10473 - Simple Base Conversion\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
