/*
 * ==========================================================================
 * UVa 10032 - Tug of War
 * Title-CN: 拔河比賽
 * Difficulty: UVa Star 3
 * Tags: dynamic-programming, knapsack, bit-manipulation
 * URL: https://onlinejudge.org/external/100/10032.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Divide N people into two teams with headcount difference <= 1, minimizing weight difference.
 *
 * [中文] 題目說明:
 *     將 N 個人分成兩組，人數差距至多 1 人（一組為 n/2 人），使得兩組體重總和最接近。
 *
 * [EN] Approach:
 *     DP bitmask knapsack: dp[weight] is a 64-bit integer where k-th bit = 1 if weight is achievable with k people.
 * [中文] 思路:
 *     二維背包壓位 DP。dp[w] 的第 k 位元為 1 代表可用 k 個人湊出體重 w。
 * ==========================================================================
 */
#include <stdio.h>
#include <string.h>

void solve_uva10032(int n, const int *w, int *ans1, int *ans2) {
    int total_w = 0;
    for (int i = 0; i < n; i++) total_w += w[i];
    int half_w = total_w / 2;
    int target_cnt = n / 2;

    unsigned long long dp[23000] = {0};
    dp[0] = 1ULL; /* 0 people give 0 weight */

    for (int i = 0; i < n; i++) {
        int weight = w[i];
        for (int j = half_w; j >= weight; j--) {
            dp[j] |= (dp[j - weight] << 1);
        }
    }

    for (int j = half_w; j >= 0; j--) {
        if ((dp[j] & (1ULL << target_cnt)) || (n % 2 == 1 && (dp[j] & (1ULL << (target_cnt + 1))))) {
            *ans1 = j;
            *ans2 = total_w - j;
            return;
        }
    }
}

int main(void) {
    int w[3] = {100, 90, 200};
    int a1, a2;
    solve_uva10032(3, w, &a1, &a2);
    int ok = (a1 == 190 && a2 == 200) || (a1 == 200 && a2 == 190);
    printf("%s: UVa 10032 - Tug of War\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
