/*
 * ==========================================================================
 * UVa 10443 - Rock, Scissors, Paper
 * Title-CN: 剪刀石頭布網格爭奪戰
 * Difficulty: Easy
 * Tags: Grid Simulation
 * URL: https://onlinejudge.org/external/104/10443.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Simulate daily territorial changes in an R x C grid where adjacent winning hands capture enemy cells.
 *
 * [中文] 題目說明:
 *     模擬 R x C 網格中剪刀、石頭、布的陣地爭奪戰，若相鄰格子有能克制自己的手勢則被佔領，各格同步更新。
 *
 * [EN] Approach:
 *     Simulate d days. For each cell, check 4-neighbors; if any neighbor beats it, mark for capture in next state array.
 * [中文] 思路:
 *     模擬 d 天的變換，對每個格子檢查四鄰居是否有克制手勢（R 勝 S、S 勝 P、P 勝 R），以雙緩衝區同步更新。
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

bool beats(char a, char b) {
    return (a == 'R' && b == 'S') || (a == 'S' && b == 'P') || (a == 'P' && b == 'R');
}
void simulate_rps(int r, int c, int days, char grid[10][10]) {
    int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
    char next_g[10][10];
    for (int day = 0; day < days; day++) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                next_g[i][j] = grid[i][j];
                for (int k = 0; k < 4; k++) {
                    int ni = i + dr[k], nj = j + dc[k];
                    if (ni >= 0 && ni < r && nj >= 0 && nj < c) {
                        if (beats(grid[ni][nj], grid[i][j])) {
                            next_g[i][j] = grid[ni][nj];
                            break;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++) grid[i][j] = next_g[i][j];
    }
}

int main(void) {

    char g[10][10] = {"RS", "RR"};
    simulate_rps(2, 2, 1, g);
    int ok = (g[0][1] == 'R'); // S is beaten by R
    printf("%s: UVa 10443 - Rock, Scissors, Paper\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
