/*
 * ==========================================================================
 * UVa 696 - How Many Knights
 * Title-CN: 棋盤上最多騎士放置數
 * Difficulty: UVa Star 1
 * Tags: math, chess, greedy
 * URL: https://onlinejudge.org/external/6/696.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find maximum number of non-attacking knights on an M x N board.
 *
 * [中文] 題目說明:
 *     求在 M x N 棋盤上互不攻擊的西洋棋騎士的最大擺放數量 (特殊處理 1 列與 2 列棋盤)。
 *
 * [EN] Approach:
 *     Cases: if min(M, N) == 1, ans = max(M, N); if min(M, N) == 2, blocks of 2x2 with period 4; else ans = (M*N + 1)/2.
 * [中文] 思路:
 *     分類討論：若有一邊為 1 則為全放；若有一邊為 2 則以 4 為週期 2x2 區塊交替；一般棋盤黑白棋格著色為 (M*N + 1)/2。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva696(int m, int n) {
    int r = (m < n) ? m : n;
    int c = (m < n) ? n : m;
    if (r == 1) return c;
    if (r == 2) {
        int rem = c % 4;
        return (c / 4) * 4 + ((rem == 1) ? 2 : (rem >= 2 ? 4 : 0));
    }
    return (m * n + 1) / 2;
}

int main(void) {

    int ok = (solve_uva696(2, 3) == 4) && (solve_uva696(3, 3) == 5);
    printf("%s: UVa 696 - How Many Knights\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
