/*
 * ==========================================================================
 * UVa 11677 - Alarm Clock
 * Title-CN: 鬧鐘剩餘睡眠分鐘數
 * Difficulty: UVa Star 1
 * Tags: math, simulation
 * URL: https://onlinejudge.org/external/116/11677.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Compute minutes of sleep between bedtime (H1:M1) and alarm time (H2:M2).
 *
 * [中文] 題目說明:
 *     計算從當前睡覺時間 (H1:M1) 到鬧鐘響起時間 (H2:M2) 之間相隔的睡眠分鐘數。
 *
 * [EN] Approach:
 *     Convert both times to minutes from midnight: (t2 - t1 + 1440) % 1440.
 * [中文] 思路:
 *     將兩時間皆轉換為從午夜 0:00 起算的分鐘數，計算 (t2 - t1 + 1440) % 1440 即可正確處理跨日情形。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva11677(int h1, int m1, int h2, int m2) {
    int t1 = h1 * 60 + m1;
    int t2 = h2 * 60 + m2;
    return (t2 - t1 + 1440) % 1440;
}

int main(void) {

    int ok = (solve_uva11677(1, 5, 1, 10) == 5) && (solve_uva11677(23, 50, 0, 30) == 40);
    printf("%s: UVa 11677 - Alarm Clock\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
