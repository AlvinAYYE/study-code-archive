/*
 * ==========================================================================
 * UVa 12100 - Printer Queue
 * Title-CN: 印表機佇列優先級排程完成時間
 * Difficulty: UVa Star 2
 * Tags: data-structures, queue, simulation
 * URL: https://onlinejudge.org/external/121/12100.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Simulate printer job queue where higher priority jobs print first. Calculate minutes until target job at initial index m is printed.
 *
 * [中文] 題目說明:
 *     模擬具有優先級的印表機工作佇列 (佇列中若存在更高優先級工作則移至隊底)，求初始位於索引 m 的工作被列印的耗時 (分鐘)。
 *
 * [EN] Approach:
 *     FIFO circular queue tracking (priority, is_target) pairs. If current has lower priority than any queued job, re-enqueue; else print and increment minute counter.
 * [中文] 思路:
 *     以環形佇列維護各工作之優先級與目標標記，若佇列後方存在更高優先級則移至隊尾，否則列印出隊並累計分鐘數。
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

int solve_uva12100(int n, int m, int *prio) {
    int q_p[100], q_t[100], head = 0, tail = n;
    for (int i = 0; i < n; i++) {
        q_p[i] = prio[i];
        q_t[i] = (i == m);
    }
    int minutes = 0;
    while (head < tail) {
        int cur_p = q_p[head], cur_t = q_t[head++];
        int has_higher = 0;
        for (int i = head; i < tail; i++) {
            if (q_p[i] > cur_p) { has_higher = 1; break; }
        }
        if (has_higher) {
            q_p[tail] = cur_p;
            q_t[tail++] = cur_t;
        } else {
            minutes++;
            if (cur_t) return minutes;
        }
    }
    return minutes;
}

int main(void) {

    int p[] = {1, 1, 9, 1, 1, 1};
    int t = solve_uva12100(6, 0, p); // job 0 printed after 9 -> 5th
    int ok = (t == 5);
    printf("%s: UVa 12100 - Printer Queue\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
