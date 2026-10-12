/*
 * ==========================================================================
 * UVa 573 - The Snail
 * Title-CN: 蝸牛爬井
 * Difficulty: UVa Star 1
 * Tags: simulation
 * ==========================================================================
 * [EN] Problem: Snail climbs up U feet daily with fatigue factor F, slips D feet nightly. Determine success/failure day.
 * [中文] 題目說明: 蝸牛白天向上爬 U 英尺（每天疲勞扣減 F% 初速），夜間滑落 D 英尺。求爬出井或滑落出井底的天數。
 * [EN] Approach: Step-by-step daytime and nighttime height tracking.
 * [中文] 思路: 依天逐日模擬白天爬升與夜晚滑落高度。
 * ==========================================================================
 */
#include <stdio.h>

int solve_uva573(double h, double u, double d, double f, int *success) {
    double cur = 0.0;
    double step = u;
    double fatigue = u * (f / 100.0);
    int day = 0;
    while (1) {
        day++;
        if (step > 0.0) cur += step;
        if (cur > h) { *success = 1; return day; }
        cur -= d;
        if (cur < 0.0) { *success = 0; return day; }
        step -= fatigue;
    }
}

int main(void) {
    int succ;
    int day = solve_uva573(6, 3, 1, 10, &succ);
    int ok = (succ == 1 && day == 3);
    printf("%s: UVa 573 - The Snail\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
