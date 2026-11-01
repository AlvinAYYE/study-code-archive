/*
 * ==========================================================================
 * UVa 700 - Date Bugs
 * Title-CN: 千年蟲日期還原 (同餘模擬)
 * Difficulty: Medium
 * Tags: Math, Chinese Remainder, Simulation
 * URL: https://onlinejudge.org/external/7/700.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the actual year given multiple computers each with a year-display bug that cycles every (b - a) years.
 *
 * [中文] 題目描述:
 *     給定多台有日期漏洞的電腦顯示年份與循環週期，求所有電腦能吻合顯示的最早實際年份（< 10000）。
 *
 * [EN] Approach:
 *     Simulate forward starting from the earliest valid year of the computer with largest period.
 *
 * [中文] 解題思維:
 *     以週期最大或首台電腦為基準，逐步按週期跳躍檢查是否同時滿足其他所有電腦的同餘條件。
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

int find_actual_year(int n, int *y, int *a, int *b) {
    int max_a = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > max_a) max_a = a[i];
    }
    // Start search from max_a or first year match
    int step = b[0] - a[0];
    int start = y[0];
    while (start < max_a) start += step;

    for (int year = start; year < 10000; year += step) {
        int all_ok = 1;
        for (int i = 1; i < n; i++) {
            int p = b[i] - a[i];
            if (year < a[i] || (year - y[i]) % p != 0) {
                all_ok = 0;
                break;
            }
        }
        if (all_ok) return year;
    }
    return -1;
}

int main(void) {

    int y[] = {41, 1941};
    int a[] = {1900, 1900};
    int b[] = {2000, 10000};
    // Computer 0 rolls over 1900..2000 (period 100), shows 41 -> actual 1941
    int res = find_actual_year(2, y, a, b);
    int ok = (res == 1941);
    printf("%s: UVa 700 - Date Bugs\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
