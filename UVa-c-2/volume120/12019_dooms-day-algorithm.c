/*
 * ==========================================================================
 * UVa 12019 - Doom's Day Algorithm
 * Title-CN: 末日審判演算法 (2011年星期幾計算)
 * Difficulty: UVa Star 1
 * Tags: math, date
 * URL: https://onlinejudge.org/external/120/12019.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine the day of week for any date in year 2011 (knowing 2011/1/1 was Saturday).
 *
 * [中文] 題目說明:
 *     計算 2011 年中任意日期 (月/日) 是星期幾 (已知 2011 年 1 月 1 日為星期六)。
 *
 * [EN] Approach:
 *     Sum days in preceding months plus day of month. Day of week = (start_offset + total_days - 1) % 7.
 * [中文] 思路:
 *     累計各月份天數計算自 1 月 1 日起的天數偏移量，對 7 取模對應星期陣列輸出。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

const char* solve_uva12019(int m, int d) {
    const char *days[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    int mdays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int passed = 0;
    for (int i = 1; i < m; i++) passed += mdays[i];
    passed += d - 1;
    return days[passed % 7];
}

int main(void) {

    int ok = (strcmp(solve_uva12019(1, 1), "Saturday") == 0) &&
             (strcmp(solve_uva12019(1, 6), "Thursday") == 0);
    printf("%s: UVa 12019 - Doom's Day Algorithm\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
