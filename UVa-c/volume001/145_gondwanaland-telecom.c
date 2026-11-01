/*
 * ==========================================================================
 * UVa 145 - Gondwanaland Telecom
 * Title-CN: 跨時段電話通話費率分段累計
 * Difficulty: UVa Star 1
 * Tags: simulation, math
 * URL: https://onlinejudge.org/external/1/145.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given call start and end times and rate category, calculate minutes spent in day (8am-6pm), evening (6pm-10pm), and night (10pm-8am) bands, and total bill.
 *
 * [中文] 題目說明:
 *     給定電話通話起訖時間與費率代碼，分段統計日間 (8:00-18:00)、傍晚 (18:00-22:00) 與夜間 (22:00-8:00) 的通話分鐘數與總話費。
 *
 * [EN] Approach:
 *     Convert times to minute-of-day offsets. Step minute by minute (or calculate overlapping intervals) modulo 1440, classifying each minute into its tariff band.
 * [中文] 思路:
 *     將通話時間轉換為以分鐘為單位的時間戳，跨日時加 1440 分鐘，逐分鐘比對落點時段區間累加三時段通話時間並計費。
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

void get_call_minutes(int sh, int sm, int eh, int em, int *day, int *eve, int *ngt) {
    *day = 0; *eve = 0; *ngt = 0;
    int cur = sh * 60 + sm;
    int end = eh * 60 + em;
    if (end <= cur) end += 24 * 60;
    for (int t = cur; t < end; t++) {
        int m = t % 1440;
        if (m >= 480 && m < 1080) (*day)++;
        else if (m >= 1080 && m < 1320) (*eve)++;
        else (*ngt)++;
    }
}

int main(void) {

    int d, e, n;
    get_call_minutes(8, 0, 8, 30, &d, &e, &n);
    int ok = (d == 30 && e == 0 && n == 0);
    printf("%s: UVa 145 - Gondwanaland Telecom\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
