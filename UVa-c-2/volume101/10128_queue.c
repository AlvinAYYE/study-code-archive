/*
 * ==========================================================================
 * UVa 10128 - Queue
 * Title-CN: 隊列視角 (斯特林數與排列DP)
 * Difficulty: Medium
 * Tags: DP, Combinatorics, Stirling Numbers
 * URL: https://onlinejudge.org/external/101/10128.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given N people of distinct heights standing in a line, count permutations where P people are visible from the front and R from the back.
 *
 * [中文] 題目說明:
 *     N 個人排成一列，求由前看可見 P 個人、由後看可見 R 個人的排列總數。
 *
 * [EN] Approach:
 *     DP state dp[n][p][r] = dp[n-1][p-1][r] (shortest in front) + dp[n-1][p][r-1] (shortest in back) + dp[n-1][p][r] * (n - 2) (shortest inside).
 * [中文] 思路:
 *     動態規劃：考慮最矮者位置，可放在最前（前視增 1）、最後（後視增 1）或中間 n-2 個位置之一（視角不變）：dp[n][p][r] = dp[n-1][p-1][r] + dp[n-1][p][r-1] + (n-2)*dp[n-1][p][r]。
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

long long count_queues(int n, int p, int r) {
    long long dp[15][15][15] = {0};
    dp[1][1][1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= p; j++) {
            for (int k = 1; k <= r; k++) {
                dp[i][j][k] = dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] + dp[i - 1][j][k] * (i - 2);
            }
        }
    }
    return dp[n][p][r];
}

int main(void) {

    int ok = (count_queues(3, 2, 2) == 2); // 1 3 2, 2 3 1
    printf("%s: UVa 10128 - Queue\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
