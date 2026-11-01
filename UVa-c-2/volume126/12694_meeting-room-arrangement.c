/*
 * ==========================================================================
 * UVa 12694 - Meeting Room Arrangement
 * Title-CN: 會議室排程最大場數 (貪婪區間排程)
 * Difficulty: UVa Star 1
 * Tags: greedy, sorting, interval-scheduling
 * URL: https://onlinejudge.org/external/126/12694.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find maximum number of non-overlapping meetings that can be scheduled in a single meeting room.
 *
 * [中文] 題目說明:
 *     在單一會議室中，求最多可容納的互不重疊會議場數 (經典貪婪區間排程演算法，按結束時間由早到晚排序)。
 *
 * [EN] Approach:
 *     Classic interval scheduling: sort meetings by finish time. Greedily select next meeting whose start time >= current finish.
 * [中文] 思路:
 *     依會議結束時間升序排序。貪婪挑選結束時間最早且開始時間不早於前一場結束時間的會議，場數最大化。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct { int s, e; } Meeting;

int solve_uva12694(int n, Meeting *m) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (m[i].e > m[j].e) { Meeting t = m[i]; m[i] = m[j]; m[j] = t; }
        }
    }
    int cnt = 0, last_end = 0;
    for (int i = 0; i < n; i++) {
        if (m[i].s >= last_end) {
            cnt++;
            last_end = m[i].e;
        }
    }
    return cnt;
}

int main(void) {

    Meeting m[3] = {{1, 3}, {2, 5}, {4, 7}};
    int ok = (solve_uva12694(3, m) == 2);
    printf("%s: UVa 12694 - Meeting Room Arrangement\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
