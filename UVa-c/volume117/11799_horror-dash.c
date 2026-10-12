/*
 * ==========================================================================
 * UVa 11799 - Horror Dash
 * Title-CN: 恐怖衝刺
 * Difficulty: UVa Star 1
 * Tags: math, basic-io
 * URL: https://onlinejudge.org/external/117/11799.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Clown must run at least as fast as the fastest running student. Find maximum speed.
 *
 * [中文] 題目說明:
 *     小丑需要跑得比所有受驚嚇奔跑的學生都快，求小丑所需的最小速度（數列的最大值）。
 *
 * [EN] Approach:
 *     Single pass max value search.
 * [中文] 思路:
 *     單次線性遍歷求最大速度值。
 * ==========================================================================
 */
#include <stdio.h>

int solve_uva11799(int n, const int *speeds) {
    int max_s = 0;
    for (int i = 0; i < n; i++) {
        if (speeds[i] > max_s) max_s = speeds[i];
    }
    return max_s;
}

int main(void) {
    int sp[5] = {9, 3, 5, 2, 6};
    int ok = (solve_uva11799(5, sp) == 9);
    printf("%s: UVa 11799 - Horror Dash\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
