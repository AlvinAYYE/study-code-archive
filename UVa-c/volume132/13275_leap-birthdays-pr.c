/*
 * ==========================================================================
 * UVa 13275 - Leap Birthdays
 * Title-CN: 閏年閏日生日次數計算 (2月29日)
 * Difficulty: UVa Star 1
 * Tags: math, simulation
 * URL: https://onlinejudge.org/external/132/13275.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count how many real birthdays a person born on Feb 29 has celebrated between birth year and year Y.
 *
 * [中文] 題目說明:
 *     計算出生於 2 月 29 日 (閏年閏日) 的人在出生年到目標年份 Y 之間，實際過過幾次生日 (閏年計數)。
 *
 * [EN] Approach:
 *     For Feb 29 birth, birthday occurs only in leap years (year % 400 == 0 or (year % 4 == 0 and year % 100 != 0)).
 * [中文] 思路:
 *     若生日非 2 月 29 則每年過一次；若為 2 月 29 則遍歷出生年+1 到目標年，累加期間的閏年次數。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int is_leap_13275(int y) {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

int solve_uva13275(int d, int m, int y, int qy) {
    if (d != 29 || m != 2) return qy - y;
    int cnt = 0;
    for (int yr = y + 1; yr <= qy; yr++) {
        if (is_leap_13275(yr)) cnt++;
    }
    return cnt;
}

int main(void) {

    int ok = (solve_uva13275(29, 2, 2000, 2016) == 4); /* 2004, 2008, 2012, 2016 */
    printf("%s: UVa 13275 - Leap Birthdays\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
