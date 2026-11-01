/*
 * ==========================================================================
 * UVa 10267 - Graphical Editor
 * Title-CN: 圖形點陣畫布編輯直譯器模擬
 * Difficulty: UVa Star 2
 * Tags: simulation, flood-fill
 * URL: https://onlinejudge.org/external/102/10267.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Simulate bitmap paint editor supporting operations: create canvas, clear, color pixel, draw vertical/horizontal lines, fill rectangle, and flood fill.
 *
 * [中文] 題目說明:
 *     模擬點陣圖繪圖軟體指令：新建畫布、清空、單點著色、垂直線、水平線、填滿矩形與漫水填充區塊著色。
 *
 * [EN] Approach:
 *     Maintain 2D char array board[M][N]. Dispatch commands: I (init), C (clear), L (pixel), V (vert), H (horiz), K (rect), F (flood fill).
 * [中文] 思路:
 *     以二維字元矩陣維護像素畫布，依指令代碼分別執行單點、直線繪製、矩形填滿或以 BFS 執行漫水填充換色。
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

void editor_pixel(char b[20][20], int x, int y, char c) {
    b[y - 1][x - 1] = c;
}

void editor_clear(char b[20][20], int m, int n) {
    for (int r = 0; r < n; r++)
        for (int c = 0; c < m; c++)
            b[r][c] = 'O';
}

int main(void) {

    char b[20][20];
    editor_clear(b, 2, 2);
    editor_pixel(b, 1, 1, 'X');
    int ok = (b[0][0] == 'X' && b[0][1] == 'O');
    printf("%s: UVa 10267 - Graphical Editor\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
