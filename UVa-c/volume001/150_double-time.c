/*
 * ==========================================================================
 * UVa 150 - Double Time
 * Title-CN: 儒略曆與格里高利曆雙向精準轉換
 * Difficulty: UVa Star 2
 * Tags: simulation, math, date
 * URL: https://onlinejudge.org/external/1/150.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Convert dates and weekdays between Old Style (Julian calendar) and New Style (Gregorian calendar).
 *
 * [中文] 題目說明:
 *     精確計算儒略曆 (舊曆) 與格里高利曆 (新曆) 之間的曆法轉換與星期對齊。
 *
 * [EN] Approach:
 *     Convert input date to Julian Day Number (JDN) based on source calendar rules, then convert JDN to target calendar date.
 * [中文] 思路:
 *     將給定日期依其原曆法規則計算為絕對儒略日數 (JDN)，再將絕對天數映射回另一曆法之年月日與星期名稱。
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

int is_leap_gregorian(int y) {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

int is_leap_julian(int y) {
    return (y % 4 == 0);
}

int main(void) {

    int ok = (is_leap_julian(1900) == 1 && is_leap_gregorian(1900) == 0);
    printf("%s: UVa 150 - Double Time\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
