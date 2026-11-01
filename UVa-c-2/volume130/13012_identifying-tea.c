/*
 * ==========================================================================
 * UVa 13012 - Identifying tea
 * Title-CN: 盲測盲品茶葉猜中人數統計
 * Difficulty: UVa Star 1
 * Tags: simulation
 * URL: https://onlinejudge.org/external/130/13012.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given correct tea type T and 5 contestants' answers, count how many contestants guessed correctly.
 *
 * [中文] 題目說明:
 *     盲測品茶：已知正確茶葉編號 T，統計 5 位參賽選手中有多少人猜中了正確編號。
 *
 * [EN] Approach:
 *     Count matching answers among 5 inputs equal to T.
 * [中文] 思路:
 *     遍歷 5 位選手的回答，每當數值等於正確編號 T 則計數加 1。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva13012(int t, const int *ans) {
    int cnt = 0;
    for (int i = 0; i < 5; i++) if (ans[i] == t) cnt++;
    return cnt;
}

int main(void) {

    int a[5] = {1, 2, 3, 2, 2};
    int ok = (solve_uva13012(2, a) == 3);
    printf("%s: UVa 13012 - Identifying tea\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
