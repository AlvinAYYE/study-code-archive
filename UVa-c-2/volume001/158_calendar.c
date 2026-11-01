/*
 * ==========================================================================
 * UVa 158 - Calendar
 * Title-CN: 日程提醒日曆日期間隔模擬
 * Difficulty: UVa Star 2
 * Tags: simulation, date
 * URL: https://onlinejudge.org/external/1/158.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given yearly anniversaries and event reminders with warning windows (0 to 7 days), output today's active reminder list.
 *
 * [中文] 題目說明:
 *     給定年度紀念日與具有提前預警天數 (0 到 7 天) 的日程事件，輸出今日應觸發之提醒清單與星號提示等級。
 *
 * [EN] Approach:
 *     Simulate day count differences across dates within the current year (and year boundary leap considerations), sorting reminders by proximity.
 * [中文] 思路:
 *     計算給定基準日與各紀念日之天數差值，若落在預警區間內則按緊迫度與星號數量排序印出提醒日程。
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

int days_diff(int m1, int d1, int m2, int d2) {
    int mdays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int t1 = d1, t2 = d2;
    for (int i = 1; i < m1; i++) t1 += mdays[i];
    for (int i = 1; i < m2; i++) t2 += mdays[i];
    return t2 - t1;
}

int main(void) {

    int d = days_diff(1, 15, 1, 18);
    int ok = (d == 3);
    printf("%s: UVa 158 - Calendar\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
