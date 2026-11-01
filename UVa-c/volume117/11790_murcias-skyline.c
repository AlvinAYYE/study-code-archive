/*
 * ==========================================================================
 * UVa 11790 - Murcia's Skyline
 * Title-CN: 穆爾西亞的天際線
 * Difficulty: Medium
 * Tags: DP, LIS, LDS
 * URL: https://onlinejudge.org/external/117/11790.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given building heights and widths, find the maximum total width of strictly increasing and strictly decreasing subsequences of heights.
 *
 * [中文] 題目概述:
 *     給定大樓的高度與寬度，求高度嚴格遞增與嚴格遞減的子序列中，總寬度的最大值。
 *
 * [EN] Approach:
 *     Weighted LIS and LDS using dynamic programming in O(N^2). dp_inc[i] = w[i] + max(dp_inc[j]) for h[j] < h[i].
 * [中文] 解題思路:
 *     帶權重的 LIS 與 LDS 動態規劃：dp_inc[i] = w[i] + max(dp_inc[j])（當 h[j] < h[i]）。
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

void murcia_skyline(int n, const int *h, const int *w, int *max_inc, int *max_dec) {
    int dp_inc[100], dp_dec[100];
    int mi = 0, md = 0;
    for (int i = 0; i < n; i++) {
        dp_inc[i] = dp_dec[i] = w[i];
        for (int j = 0; j < i; j++) {
            if (h[j] < h[i] && dp_inc[j] + w[i] > dp_inc[i]) dp_inc[i] = dp_inc[j] + w[i];
            if (h[j] > h[i] && dp_dec[j] + w[i] > dp_dec[i]) dp_dec[i] = dp_dec[j] + w[i];
        }
        if (dp_inc[i] > mi) mi = dp_inc[i];
        if (dp_dec[i] > md) md = dp_dec[i];
    }
    *max_inc = mi; *max_dec = md;
}

int main(void) {

    int h[] = {10, 100, 50}, w[] = {50, 10, 20};
    int mi, md;
    murcia_skyline(3, h, w, &mi, &md);
    int ok = (mi == 70 || mi == 60) && (md >= 30);
    printf("%s: UVa 11790 - Murcia's Skyline\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
