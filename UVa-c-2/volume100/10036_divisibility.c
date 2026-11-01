/*
 * ==========================================================================
 * UVa 10036 - Divisibility
 * Title-CN: 整除性動態規劃
 * Difficulty: UVa Star 2
 * Tags: dynamic-programming, math
 * URL: https://onlinejudge.org/external/100/10036.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Can we place '+' or '-' between elements such that sum % K == 0?
 *
 * [中文] 題目說明:
 *     在給定數列相鄰數間放入加號或減號，求最終計算結果是否可能被 K 整除。
 *
 * [EN] Approach:
 *     DP state dp[mod] = boolean reachable mod K. For each element x:
 *     next_dp[(m + x) % K] = true, next_dp[(m - x) % K] = true.
 * [中文] 思路:
 *     同餘動態規劃。dp[r] 代表前 i 個數字運算後是否可得到模 K 餘數為 r。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int solve_uva10036(int n, int k, const int *arr) {
    int dp[105] = {0};
    int init_mod = (abs(arr[0]) % k);
    dp[init_mod] = 1;

    for (int i = 1; i < n; i++) {
        int next_dp[105] = {0};
        int val = abs(arr[i]) % k;
        for (int m = 0; m < k; m++) {
            if (dp[m]) {
                next_dp[(m + val) % k] = 1;
                next_dp[(m - val + k) % k] = 1;
            }
        }
        memcpy(dp, next_dp, sizeof(dp));
    }
    return dp[0];
}

int main(void) {
    int a1[] = {17, 5, -21, 15};
    int ok = solve_uva10036(4, 7, a1);
    printf("%s: UVa 10036 - Divisibility\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
