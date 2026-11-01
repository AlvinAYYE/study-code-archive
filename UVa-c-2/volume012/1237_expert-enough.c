/*
 * ==========================================================================
 * UVa 1237 - Expert Enough?
 * Title-CN: 汽車價格區間資料庫單一製造商查詢
 * Difficulty: UVa Star 1
 * Tags: brute-force
 * URL: https://onlinejudge.org/external/12/1237.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given price ranges [L_i, H_i] for car makers, determine if a query price P falls in the range of exactly one maker.
 *
 * [中文] 題目說明:
 *     給定多家汽車製造商的價格區間 [L_i, H_i]，對於查詢價格 P，若恰好只有一家製造商符合則輸出廠牌名稱，否則輸出 UNDETERMINED。
 *
 * [EN] Approach:
 *     Iterate database: count makers with L_i <= P <= H_i. If count == 1 return maker index, else return -1.
 * [中文] 思路:
 *     循序掃描資料庫中所有區間，統計滿足 L_i <= P <= H_i 的廠商數，若恰好為 1 則回傳該廠商，否則標記無解。
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

int solve_uva1237(int d, int *low, int *high, int p) {
    int match_idx = -1, match_cnt = 0;
    for (int i = 0; i < d; i++) {
        if (p >= low[i] && p <= high[i]) {
            match_cnt++;
            match_idx = i;
        }
    }
    return (match_cnt == 1) ? match_idx : -1;
}

int main(void) {

    int l[] = {100, 300}, h[] = {200, 400};
    int ans = solve_uva1237(2, l, h, 150);
    int ok = (ans == 0);
    printf("%s: UVa 1237 - Expert Enough?\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
