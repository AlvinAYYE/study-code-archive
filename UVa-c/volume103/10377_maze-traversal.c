/*
 * ==========================================================================
 * UVa 10377 - Maze Traversal
 * Title-CN: 迷宮機器人巡航
 * Difficulty: Easy
 * Tags: Simulation, Grid
 * URL: https://onlinejudge.org/external/103/10377.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Simulate a robot moving in a grid maze executing commands: R (turn right), L (turn left), F (move forward if not wall), Q (quit).
 *
 * [中文] 題目說明:
 *     模擬機器人在網格迷宮中根據指令序列巡航（R: 右轉, L: 左轉, F: 前進遇牆停, Q: 退出），求最終座標與朝向。
 *
 * [EN] Approach:
 *     Track position (r, c) and orientation (N=0, E=1, S=2, W=3). Update orientation on L/R, update position on F if cell is not '*'.
 * [中文] 思路:
 *     維護機器人位置與朝向（北東南西 0..3），遇到轉向指令更新方向，前進指令遇空格才移動。
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

void run_robot(int R, int C, const char maze[10][10], int *r, int *c, char *dir, const char *cmds) {
    int d = 0; // 0:N, 1:E, 2:S, 3:W
    if (*dir == 'E') d = 1; else if (*dir == 'S') d = 2; else if (*dir == 'W') d = 3;
    int dr[] = {-1, 0, 1, 0}, dc[] = {0, 1, 0, -1};
    const char dir_ch[] = "NESW";
    for (int i = 0; cmds[i] && cmds[i] != 'Q'; i++) {
        if (cmds[i] == 'R') d = (d + 1) % 4;
        else if (cmds[i] == 'L') d = (d + 3) % 4;
        else if (cmds[i] == 'F') {
            int nr = *r + dr[d], nc = *c + dc[d];
            if (nr >= 0 && nr < R && nc >= 0 && nc < C && maze[nr][nc] != '*') {
                *r = nr; *c = nc;
            }
        }
    }
    *dir = dir_ch[d];
}

int main(void) {

    char m[10][10] = {"* *", "* *", "***"};
    int r = 1, c = 1; char dir = 'N';
    run_robot(3, 3, m, &r, &c, &dir, "FQ");
    int ok = (r == 0 && c == 1 && dir == 'N');
    printf("%s: UVa 10377 - Maze Traversal\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
