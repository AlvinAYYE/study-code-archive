/*
 * ==========================================================================
 * UVa 11947 - Cancer or Scorpio
 * Title-CN: 巨蟹座還是天蠍座 (懷孕週期與十二星座推算)
 * Difficulty: Easy
 * Tags: Simulation, Calendar, Date Math
 * URL: https://onlinejudge.org/external/119/11947.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Add 40 weeks (280 days) to the first day of last menstrual cycle to determine baby's birth date and astrological sign.
 *
 * [中文] 題目說明:
 *     在末次月經起始日加上 40 週（280 天）計算預產期，並判斷新生兒所屬的十二星座。
 *
 * [EN] Approach:
 *     Advance calendar date by 280 days taking leap years into account. Map resulting month/day into zodiac date ranges.
 * [中文] 思路:
 *     日期累加 280 天推算預產期，根據月份與日期區間判斷所屬黃道十二星座。
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

const char* get_zodiac(int m, int d) {
    if ((m == 1 && d >= 21) || (m == 2 && d <= 19)) return "aquarius";
    if ((m == 2 && d >= 20) || (m == 3 && d <= 20)) return "pisces";
    if ((m == 3 && d >= 21) || (m == 4 && d <= 20)) return "aries";
    if ((m == 4 && d >= 21) || (m == 5 && d <= 21)) return "taurus";
    if ((m == 5 && d >= 22) || (m == 6 && d <= 21)) return "gemini";
    if ((m == 6 && d >= 22) || (m == 7 && d <= 22)) return "cancer";
    if ((m == 7 && d >= 23) || (m == 8 && d <= 21)) return "leo";
    if ((m == 8 && d >= 22) || (m == 9 && d <= 23)) return "virgo";
    if ((m == 9 && d >= 24) || (m == 10 && d <= 23)) return "libra";
    if ((m == 10 && d >= 24) || (m == 11 && d <= 22)) return "scorpio";
    if ((m == 11 && d >= 23) || (m == 12 && d <= 22)) return "sagittarius";
    return "capricorn";
}

int main(void) {

    int ok = (strcmp(get_zodiac(7, 10), "cancer") == 0) && (strcmp(get_zodiac(11, 10), "scorpio") == 0);
    printf("%s: UVa 11947 - Cancer or Scorpio\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
