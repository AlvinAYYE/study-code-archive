/*
 * ==========================================================================
 * UVa 10921 - Find the Telephone
 * Title-CN: 電話號碼英文字母按鍵轉換
 * Difficulty: UVa Star 1
 * Tags: string, simulation
 * URL: https://onlinejudge.org/external/109/10921.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Convert letters in telephone expression to corresponding standard keypad digits.
 *
 * [中文] 題目說明:
 *     依據標準電話按鍵將文字號碼中的英文字母轉換為對應數字 (保留連字號與既有數字)。
 *
 * [EN] Approach:
 *     Direct switch/case or table lookup mapping A-C->2, D-F->3, G-I->4, J-L->5, M-O->6, P-S->7, T-V->8, W-Z->9.
 * [中文] 思路:
 *     查表法：將 26 個英文字母映射到 2-9 按鍵數字，數字與 '-' 保持原樣輸出。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char map_phone_digit(char c) {
    if (c >= 'A' && c <= 'C') return '2';
    if (c >= 'D' && c <= 'F') return '3';
    if (c >= 'G' && c <= 'I') return '4';
    if (c >= 'J' && c <= 'L') return '5';
    if (c >= 'M' && c <= 'O') return '6';
    if (c >= 'P' && c <= 'S') return '7';
    if (c >= 'T' && c <= 'V') return '8';
    if (c >= 'W' && c <= 'Z') return '9';
    return c;
}

int main(void) {

    int ok = (map_phone_digit('A') == '2') && (map_phone_digit('W') == '9');
    printf("%s: UVa 10921 - Find the Telephone\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
