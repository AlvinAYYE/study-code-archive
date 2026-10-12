/*
 * ==========================================================================
 * UVa 12468 - Zapping
 * Title-CN: 遙控器轉台最短按鍵次數
 * Difficulty: UVa Star 1
 * Tags: math
 * ==========================================================================
 * [EN] Problem: Channel numbers 0..99 wrap around. Find minimal presses of up/down buttons from channel a to b.
 * [中文] 題目說明: 電視頻道 0 到 99 首尾循環相接，求從頻道 a 切換到頻道 b 所需的最少上下按鍵次數。
 * [EN] Approach: diff = abs(a - b). Min presses = min(diff, 100 - diff).
 * [中文] 思路: 絕對差值 diff 與環形反向差值 100 - diff 取較小者。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>

int solve_uva12468(int a, int b) {
    int diff = abs(a - b);
    return (diff < 100 - diff) ? diff : (100 - diff);
}

int main(void) {
    int ok = (solve_uva12468(0, 99) == 1) && (solve_uva12468(10, 20) == 10);
    printf("%s: UVa 12468 - Zapping\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
