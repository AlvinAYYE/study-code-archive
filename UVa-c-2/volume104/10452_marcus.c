/*
 * ==========================================================================
 * UVa 10452 - Marcus
 * Title-CN: 古墓印第安納瓊斯路徑字符導航
 * Difficulty: UVa Star 2
 * Tags: graph, dfs
 * URL: https://onlinejudge.org/external/104/10452.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Navigate Marcus across a stone cobblestone grid from '@' to '#' following the exact sequence 'IEHOVA#' using steps 'forth', 'left', 'right'.
 *
 * [中文] 題目說明:
 *     在古墓石磚網格中導引瓊斯從 '@' 走到 '#'，嚴格依序踩踏 "IEHOVA#" 字元，輸出每步動作 (forth, left, right)。
 *
 * [EN] Approach:
 *     DFS search from '@'. At each step, test 3 legal moves (forward, left, right) matching the next character in "IEHOVA#".
 * [中文] 思路:
 *     自 '@' 出發 DFS 搜尋：每次向正前方、左方、右方尋找與 "IEHOVA#" 當前字元吻合之相鄰格子推進並記錄指令清單。
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

int solve_uva10452(int m, int n, char g[10][10], int r, int c, int step_idx, char out_moves[][10]) {
    const char *target = "IEHOVA#";
    if (step_idx == 7) return 1;
    // Forth
    if (r - 1 >= 0 && g[r - 1][c] == target[step_idx]) {
        strcpy(out_moves[step_idx], "forth");
        if (solve_uva10452(m, n, g, r - 1, c, step_idx + 1, out_moves)) return 1;
    }
    // Left
    if (c - 1 >= 0 && g[r][c - 1] == target[step_idx]) {
        strcpy(out_moves[step_idx], "left");
        if (solve_uva10452(m, n, g, r, c - 1, step_idx + 1, out_moves)) return 1;
    }
    // Right
    if (c + 1 < n && g[r][c + 1] == target[step_idx]) {
        strcpy(out_moves[step_idx], "right");
        if (solve_uva10452(m, n, g, r, c + 1, step_idx + 1, out_moves)) return 1;
    }
    return 0;
}

int main(void) {

    char g[10][10] = {"#", "A", "V", "O", "H", "E", "I", "@"};
    char moves[7][10];
    int ok = solve_uva10452(8, 1, g, 7, 0, 0, moves);
    ok = ok && (strcmp(moves[0], "forth") == 0);
    printf("%s: UVa 10452 - Marcus\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
