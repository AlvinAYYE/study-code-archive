/*
 * ==========================================================================
 * UVa 12563 - Jin Ge Jin Qu hao
 * Title-CN: 勁歌金曲 (雙目標 0-1 背包問題)
 * Difficulty: Medium
 * Tags: Dynamic Programming, Knapsack
 * URL: https://onlinejudge.org/external/125/12563.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Maximize the number of KTV songs sung before time limit t runs out, then maximize total time sung (adding 678s song at end).
 *
 * [中文] 題目描述:
 *     在 KTV 剩餘時間 t 之前點播歌曲，優先最大化演唱歌曲數，其次最大化總時間，最後加上一首 678 秒的《勁歌金曲》。
 *
 * [EN] Approach:
 *     0-1 Knapsack with capacity (t - 1): maximize (count, time). Final answer is (count + 1, time + 678).
 *
 * [中文] 解題思維:
 *     容量為 t - 1 的 0-1 背包：以 (歌曲數, 耗費時間) 為狀態最大化，最後結果累加 1 首歌曲與 678 秒《勁歌金曲》。
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

void solve_ktv_knapsack(int n, int t, int *lens, int *out_count, int *out_time) {
    int cap = t - 1;
    if (cap < 0) cap = 0;
    int dp_cnt[10005], dp_time[10005];
    memset(dp_cnt, -1, sizeof(dp_cnt));
    memset(dp_time, 0, sizeof(dp_time));

    dp_cnt[0] = 0;
    dp_time[0] = 0;

    for (int i = 0; i < n; i++) {
        int w = lens[i];
        for (int c = cap; c >= w; c--) {
            if (dp_cnt[c - w] != -1) {
                int new_cnt = dp_cnt[c - w] + 1;
                int new_time = dp_time[c - w] + w;
                if (new_cnt > dp_cnt[c] || (new_cnt == dp_cnt[c] && new_time > dp_time[c])) {
                    dp_cnt[c] = new_cnt;
                    dp_time[c] = new_time;
                }
            }
        }
    }
    int best_c = 0, best_t = 0;
    for (int c = 0; c <= cap; c++) {
        if (dp_cnt[c] > best_c || (dp_cnt[c] == best_c && dp_time[c] > best_t)) {
            best_c = dp_cnt[c];
            best_t = dp_time[c];
        }
    }
    *out_count = best_c + 1;
    *out_time = best_t + 678;
}

int main(void) {

    int songs[] = {100, 200}; // limit t = 150 -> can choose song 100 -> 1 song, total 100 + 678 = 778
    int cnt, time;
    solve_ktv_knapsack(2, 150, songs, &cnt, &time);
    int ok = (cnt == 2 && time == 778);
    printf("%s: UVa 12563 - Jin Ge Jin Qu hao\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
