/*
 * ==========================================================================
 * UVa 10279 - Mine Sweeper
 * Title-CN: 踩地雷盤面模擬
 * Difficulty: Easy
 * Tags: Grid Simulation
 * URL: https://onlinejudge.org/external/102/10279.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Display opened cells showing adjacent mine counts, and reveal all mines if an open cell is a mine.
 *
 * [中文] 題目說明:
 *     輸出踩地雷棋盤：已點開處顯示相鄰地雷數；若點中地雷則引爆顯示所有地雷位置。
 *
 * [EN] Approach:
 *     Count 8-neighbor mines for each cell. If any touched cell is a mine ('*'), copy all mines to the output board.
 * [中文] 思路:
 *     計算每格 8 鄰居地雷數；若觸摸到的格子中有地雷，則將棋盤上所有地雷位置全部揭露。
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

void reveal_mines(int n, char mines[10][10], char touches[10][10], char out[10][10]) {
    bool exploded = false;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (touches[i][j] == 'x' && mines[i][j] == '*') exploded = true;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (touches[r][c] == 'x') {
                int count = 0;
                for (int dr = -1; dr <= 1; dr++)
                    for (int dc = -1; dc <= 1; dc++) {
                        int nr = r + dr, nc = c + dc;
                        if (nr >= 0 && nr < n && nc >= 0 && nc < n && mines[nr][nc] == '*') count++;
                    }
                out[r][c] = count + '0';
            } else {
                out[r][c] = (exploded && mines[r][c] == '*') ? '*' : '.';
            }
        }
    }
}

int main(void) {

    char m[10][10] = {".*", ".."}, t[10][10] = {"x.", ".."}, o[10][10];
    reveal_mines(2, m, t, o);
    int ok = (o[0][0] == '1' && o[0][1] == '.');
    printf("%s: UVa 10279 - Mine Sweeper\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
