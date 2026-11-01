/*
 * ==========================================================================
 * UVa 11494 - Queen
 * Title-CN: 西洋棋皇后移動最少步數判定
 * Difficulty: UVa Star 1
 * Tags: basics, math
 * URL: https://onlinejudge.org/external/114/11494.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find minimum moves for a chess queen to move from (x1, y1) to (x2, y2) on an 8x8 board: 0 if same, 1 if aligned, else 2.
 *
 * [中文] 題目說明:
 *     計算西洋棋皇后從 (x1, y1) 移動至 (x2, y2) 的最少步數：同位置為 0 步，同行/同列/同斜線為 1 步，其餘為 2 步。
 *
 * [EN] Approach:
 *     Check conditions: if x1==x2 and y1==y2 return 0; if x1==x2 or y1==y2 or abs(x1-x2)==abs(y1-y2) return 1; else return 2.
 * [中文] 思路:
 *     起訖點相同回傳 0；在同橫行、同縱列或兩對角斜線上回傳 1；其餘任意位置至多 2 步必可到達。
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

int solve_uva11494(int x1, int y1, int x2, int y2) {
    if (x1 == x2 && y1 == y2) return 0;
    int dx = x1 - x2, dy = y1 - y2;
    if (dx < 0) dx = -dx;
    if (dy < 0) dy = -dy;
    if (x1 == x2 || y1 == y2 || dx == dy) return 1;
    return 2;
}

int main(void) {

    int ok = (solve_uva11494(1, 1, 1, 1) == 0 &&
              solve_uva11494(1, 1, 1, 5) == 1 &&
              solve_uva11494(1, 1, 5, 5) == 1 &&
              solve_uva11494(1, 1, 2, 5) == 2);
    printf("%s: UVa 11494 - Queen\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
