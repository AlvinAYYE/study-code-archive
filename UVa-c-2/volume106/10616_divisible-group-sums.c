/*
 * ==========================================================================
 * UVa 10616 - Divisible Group Sums
 * Title-CN: 被 D 整除之 M 個整數子集和動態規劃
 * Difficulty: UVa Star 2
 * Tags: dynamic-programming
 * URL: https://onlinejudge.org/external/106/10616.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given N integers, count subsets of size M whose sum is divisible by D.
 *
 * [中文] 題目概述:
 *     給定包含 N 個整數的集合，計算大小恰好為 M 且元素總和能被 D 整除的子集個數 (背包動態規劃)。
 *
 * [EN] Approach:
 *     3D Dynamic Programming: dp[i][count][rem] = ways to pick count numbers with sum mod D = rem. Handle negative mod.
 * [中文] 解題思路:
 *     三維背包 DP：dp[cnt][rem] 表示選取 cnt 個數且餘數為 rem 的組合數，由後向前更新轉移並處理負數取模。
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

long long solve_uva10616(int n, int m, int d, int *arr) {
    long long dp[15][25] = {0};
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        int v = ((arr[i] % d) + d) % d;
        for (int c = m; c >= 1; c--) {
            for (int r = 0; r < d; r++) {
                int prev_r = ((r - v) % d + d) % d;
                dp[c][r] += dp[c - 1][prev_r];
            }
        }
    }
    return dp[m][0];
}

int main(void) {

    int a[] = {1, 2, 3, 4};
    long long ways = solve_uva10616(4, 2, 2, a); // {1,3}, {2,4} -> 2
    int ok = (ways == 2);
    printf("%s: UVa 10616 - Divisible Group Sums\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
