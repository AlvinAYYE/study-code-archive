/*
 * ==========================================================================
 * UVa 445 - Marvelous Mazes
 * Title-CN: 奇妙的迷宮解碼繪圖
 * Difficulty: UVa Star 1
 * Tags: string, simulation
 * ==========================================================================
 * [EN] Problem: Decode maze format: consecutive digits sum to frequency of next character ('b' is space, '!' is newline).
 * [中文] 題目說明: 迷宮輸出解碼：連續數字累加為後續字元的重複次數，'b' 代表空格，'!' 代表換行。
 * [EN] Approach: Accumulate digit sum, repeat character printing.
 * [中文] 思路: 累加連續數字和，遇到非數字字元則重複輸出對應次數。
 * ==========================================================================
 */
#include <stdio.h>
#include <ctype.h>

void solve_uva445(FILE *in, FILE *out) {
    int repeat = 0;
    int ch;

    while ((ch = fgetc(in)) != EOF) {
        if (ch >= '0' && ch <= '9') {
            repeat += ch - '0';
        } else if (ch == '!') {
            fputc('\n', out);
            repeat = 0;
        } else if (ch == '\n') {
            fputc('\n', out);
            repeat = 0;
        } else if (ch != '\r') {
            int output = ch == 'b' ? ' ' : ch;
            int i;
            for (i = 0; i < repeat; i++) {
                fputc(output, out);
            }
            repeat = 0;
        }
    }
}

int main(void) {
    solve_uva445(stdin, stdout);
    return 0;
}
