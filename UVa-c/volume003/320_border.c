/*
 * ==========================================================================
 * UVa 320 - Border
 * Title-CN: 走邊界圖案繪製
 * Difficulty: Medium
 * Tags: Simulation, Grid, Bitmap
 * URL: https://onlinejudge.org/external/3/320.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given a start point and direction moves along the border of an object on a 32x32 grid, mark the boundary cells and output the bitmap.
 *
 * [中文] 題目描述:
 *     給定在 32x32 網格上的起點與沿著物體外框走的移動指令（E, W, N, S），標記所有相鄰邊界的單元格並繪製點陣圖。
 *
 * [EN] Approach:
 *     Simulate the border walk. Moving E fills cell (x, y-1); N fills (x, y); W fills (x-1, y); S fills (x-1, y-1).
 *
 * [中文] 解題思維:
 *     模擬邊界行走路徑：向東走標記 (x, y-1)，向北走標記 (x, y)，向西走標記 (x-1, y)，向南走標記 (x-1, y-1)。
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

void trace_border(int sx, int sy, const char *path, char grid[32][33]) {
    for (int r = 0; r < 32; r++) {
        for (int c = 0; c < 32; c++) grid[r][c] = '.';
        grid[r][32] = '\0';
    }
    int x = sx, y = sy;
    for (int i = 0; path[i] && path[i] != '.'; i++) {
        if (path[i] == 'E') {
            if (y - 1 >= 0 && y - 1 < 32 && x >= 0 && x < 32) grid[y - 1][x] = 'X';
            x++;
        } else if (path[i] == 'N') {
            if (y >= 0 && y < 32 && x >= 0 && x < 32) grid[y][x] = 'X';
            y++;
        } else if (path[i] == 'W') {
            if (y >= 0 && y < 32 && x - 1 >= 0 && x - 1 < 32) grid[y][x - 1] = 'X';
            x--;
        } else if (path[i] == 'S') {
            if (y - 1 >= 0 && y - 1 < 32 && x - 1 >= 0 && x - 1 < 32) grid[y - 1][x - 1] = 'X';
            y--;
        }
    }
}

int main(void) {
    char g[32][33];
    trace_border(1, 1, "ENWS.", g);
    // Loop around cell (1, 1): fills cell (0, 1)
    int ok = (g[0][1] == 'X');
    printf("%s: UVa 320 - Border\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
