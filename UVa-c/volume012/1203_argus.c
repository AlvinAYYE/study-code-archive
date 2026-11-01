/*
 * ==========================================================================
 * UVa 1203 - Argus
 * Title-CN: 阿格斯週期查詢優先佇列排程
 * Difficulty: UVa Star 2
 * Tags: data-structures, priority-queue
 * URL: https://onlinejudge.org/external/12/1203.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Simulate periodic query registrations: repeatedly return next query ID scheduled to execute by time (tie-broken by query ID).
 *
 * [中文] 題目說明:
 *     模擬多個週期性查詢註冊：依據下次觸發時間 (時間相同時按查詢 ID 升序) 循序提取前 K 個被執行的查詢 ID。
 *
 * [EN] Approach:
 *     Simulate via priority queue or sorted state array storing (cur_time, period, q_num). Advance time by period after each pop.
 * [中文] 思路:
 *     以優先佇列或狀態陣列維護各註冊項之 (當前時間, 週期, 查詢編號)，每次選出時間最小者加入輸出序列並更新其下次觸發時間。
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

void solve_uva1203(int n, int *qid, int *period, int k, int *out) {
    int next_t[50];
    for (int i = 0; i < n; i++) next_t[i] = period[i];
    for (int step = 0; step < k; step++) {
        int best_idx = 0;
        for (int i = 1; i < n; i++) {
            if (next_t[i] < next_t[best_idx] || (next_t[i] == next_t[best_idx] && qid[i] < qid[best_idx])) {
                best_idx = i;
            }
        }
        out[step] = qid[best_idx];
        next_t[best_idx] += period[best_idx];
    }
}

int main(void) {

    int q[] = {2004, 2005}, p[] = {200, 300}, o[3];
    solve_uva1203(2, q, p, 3, o);
    int ok = (o[0] == 2004 && o[1] == 2005 && o[2] == 2004);
    printf("%s: UVa 1203 - Argus\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
