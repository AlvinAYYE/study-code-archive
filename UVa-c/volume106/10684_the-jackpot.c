/*
 * ==========================================================================
 * UVa 10684 - The jackpot
 * Title-CN: 頭彩大獎 (最大連續子序列和 Kadane)
 * Difficulty: UVa Star 1
 * Tags: dynamic-programming, kadane
 * URL: https://onlinejudge.org/external/106/10684.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the maximum winning streak (maximum contiguous subarray sum) in a sequence of bets.
 *
 * [中文] 題目說明:
 *     在賭注下注收益序列中，尋找連續投注收益總和的最大值 (若最大和為 0 或負數則判定無獲利)。
 *
 * [EN] Approach:
 *     Kadane's algorithm: cur_sum = max(0, cur_sum + val). Track max_sum.
 * [中文] 思路:
 *     標準 Kadane 動態規劃：累計當前和，小於 0 則重設為 0，維護全局最大連續子序列和。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva10684(int n, const int *bets) {
    int max_s = 0, cur_s = 0;
    for (int i = 0; i < n; i++) {
        cur_s += bets[i];
        if (cur_s < 0) cur_s = 0;
        if (cur_s > max_s) max_s = cur_s;
    }
    return max_s;
}

int main(void) {

    int b[5] = {12, -4, 15, -2, 10};
    int ok = (solve_uva10684(5, b) == 31);
    printf("%s: UVa 10684 - The jackpot\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
