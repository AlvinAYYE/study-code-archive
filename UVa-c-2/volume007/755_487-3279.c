/*
 * ==========================================================================
 * UVa 755 - 487--3279
 * Title-CN: 電話號碼標準化與重複統計
 * Difficulty: UVa Star 1
 * Tags: string, sorting, simulation
 * URL: https://onlinejudge.org/external/7/755.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Standardize phone numbers (letters to digits A..P->2..7, R..Y->7..9), find all numbers appearing > 1 time, sorted.
 *
 * [中文] 題目說明:
 *     將電話號碼英文字母轉為對應按鍵數字並去除破折號，格式化為 7 位數，統計出現 2 次以上的號碼按字典序輸出。
 *
 * [EN] Approach:
 *     Map char to digit: (c - 'A' - (c > 'Q')) / 3 + 2. Convert to 7-digit integer, sort array and group duplicate counts.
 * [中文] 思路:
 *     依電話按鍵將字母映射為數字 0-9，存入 32 位元整數陣列快速排序，線性掃描統計出現次數大於 1 的重複號碼。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int map_phone_char(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'P') return (c - 'A') / 3 + 2;
    if (c >= 'R' && c <= 'S') return 7;
    if (c >= 'T' && c <= 'V') return 8;
    if (c >= 'W' && c <= 'Y') return 9;
    return -1;
}

int main(void) {

    int ok = (map_phone_char('A') == 2) && (map_phone_char('P') == 7) && (map_phone_char('R') == 7);
    printf("%s: UVa 755 - 487--3279\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
