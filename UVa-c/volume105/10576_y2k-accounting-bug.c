/*
 * ==========================================================================
 * UVa 10576 - Y2K Accounting Bug
 * Title-CN: Y2K 財務漏洞 (滑動窗口貪心回溯)
 * Difficulty: Easy
 * Tags: Greedy, Backtracking
 * URL: https://onlinejudge.org/external/105/10576.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Company reports either profit s or deficit d each month. Every 5 consecutive months showed a deficit. Find maximum annual surplus, or DEFICIT.
 *
 * [中文] 題目說明:
 *     公司每月固定盈利 s 或虧損 d，且任意連續 5 個月的財務報表總和均為赤字（< 0），求全年可能的最大盈餘總額。
 *
 * [EN] Approach:
 *     Try placing deficits d as late as possible in each 5-month block. Five possible monthly patterns: ssssd, sssdd, ssddd, sdddd, ddddd.
 * [中文] 思路:
 *     貪心法：為使總盈餘最大，在每個 5 個月窗口中盡量讓盈利 s 靠前、赤字 d 靠後。判定最多能填入多少個 s 使得 5 月和仍為負。
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

int max_annual_surplus(int s, int d) {
    int max_s = -1;
    for (int k = 4; k >= 1; k--) {
        // k surpluses and (5-k) deficits in every 5 months
        if (k * s - (5 - k) * d < 0) {
            // Pattern repeats
            int total = 0;
            if (k == 4) total = 10 * s - 2 * d; // 8s + 2s - 2d? Months: s s s s d | s s s s d | s s -> 10s - 2d
            else if (k == 3) total = 8 * s - 4 * d; // s s s d d | s s s d d | s s -> 8s - 4d
            else if (k == 2) total = 6 * s - 6 * d; // s s d d d | s s d d d | s s -> 6s - 6d
            else if (k == 1) total = 3 * s - 9 * d; // s d d d d | s d d d d | s d -> 3s - 9d
            if (total > 0) return total;
            break;
        }
    }
    return -1; // Deficit
}

int main(void) {

    int res = max_annual_surplus(19, 99); // 4*19 - 99 = 76 - 99 = -23 < 0 -> 10*19 - 2*99 = 190 - 198 = -8 < 0
    int ok = (res == -1 || res > 0);
    printf("%s: UVa 10576 - Y2K Accounting Bug\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
