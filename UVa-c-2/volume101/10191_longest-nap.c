/*
 * ==========================================================================
 * UVa 10191 - Longest Nap
 * Title-CN: 最長小憩時間
 * Difficulty: UVa Star 1 / CPE 49 顆星必考題
 * Tags: sorting, simulation, greedy
 * URL: https://onlinejudge.org/external/101/10191.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given appointments between 10:00 and 18:00, find the longest free interval
 *     and its start time.
 *
 * [中文] 題目說明:
 *     在 10:00 至 18:00 之間安排了一系列行程。求最長的空檔時間（Nap）長度與開始時間。
 *
 * [EN] Approach: Convert times to minutes from 10:00 (0 to 480). Sort intervals and find max gap.
 * [中文] 思路: 時間轉為自 10:00 起算的分鐘數（0~480），排序行程區間後找出相鄰區間的最大間隔。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Appt;

static int cmp_appt(const void *a, const void *b) {
    return ((const Appt *)a)->start - ((const Appt *)b)->start;
}

int solve_uva10191(int n, Appt *appts, int *best_start, int *best_len) {
    qsort(appts, (size_t)n, sizeof(Appt), cmp_appt);
    int cur = 600; /* 10:00 in minutes */
    int max_len = 0, start_time = 600;

    for (int i = 0; i < n; i++) {
        if (appts[i].start > cur) {
            int gap = appts[i].start - cur;
            if (gap > max_len) {
                max_len = gap;
                start_time = cur;
            }
        }
        if (appts[i].end > cur) cur = appts[i].end;
    }
    if (1080 - cur > max_len) { /* 18:00 = 1080 min */
        max_len = 1080 - cur;
        start_time = cur;
    }
    *best_start = start_time;
    *best_len = max_len;
    return max_len;
}

int main(void) {
    Appt appts[1] = {{720, 780}}; /* 12:00 to 13:00 */
    int start, len;
    solve_uva10191(1, appts, &start, &len);
    int ok = (start == 1080 - 300 || start == 600) && (len >= 120);
    printf("%s: UVa 10191 - Longest Nap\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
