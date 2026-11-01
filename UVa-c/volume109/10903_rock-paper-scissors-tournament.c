/*
 * ==========================================================================
 * UVa 10903 - Rock-Paper-Scissors Tournament
 * Title-CN: 剪刀石頭布錦標賽勝率計算
 * Difficulty: UVa Star 1
 * Tags: simulation, math
 * URL: https://onlinejudge.org/external/109/10903.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Compute win rate W / (W + L) for each player in rock-paper-scissors tournament (draws ignored).
 *
 * [中文] 題目說明:
 *     計算每位選手在剪刀石頭布錦標賽中的勝率 W / (W + L)，平局忽略不計；若無有效對局輸出破折號 '-'。
 *
 * [EN] Approach:
 *     Track wins and losses per player. Ignore draws. Output W / (W + L) rounded to 3 decimal places.
 * [中文] 思路:
 *     陣列記錄每位選手的勝場數 W 與敗場數 L。平手不計入。勝率為 (double)W / (W + L)。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double calc_win_rate_10903(int w, int l) {
    if (w + l == 0) return -1.0;
    return (double)w / (w + l);
}

int main(void) {

    int ok = (fabs(calc_win_rate_10903(2, 2) - 0.5) < 1e-4);
    printf("%s: UVa 10903 - Rock-Paper-Scissors Tournament\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
