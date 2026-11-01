/*
 * ==========================================================================
 * UVa 957 - Popes
 * Title-CN: 教宗選舉 (區間滑動窗口最大值)
 * Difficulty: Easy
 * Tags: Two Pointers, Sliding Window, Binary Search
 * URL: https://onlinejudge.org/external/9/957.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given years of pope elections and period Y, find the maximum number of popes elected in any Y consecutive years, along with the first and last year.
 *
 * [中文] 題目說明:
 *     給定教宗當選年份與年限 Y，求任意連續 Y 年區間內當選教宗的最大人數，以及該區間首末教宗的當選年份。
 *
 * [EN] Approach:
 *     Two pointers (sliding window) on sorted years array: while years[r] - years[l] >= Y, increment l. Track max(r - l + 1).
 * [中文] 思路:
 *     雙指針滑動窗口：右指針向右推進，當 years[r] - years[l] >= Y 時收縮左指針，維護窗口內教宗數量最大值。
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

void max_popes(int y_period, int p_cnt, const int *years, int *max_popes, int *first_y, int *last_y) {
    int l = 0;
    *max_popes = 0;
    for (int r = 0; r < p_cnt; r++) {
        while (years[r] - years[l] >= y_period) l++;
        int count = r - l + 1;
        if (count > *max_popes) {
            *max_popes = count;
            *first_y = years[l];
            *last_y = years[r];
        }
    }
}

int main(void) {

    int y[] = {1, 2, 3, 10, 11};
    int mp, fy, ly;
    max_popes(5, 5, y, &mp, &fy, &ly); // [1, 2, 3] span <= 5 -> 3 popes
    int ok = (mp == 3 && fy == 1 && ly == 3);
    printf("%s: UVa 957 - Popes\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
