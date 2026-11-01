/*
 * ==========================================================================
 * UVa 10721 - Bar Codes
 * Title-CN: 條形碼
 * Difficulty: Medium
 * Tags: DP, Combinatorics
 * URL: https://onlinejudge.org/external/107/10721.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count the number of barcodes of total length n, consisting of k bars, with each bar having width at most m.
 *
 * [中文] 題目概述:
 *     計算總長度為 n、由 k 個條形構成且每個條形寬度不超過 m 的條形碼數量。
 *
 * [EN] Approach:
 *     DP state dp[i][j] = number of barcodes of length i with j bars. dp[i][j] = sum(dp[i-w][j-1]) for 1 <= w <= m.
 * [中文] 解題思路:
 *     動態規劃：dp[i][j] 表示長度 i 由 j 條構成的方案數。dp[i][j] = sum(dp[i-w][j-1])，其中 1 <= w <= m。
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

long long count_barcodes(int n, int k, int m) {
    long long dp[55][55] = {0};
    dp[0][0] = 1;
    for (int bars = 1; bars <= k; bars++) {
        for (int len = bars; len <= n; len++) {
            for (int w = 1; w <= m && w <= len; w++) {
                dp[len][bars] += dp[len - w][bars - 1];
            }
        }
    }
    return dp[n][k];
}

int main(void) {

    int ok = (count_barcodes(7, 4, 3) == 16);
    printf("%s: UVa 10721 - Bar Codes\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
