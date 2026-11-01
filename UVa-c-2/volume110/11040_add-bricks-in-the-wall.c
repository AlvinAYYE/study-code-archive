/*
 * ==========================================================================
 * UVa 11040 - Add bricks in the wall
 * Title-CN: 牆面磚塊補全
 * Difficulty: Easy
 * Tags: Math, Simulation
 * URL: https://onlinejudge.org/external/110/11040.pdf
 * ==========================================================================
 * [EN] Problem:
 *     A triangular wall of 9 rows has bricks satisfying brick[r][c] = brick[r+1][c] + brick[r+1][c+1]. Fill missing bricks given odd rows.
 *
 * [中文] 題目說明:
 *     9 層三角形磚牆滿足每塊磚數值等於下方兩相鄰磚之和，已知奇數層磚塊數值，補全所有未知磚塊。
 *
 * [EN] Approach:
 *     Using 3 known bricks in a 2-level triangle (top, bottom-left, bottom-right): bottom-mid = (top - b_left - b_right) / 2. Then propagate upwards.
 * [中文] 思路:
 *     對於頂部已知磚 A 與下方間隔已知的兩磚 B, C，中間磚為 (A - B - C) / 2，依此逐層推算並向上加總補齊。
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

int find_middle_brick(int top, int b_left, int b_right) {
    return (top - b_left - b_right) / 2;
}

int main(void) {

    // top = (b_left + mid) + (mid + b_right) = b_left + b_right + 2*mid
    int mid = find_middle_brick(10, 2, 4); // 2 + 4 + 2*mid = 10 -> mid = 2
    int ok = (mid == 2);
    printf("%s: UVa 11040 - Add bricks in the wall\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
