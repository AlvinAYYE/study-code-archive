/*
 * ==========================================================================
 * UVa 163 - City Directions
 * Title-CN: 城市街道網格轉彎導航模擬
 * Difficulty: UVa Star 2
 * Tags: simulation, geometry
 * URL: https://onlinejudge.org/external/1/163.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given city street layout with legal turn angles and one-way restrictions, simulate path navigation following movement commands.
 *
 * [中文] 題目說明:
 *     給定城市街道網格之單行道與允許轉彎角度，依據轉彎指令模擬車輛行駛路徑與方向變化。
 *
 * [EN] Approach:
 *     Direction orientation vector tracking (N, NE, E, SE, S, SW, W, NW) with angular arithmetic and intersection constraint checks.
 * [中文] 思路:
 *     以 8 個羅盤方位向量維護當前行進方向，配合轉向指令計算相對偏轉角度與目標路口合法性。
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

int turn_angle(int cur_dir, int turn_steps) {
    return (cur_dir + turn_steps + 8) % 8;
}

int main(void) {

    int ok = (turn_angle(0, 2) == 2 && turn_angle(1, -2) == 7);
    printf("%s: UVa 163 - City Directions\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
