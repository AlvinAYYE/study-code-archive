/*
 * ==========================================================================
 * UVa 893 - Y3K Problem
 * Title-CN: 西元三千年曆法推進
 * Difficulty: Easy
 * Tags: Simulation, Calendar, Date Math
 * URL: https://onlinejudge.org/external/8/893.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Add N days to a given Gregorian date (day, month, year) correctly handling leap years.
 *
 * [中文] 題目說明:
 *     在給定的公曆日期上增加 N 天，正確處理閏年並輸出計算後的年月日。
 *
 * [EN] Approach:
 *     Advance day by day or month by month, checking leap year conditions: (y%4==0 && y%100!=0) || (y%400==0).
 * [中文] 思路:
 *     模擬閏年規則：（能被 4 整除且不被 100 整除，或能被 400 整除），逐步累計天數推進日期。
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

bool is_leap(int y) { return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0); }
int days_in_month(int m, int y) {
    int d[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m == 2 && is_leap(y)) return 29;
    return d[m];
}
void add_days(int n, int *d, int *m, int *y) {
    while (n > 0) {
        int left = days_in_month(*m, *y) - *d;
        if (n <= left) { *d += n; n = 0; }
        else {
            n -= (left + 1);
            *d = 1;
            (*m)++;
            if (*m > 12) { *m = 1; (*y)++; }
        }
    }
}

int main(void) {

    int d = 1, m = 1, y = 2000;
    add_days(31, &d, &m, &y);
    int ok = (d == 1 && m == 2 && y == 2000);
    printf("%s: UVa 893 - Y3K Problem\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
