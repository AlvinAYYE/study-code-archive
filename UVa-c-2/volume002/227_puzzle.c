/*
 * ==========================================================================
 * UVa 227 - Puzzle
 * Title-CN: 滑動拼圖操作模擬
 * Difficulty: UVa Star 2
 * Tags: simulation
 * URL: https://onlinejudge.org/external/2/227.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Simulate a 5x5 sliding letter puzzle: an empty space moves Above (A), Below (B), Left (L), or Right (R). Output final grid or illegal move flag.
 *
 * [中文] 題目說明:
 *     模擬 5x5 字母滑動拼圖：空格可向指定方向滑動 (A=上, B=下, L=左, R=右)。輸出移動後的最終盤面，或在越界時標記此拼圖無合法設定。
 *
 * [EN] Approach:
 *     Track empty cell position (r, c). For each command, check boundary constraints and swap empty tile with adjacent tile.
 * [中文] 思路:
 *     追蹤空白格位置 (r, c)，遇到 A/B/L/R 指令時檢驗是否越界；若合法則與相鄰格子互換字元，若越界則標記非法狀態。
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

int move_puzzle(char board[5][6], int *r, int *c, char cmd) {
    int nr = *r, nc = *c;
    if (cmd == 'A') nr--;
    else if (cmd == 'B') nr++;
    else if (cmd == 'L') nc--;
    else if (cmd == 'R') nc++;
    else return 0;

    if (nr < 0 || nr >= 5 || nc < 0 || nc >= 5) return 0;
    board[*r][*c] = board[nr][nc];
    board[nr][nc] = ' ';
    *r = nr; *c = nc;
    return 1;
}

int main(void) {

    char b[5][6] = {"TRGSJ", "XDOKI", "M VLN", "WPABE", "UQRHY"};
    int r = 2, c = 1;
    int ok = move_puzzle(b, &r, &c, 'A');
    ok = ok && (r == 1 && c == 1 && b[1][1] == ' ');
    printf("%s: UVa 227 - Puzzle\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
