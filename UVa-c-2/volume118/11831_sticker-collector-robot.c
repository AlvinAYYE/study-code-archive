/*
 * ==========================================================================
 * UVa 11831 - Sticker Collector Robot
 * Title-CN: 貼紙收集機器人行進方向模擬
 * Difficulty: UVa Star 2
 * Tags: simulation, 2d-grid
 * URL: https://onlinejudge.org/external/118/11831.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Simulate a robot on a grid following 'D' (turn right 90 deg), 'E' (turn left 90 deg), and 'F' (forward 1 step). Collect stickers '*'.
 *
 * [中文] 題目說明:
 *     在帶有障礙物 '#' 的網格上模擬機器人移動指令：右轉 'D'、左轉 'E'、前進 'F'，並收集沿途踩踏到的貼紙 '*'。
 *
 * [EN] Approach:
 *     Maintain direction orientation (N, L, S, O). Execute commands: ignore forward moves into pillars '#' or grid boundaries. Collect stickers upon entry.
 * [中文] 思路:
 *     以方向變數記錄目前朝向 (北東南西)，依序執行指令：遇到障礙物或邊界則原地踏步，踏入貼紙格時收集貼紙並標記為空地。
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

int solve_uva11831(int R, int C, char g[20][20], const char *inst, int sr, int sc, char sdir) {
    int dr[] = {-1, 0, 1, 0}, dc[] = {0, 1, 0, -1}; // N, E, S, W
    int dir = 0;
    if (sdir == 'N') dir = 0;
    else if (sdir == 'L') dir = 1;
    else if (sdir == 'S') dir = 2;
    else if (sdir == 'O') dir = 3;

    int r = sr, c = sc, stickers = 0;
    for (int i = 0; inst[i]; i++) {
        if (inst[i] == 'D') dir = (dir + 1) % 4;
        else if (inst[i] == 'E') dir = (dir + 3) % 4;
        else if (inst[i] == 'F') {
            int nr = r + dr[dir], nc = c + dc[dir];
            if (nr >= 0 && nr < R && nc >= 0 && nc < C && g[nr][nc] != '#') {
                r = nr; c = nc;
                if (g[r][c] == '*') {
                    stickers++;
                    g[r][c] = '.';
                }
            }
        }
    }
    return stickers;
}

int main(void) {

    char g[20][20] = {"..*", "..."};
    int s = solve_uva11831(2, 3, g, "FF", 0, 0, 'L'); // Move East 2 steps to (0, 2)
    int ok = (s == 1);
    printf("%s: UVa 11831 - Sticker Collector Robot\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
