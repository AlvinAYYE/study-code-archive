/*
 * ==========================================================================
 * UVa 12503 - Robot Instructions
 * Title-CN: 機器人移動指令歷史回溯
 * Difficulty: UVa Star 1
 * Tags: simulation
 * URL: https://onlinejudge.org/external/125/12503.pdf
 * ==========================================================================
 * [EN] Problem:
 *     A robot moves along a line. Instructions are 'LEFT', 'RIGHT', or 'SAME AS i' (repeating instruction i). Find final coordinate.
 *
 * [中文] 題目說明:
 *     機器人在一維數線上移動，指令可能為 LEFT (-1)、RIGHT (+1) 或 SAME AS i (重複第 i 個指令的動作)。求最後停在的座標位置。
 *
 * [EN] Approach:
 *     Store delta for each instruction 1..N. If instruction references past step i, copy delta[i]. Sum all deltas.
 * [中文] 思路:
 *     以陣列儲存各步指令造成的位移值 (+1 或 -1)，遇到 SAME AS i 則直接複製第 i 步之位移，最後加總全部位移。
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

int solve_uva12503(int n, int *types, int *refs) {
    // types: -1=LEFT, 1=RIGHT, 0=SAME AS
    int moves[105];
    int pos = 0;
    for (int i = 1; i <= n; i++) {
        if (types[i] != 0) moves[i] = types[i];
        else moves[i] = moves[refs[i]];
        pos += moves[i];
    }
    return pos;
}

int main(void) {

    int t[] = {0, -1, 1, 0};
    int r[] = {0, 0, 0, 2}; // step 3 is SAME AS 2
    int p = solve_uva12503(3, t, r);
    int ok = (p == 1); // -1 + 1 + 1 = 1
    printf("%s: UVa 12503 - Robot Instructions\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
