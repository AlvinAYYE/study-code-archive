/*
 * ==========================================================================
 * UVa 12136 - Schedule of a Married Man
 * Title-CN: 已婚男人的時間表 (時間區間重疊判斷)
 * Difficulty: Easy
 * Tags: Simulation, Interval Collision
 * URL: https://onlinejudge.org/external/121/12136.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine if a wife's meeting schedule and a husband's meeting schedule overlap in time.
 *
 * [中文] 題目說明:
 *     判斷妻子安排的約會時間區間與丈夫的會議時間區間是否存在時間重疊衝突。
 *
 * [EN] Approach:
 *     Convert times HH:MM into minutes from midnight: start_min = HH * 60 + MM. Two intervals [s1, e1] and [s2, e2] overlap iff s1 <= e2 && s2 <= e1.
 * [中文] 思路:
 *     將時間轉為當日分鐘數，閉區間 [s1, e1] 與 [s2, e2] 重疊的充要條件為 s1 <= e2 且 s2 <= e1。
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

bool time_intervals_overlap(int h1, int m1, int h2, int m2, int h3, int m3, int h4, int m4) {
    int start1 = h1 * 60 + m1, end1 = h2 * 60 + m2;
    int start2 = h3 * 60 + m3, end2 = h4 * 60 + m4;
    return (start1 <= end2 && start2 <= end1);
}

int main(void) {

    int ok = time_intervals_overlap(10, 0, 12, 0, 11, 0, 13, 0) &&
             !time_intervals_overlap(10, 0, 11, 0, 12, 0, 13, 0);
    printf("%s: UVa 12136 - Schedule of a Married Man\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
