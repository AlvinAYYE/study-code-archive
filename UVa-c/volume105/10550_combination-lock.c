/*
 * ==========================================================================
 * UVa 10550 - Combination Lock
 * Title-CN: 密碼轉盤鎖
 * Difficulty: UVa Star 1
 * Tags: math, simulation
 * URL: https://onlinejudge.org/external/105/10550.pdf
 * ==========================================================================
 * [EN] Problem:
 *     A lock dial has 40 marks (0..39). Compute total degrees turned to open lock:
 *     2 full turns clockwise, stop at 1st num; 1 full turn counter-clockwise,
 *     stop at 2nd num; turn clockwise, stop at 3rd num.
 *
 * [中文] 題目說明:
 *     圓盤有 40 刻度（每刻度 9 度）。開鎖步驟：順時針轉 2 圈後轉至數字 a，
 *     逆時針轉 1 圈後轉至數字 b，順時針轉至數字 c。求圓盤總共轉動的度數。
 *
 * [EN] Approach:
 *     Base turns = 720 + 360 = 1080 deg. Clockwise (p to target) = (p - target + 40) % 40 * 9.
 *     Counter-clockwise (p to target) = (target - p + 40) % 40 * 9.
 * [中文] 思路:
 *     基礎整圈 720 + 360 = 1080 度。順時針位移刻度 (from - to + 40) % 40 * 9，逆時針 (to - from + 40) % 40 * 9。
 * ==========================================================================
 */
#include <stdio.h>

int solve_uva10550(int init, int a, int b, int c) {
    int deg = 1080; /* 2 + 1 full turns = 3 * 360 */
    deg += ((init - a + 40) % 40) * 9;  /* Clockwise to a */
    deg += ((b - a + 40) % 40) * 9;     /* Counter-clockwise to b */
    deg += ((b - c + 40) % 40) * 9;     /* Clockwise to c */
    return deg;
}

int main(void) {
    int res = solve_uva10550(0, 30, 0, 30);
    int ok = (res == 1350);
    printf("%s: UVa 10550 - Combination Lock\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
