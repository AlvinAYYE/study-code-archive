/*
 * ==========================================================================
 * UVa 11520 - Fill the Square
 * Title-CN: 填滿方格 (貪心網格著色)
 * Difficulty: Easy
 * Tags: Greedy, Grid
 * URL: https://onlinejudge.org/external/115/11520.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Fill empty cells of an N x N grid with uppercase letters such that no two adjacent cells share the same letter, lexicographically smallest.
 *
 * [中文] 題目說明:
 *     用大寫英文字母填滿 N x N 網格中未填的 '.' 格子，相鄰格字母不可相同，且字典序最小。
 *
 * [EN] Approach:
 *     Traverse row by row, column by column. For each '.', try 'A', 'B', 'C', ... and pick the first letter not matching any 4-neighbor.
 * [中文] 思路:
 *     依字典序由上至下、由左至右遍歷，對每個 '.' 依序嘗試 'A', 'B', 'C'... 挑選與相鄰四格皆不重複的最小字母。
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

void fill_square(int n, char g[10][10]) {
    int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (g[r][c] == '.') {
                for (char ch = 'A'; ch <= 'Z'; ch++) {
                    bool ok = true;
                    for (int k = 0; k < 4; k++) {
                        int nr = r + dr[k], nc = c + dc[k];
                        if (nr >= 0 && nr < n && nc >= 0 && nc < n && g[nr][nc] == ch) {
                            ok = false;
                            break;
                        }
                    }
                    if (ok) { g[r][c] = ch; break; }
                }
            }
        }
    }
}

int main(void) {

    char g[10][10] = {"..", ".."};
    fill_square(2, g);
    int ok = (g[0][0] == 'A' && g[0][1] == 'B' && g[1][0] == 'B' && g[1][1] == 'A');
    printf("%s: UVa 11520 - Fill the Square\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
