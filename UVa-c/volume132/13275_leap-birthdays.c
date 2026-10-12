/*
 * ==========================================================================
 * UVa 13275 - Leap Birthdays
 * Title-CN: 閏年 2 月 29 日生日慶祝次數
 * Difficulty: UVa Star 1
 * Tags: math
 * ==========================================================================
 * [EN] Problem: Count birthday celebrations up to year Q for someone born on D/M/Y.
 * [中文] 題目說明: 計算生於 D/M/Y 的人至 Q 年為止能慶祝生日的次數（非閏日每年皆能慶祝，2/29 則僅在閏年慶祝）。
 * [EN] Approach: If not Feb 29, return Q - Y; else count leap years in (Y, Q].
 * [中文] 思路: 若非 2 月 29 則為 Q - Y；若是 2 月 29 則統計期間內的閏年個數。
 * ==========================================================================
 */
#include <stdio.h>

static int is_leap(int y) {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

int count_birthdays(int d, int m, int y, int q) {
    if (d != 29 || m != 2) return q - y;
    int cnt = 0;
    for (int yr = y + 1; yr <= q; yr++) if (is_leap(yr)) cnt++;
    return cnt;
}

int main(void) {
    int ok = (count_birthdays(29, 2, 2000, 2016) == 4);
    printf("%s: UVa 13275 - Leap Birthdays\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
