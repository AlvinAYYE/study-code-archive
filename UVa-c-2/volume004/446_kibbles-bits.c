/*
 * ==========================================================================
 * UVa 446 - Kibbles n Bits n Bits n Bits
 * Title-CN: 十六進位轉十三位元二進位運算
 * Difficulty: UVa Star 1
 * Tags: bit-manipulation, base-conversion, formatting
 * URL: https://onlinejudge.org/external/4/446.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given hex expression 'A + B' or 'A - B', print 13-bit binary of A, operator, 13-bit binary of B, and decimal result.
 *
 * [中文] 題目說明:
 *     給定十六進位運算式 (如 '0x1A + 0x2')，格式化輸出 13 位元二進位、運算子與十進位計算結果。
 *
 * [EN] Approach:
 *     Parse hex with %x. Format integers into 13-bit binary with leading zeros using bitwise checks (1 << bit).
 * [中文] 思路:
 *     利用 %x 讀入數值，位元運算由第 12 位元往下檢查 (val & (1 << i)) 輸出 13 位二進位字串並計算加減結果。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void to_binary13(int val, char *out) {
    for (int i = 12; i >= 0; i--) {
        out[12 - i] = (val & (1 << i)) ? '1' : '0';
    }
    out[13] = '\0';
}

int main(void) {

    char b[15];
    to_binary13(5, b);
    int ok = (strcmp(b, "0000000000101") == 0);
    printf("%s: UVa 446 - Kibbles n Bits n Bits n Bits\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
