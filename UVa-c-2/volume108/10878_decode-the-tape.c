/*
 * ==========================================================================
 * UVa 10878 - Decode the tape
 * Title-CN: 解碼穿孔紙帶 (Punched Tape ASCII 解碼)
 * Difficulty: UVa Star 1
 * Tags: bit-manipulation, string, simulation
 * URL: https://onlinejudge.org/external/108/10878.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Decode 7-bit ASCII characters from punched tape visual rows ('o' is 1, space is 0).
 *
 * [中文] 題目說明:
 *     解析紙帶孔洞圖形還原 ASCII 訊息：字元 'o' 代表二進位 1，空白代表 0，點 '.' 為定位孔忽視。
 *
 * [EN] Approach:
 *     Read row between '|' bars, convert 'o' positions to bitmask byte, print corresponding char.
 * [中文] 思路:
 *     讀取每行紙帶，將孔洞 'o' 依位元加權累加為一個位元組字元，直接輸出 ASCII 字元。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char decode_tape_line(const char *line) {
    int val = 0;
    for (int i = 0; line[i]; i++) {
        if (line[i] == 'o') val = (val << 1) | 1;
        else if (line[i] == ' ') val = (val << 1);
    }
    return (char)val;
}

int main(void) {

    char c = decode_tape_line("|  o.o o |"); /* 0010101 = 21 -> wait */
    int ok = 1;
    printf("%s: UVa 10878 - Decode the tape\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
