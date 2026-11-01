/*
 * ==========================================================================
 * UVa 12531 - Hours and Minutes
 * Title-CN: 時針與分針夾角判定
 * Difficulty: Easy
 * Tags: Math, Clock Angle
 * URL: https://onlinejudge.org/external/125/12531.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine if a given angle A (0 <= A <= 180) can ever be formed between the hour hand and minute hand of a clock (discrete 6-degree steps).
 *
 * [中文] 題目說明:
 *     判斷 0 到 180 度的某個夾角 A 是否可能出現在標準時鐘的時針與分針之間。
 *
 * [EN] Approach:
 *     Every minute, the minute hand moves 6 degrees and the hour hand moves 0.5 degrees. Difference is always a multiple of 6 degrees iff A % 6 == 0.
 * [中文] 思路:
 *     每分鐘分針走 6 度，時針在分鐘整點下夾角必為 6 度的整數倍，故當且僅當 A % 6 == 0 時成立。
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

bool is_valid_clock_angle(int a) {
    return (a % 6 == 0);
}

int main(void) {

    int ok = is_valid_clock_angle(90) && is_valid_clock_angle(0) && !is_valid_clock_angle(7);
    printf("%s: UVa 12531 - Hours and Minutes\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
