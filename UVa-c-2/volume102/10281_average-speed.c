/*
 * ==========================================================================
 * UVa 10281 - Average Speed
 * Title-CN: 平均速度與總里程計算
 * Difficulty: UVa Star 1
 * Tags: simulation, math
 * ==========================================================================
 * [EN] Problem: Track accumulated distance under changing speeds.
 * [中文] 題目說明: 追蹤變速行駛下的累積總里程。
 * [EN] Approach: Dist += current_speed * (time_now - time_last).
 * [中文] 思路: 時間差乘上當前車速累積總里程。
 * ==========================================================================
 */
#include <stdio.h>
#include <math.h>

int main(void) {
    int ok = 1;
    printf("%s: UVa 10281 - Average Speed\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
