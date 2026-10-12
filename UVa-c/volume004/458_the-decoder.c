/*
 * ==========================================================================
 * UVa 458 - The Decoder
 * Title-CN: 簡易解碼器
 * Difficulty: UVa Star 1
 * Tags: string, basic-io
 * ==========================================================================
 * [EN] Problem: Decode by subtracting 7 from ASCII value of each character.
 * [中文] 題目說明: 簡易字元解碼：將每個字元的 ASCII 碼減去 7。
 * [EN] Approach: putchar(c - 7) for all non-newline characters.
 * [中文] 思路: 逐字元讀入輸出 c - 7。
 * ==========================================================================
 */
#include <stdio.h>

char decode_char(char c) {
    return (char)(c - 7);
}

int main(void) {
    int ok = (decode_char('1') == '*') && (decode_char('J') == 'C');
    printf("%s: UVa 458 - The Decoder\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
