/*
 * ==========================================================================
 * UVa 11956 - Brainfuck
 * Title-CN: Brainfuck 解釋器模擬
 * Difficulty: Easy
 * Tags: Simulation, Interpreter
 * URL: https://onlinejudge.org/external/119/11956.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Simulate Brainfuck memory operations on a 100-byte circular array initialized to 0 with commands: '>', '<', '+', '-', '.' (loop commands '[' and ']' do not appear).
 *
 * [中文] 題目說明:
 *     在 100 位元組的循環數組上模擬 Brainfuck 記憶體操作（支援 > 右移、< 左移、+ 加一、- 減一，遇 256 取模）。
 *
 * [EN] Approach:
 *     Maintain pointer ptr (0 to 99) with wrap-around, and byte values bytes[ptr] modulo 256.
 * [中文] 思路:
 *     維護指針 ptr (模 100 循環) 與記憶體值 byte[ptr] (模 256 循環)，遍歷指令字符更新狀態。
 * ==========================================================================
 * UVa Online Judge Submission Template:
 * #include <stdio.h>
 * #include <stdlib.h>
 * #include <string.h>
 * #include <math.h>
 *
 * int main(void) {
 *     // Read input and call logic function
 *     return 0;
 * }
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

void run_brainfuck(const char *code, unsigned char mem[100]) {
    memset(mem, 0, 100);
    int ptr = 0;
    for (int i = 0; code[i]; i++) {
        if (code[i] == '>') ptr = (ptr + 1) % 100;
        else if (code[i] == '<') ptr = (ptr + 99) % 100;
        else if (code[i] == '+') mem[ptr] = (mem[ptr] + 1) % 256;
        else if (code[i] == '-') mem[ptr] = (mem[ptr] + 255) % 256;
    }
}

int main(void) {

    unsigned char m[100];
    run_brainfuck("++>+++", m);
    int ok = (m[0] == 2 && m[1] == 3);
    printf("%s: UVa 11956 - Brainfuck\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
