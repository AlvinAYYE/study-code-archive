/*
 * ==========================================================================
 * UVa 11805 - Bafana Bafana
 * Title-CN: 南非足球傳球 (環形取模位移)
 * Difficulty: UVa Star 1
 * Tags: math
 * URL: https://onlinejudge.org/external/118/11805.pdf
 * ==========================================================================
 * [EN] Problem:
 *     N players in a circle (1..N). Ball starts at player K and is passed P times clockwise. Find player holding the ball.
 *
 * [中文] 題目說明:
 *     N 名球員圍成一圈 (編號 1 到 N)。球從 K 號開始順時針傳球 P 次，求最後持球的球員編號。
 *
 * [EN] Approach:
 *     Formula: 1-based circular shift: ((K - 1 + P) % N) + 1.
 * [中文] 思路:
 *     循環取模公式：將 1-based 轉為 0-based 位移取模後加 1，即 ((K - 1 + P) % N) + 1。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva11805(int n, int k, int p) {
    return ((k - 1 + p) % n) + 1;
}

int main(void) {

    int ok = (solve_uva11805(5, 2, 5) == 2) && (solve_uva11805(6, 3, 5) == 2);
    printf("%s: UVa 11805 - Bafana Bafana\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
