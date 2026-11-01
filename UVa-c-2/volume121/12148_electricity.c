/*
 * ==========================================================================
 * UVa 12148 - Electricity
 * Title-CN: 電力度數計算 (連續相鄰天)
 * Difficulty: Easy
 * Tags: Simulation, Calendar, Date
 * URL: https://onlinejudge.org/external/121/12148.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given dates and electricity meter readings, find the total consumption and number of days for consecutive calendar day readings.
 *
 * [中文] 題目描述:
 *     給定日期與電表讀數列表，計算所有連續相鄰日（日期相差恰好 1 天）的用電量總和與天數。
 *
 * [EN] Approach:
 *     Check if (D2, M2, Y2) is exactly the day after (D1, M1, Y1). If so, accumulate consumption difference.
 *
 * [中文] 解題思維:
 *     判斷相鄰兩筆紀錄是否恰好隔 1 天（處理閏年與跨月跨年），若符合則累加用電差額與天數。
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

static int is_leap(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

static int days_in_month(int m, int y) {
    int d[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m == 2 && is_leap(y)) return 29;
    return d[m];
}

static int is_next_day(int d1, int m1, int y1, int d2, int m2, int y2) {
    if (d1 < days_in_month(m1, y1)) {
        return (y1 == y2 && m1 == m2 && d2 == d1 + 1);
    } else {
        if (m1 < 12) return (y1 == y2 && m2 == m1 + 1 && d2 == 1);
        else return (y2 == y1 + 1 && m2 == 1 && d2 == 1);
    }
}

void solve_electricity(int n, int d[], int m[], int y[], int c[], int *out_days, int *out_cons) {
    *out_days = 0;
    *out_cons = 0;
    for (int i = 1; i < n; i++) {
        if (is_next_day(d[i - 1], m[i - 1], y[i - 1], d[i], m[i], y[i])) {
            (*out_days)++;
            *out_cons += (c[i] - c[i - 1]);
        }
    }
}

int main(void) {

    int d[] = {1, 2, 4};
    int m[] = {1, 1, 1};
    int y[] = {2008, 2008, 2008};
    int c[] = {100, 110, 150};
    int out_d, out_c;
    solve_electricity(3, d, m, y, c, &out_d, &out_c);
    int ok = (out_d == 1 && out_c == 10);
    printf("%s: UVa 12148 - Electricity\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
