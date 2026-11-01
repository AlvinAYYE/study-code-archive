/*
 * ==========================================================================
 * UVa 10550 - Combination Lock
 * Title-CN: 轉盤密碼鎖旋轉度數
 * Difficulty: UVa Star 1
 * Tags: math, simulation
 * URL: https://onlinejudge.org/external/105/10550.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Compute total degrees of rotation to open lock with 40 ticks: 2 full clockwise turns, 1 counter-clockwise, then to 3rd combo.
 *
 * [中文] 題目說明:
 *     計算開啟 40 格轉盤密碼鎖旋轉的總角度：順時針轉 2 整圈、逆時針轉 1 整圈，最後轉至第 3 個密碼刻度。
 *
 * [EN] Approach:
 *     Base turns = 720 + 360 = 1080 deg. Each tick is 360/40 = 9 deg. Clockwise: (cur - next + 40)%40; Counter-clockwise: (next - cur + 40)%40.
 * [中文] 思路:
 *     固定旋轉角度為 2圈 + 1圈 = 1080度。每刻度 9 度。順時針步數為 (a-b+40)%40，逆時針為 (c-b+40)%40，累加總角度。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva10550(int init, int c1, int c2, int c3) {
    int deg = 1080;
    deg += ((init - c1 + 40) % 40) * 9;
    deg += ((c2 - c1 + 40) % 40) * 9;
    deg += ((c2 - c3 + 40) % 40) * 9;
    return deg;
}

int main(void) {

    int ok = (solve_uva10550(0, 30, 0, 30) == 1350);
    printf("%s: UVa 10550 - Combination Lock\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
