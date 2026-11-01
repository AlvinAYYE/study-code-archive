/*
 * ==========================================================================
 * UVa 11926 - Multitasking
 * Title-CN: 多任務調度衝突檢測
 * Difficulty: Medium
 * Tags: Bitset, Interval Collision
 * URL: https://onlinejudge.org/external/119/11926.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Detect if one-time and recurring calendar appointments overlap in time using a bitset up to 1,000,000 minutes.
 *
 * [中文] 題目說明:
 *     利用位元陣列檢查單次與週期性重複的日程預約是否存在時間重疊衝突（時間上限 1,000,000 分鐘）。
 *
 * [EN] Approach:
 *     Use a bool array or bitset of size 1,000,000. Mark each interval [start, end-1]. If any minute is already marked, conflict exists.
 * [中文] 思路:
 *     使用長度 1,000,000 的布林陣列，將各任務在半開區間 [start, end) 內的每一分鐘標記為 1，若遇已標記則衝突。
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

bool has_schedule_conflict(int n, const int one_time[][2]) {
    bool occupied[1000] = {false};
    for (int i = 0; i < n; i++) {
        for (int t = one_time[i][0]; t < one_time[i][1]; t++) {
            if (occupied[t]) return true; // conflict
            occupied[t] = true;
        }
    }
    return false;
}

int main(void) {

    int sch1[][2] = {{10, 20}, {20, 30}};
    int sch2[][2] = {{10, 25}, {20, 30}};
    int ok = !has_schedule_conflict(2, sch1) && has_schedule_conflict(2, sch2);
    printf("%s: UVa 11926 - Multitasking\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
