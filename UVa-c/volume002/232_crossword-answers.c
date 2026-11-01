/*
 * ==========================================================================
 * UVa 232 - Crossword Answers
 * Title-CN: 填字遊戲題號編號與單詞提取
 * Difficulty: UVa Star 1
 * Tags: string, 2d-grid
 * URL: https://onlinejudge.org/external/2/232.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given an r x c crossword grid with black cells '*', assign clue numbers to cells that start across/down words and print all words.
 *
 * [中文] 題目說明:
 *     在包含黑格 '*' 的 r x c 填字遊戲網格中，為所有作為橫向或縱向單詞開頭的格子編定題號並依序提取單詞。
 *
 * [EN] Approach:
 *     Number a cell if it is not '*' and (left is '*' or edge, OR above is '*' or edge). Collect horizontal and vertical words.
 * [中文] 思路:
 *     非黑格且其上方或左方為黑格/邊界之格子依序給予流水號題號，分別橫向與縱向掃描輸出單詞。
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

int is_start_cell(int r, int c, int R, int C, char g[10][10]) {
    if (g[r][c] == '*') return 0;
    int left_border = (c == 0 || g[r][c - 1] == '*');
    int up_border = (r == 0 || g[r - 1][c] == '*');
    return (left_border || up_border);
}

int main(void) {

    char g[10][10] = {"AT*", "*O*"};
    int ok = is_start_cell(0, 0, 2, 3, g) && is_start_cell(0, 1, 2, 3, g);
    printf("%s: UVa 232 - Crossword Answers\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
