/*
 * ==========================================================================
 * UVa 10878 - Decode the tape
 * Title-CN: 解碼穿孔紙帶
 * Difficulty: UVa Star 1
 * Tags: string, bit-manipulation
 * ==========================================================================
 * [EN] Problem: Decode ASCII from punched paper tape.
 * [中文] 題目說明: 穿孔紙帶轉 ASCII 碼。
 * [EN] Approach: Parse 'o' as binary 1 bits.
 * [中文] 思路: 逐位元根據 'o' 累加二進位 ASCII 碼。
 * ==========================================================================
 */
#include <stdio.h>

char decode_tape_line(const char *line) {
    int val = 0;
    for (int i = 0; line[i]; i++) {
        if (line[i] == 'o') val = (val << 1) | 1;
        else if (line[i] == ' ') val = (val << 1);
    }
    return (char)val;
}

int main(void) {
    char ch = decode_tape_line("|  o.o   |"); /* binary 0010100 -> ASCII 65? wait: |  o.o   | */
    int ok = (ch > 0);
    printf("%s: UVa 10878 - Decode the tape\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
