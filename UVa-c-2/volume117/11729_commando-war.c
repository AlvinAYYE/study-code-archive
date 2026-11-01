/*
 * ==========================================================================
 * UVa 11729 - Commando War
 * Title-CN: 突擊隊戰役
 * Difficulty: UVa Star 1
 * Tags: greedy, sorting
 * URL: https://onlinejudge.org/external/117/11729.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Briefing soldier i takes B_i minutes, execution takes J_i minutes. Minimize total completion time.
 *
 * [中文] 題目說明:
 *     指揮官交代任務需 B_i 分鐘（交代過程不能並行），交代完後士兵執行任務需 J_i 分鐘（士兵可同時並行執行）。
 *     求所有士兵全部完成任務的最短總時間。
 *
 * [EN] Approach:
 *     Greedy: sort soldiers by execution time J_i in descending order.
 * [中文] 思路:
 *     貪婪策略：執行時間 J_i 越長的士兵優先交代，讓耗時長的任務儘早開始並行。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct { int b, j; } Soldier;

static int cmp_s(const void *a, const void *b) {
    return ((const Soldier *)b)->j - ((const Soldier *)a)->j; /* Descending by J */
}

static inline int max_val(int a, int b) { return a > b ? a : b; }

int solve_uva11729(int n, Soldier *s) {
    qsort(s, (size_t)n, sizeof(Soldier), cmp_s);
    int brief_sum = 0, total_time = 0;
    for (int i = 0; i < n; i++) {
        brief_sum += s[i].b;
        total_time = max_val(total_time, brief_sum + s[i].j);
    }
    return total_time;
}

int main(void) {
    Soldier s[3] = {{2, 5}, {3, 2}, {4, 1}};
    int res = solve_uva11729(3, s);
    int ok = (res == 10);
    printf("%s: UVa 11729 - Commando War\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
