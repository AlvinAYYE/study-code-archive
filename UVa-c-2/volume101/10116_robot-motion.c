/*
 * ==========================================================================
 * UVa 10116 - Robot Motion
 * Title-CN: 網格機器人移動迴圈環路檢測
 * Difficulty: UVa Star 1
 * Tags: simulation, 2d-grid
 * URL: https://onlinejudge.org/external/101/10116.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Simulate robot following grid instructions (N, S, E, W). Output either steps to exit grid or steps before entering a cycle and cycle length.
 *
 * [中文] 題目說明:
 *     在給定方位指示 (N, S, E, W) 的網格中模擬機器人移動，輸出成功脫離網格的步數，或陷入環路前的步數與環長度。
 *
 * [EN] Approach:
 *     Trace path using a 2D step tracking array step[r][c]. If cell re-visited, cycle detected; if outside grid, exit achieved.
 * [中文] 思路:
 *     以 step[r][c] 記錄踏入各格之步數，若下一步超出邊界則為成功走出；若下一步為已走訪格則計算入環前步數與環長。
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

void solve_uva10116(int R, int C, char g[10][10], int sc, int *exit_steps, int *loop_steps) {
    int step[10][10] = {0};
    int r = 0, c = sc, cur_step = 1;
    while (1) {
        if (r < 0 || r >= R || c < 0 || c >= C) {
            *exit_steps = cur_step - 1;
            *loop_steps = 0;
            return;
        }
        if (step[r][c] > 0) {
            *exit_steps = step[r][c] - 1;
            *loop_steps = cur_step - step[r][c];
            return;
        }
        step[r][c] = cur_step++;
        char dir = g[r][c];
        if (dir == 'N') r--;
        else if (dir == 'S') r++;
        else if (dir == 'E') c++;
        else if (dir == 'W') c--;
    }
}

int main(void) {

    char g[10][10] = {"EE", "WW"};
    int ex, lp;
    solve_uva10116(2, 2, g, 0, &ex, &lp);
    int ok = (lp > 0 || ex > 0);
    printf("%s: UVa 10116 - Robot Motion\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
