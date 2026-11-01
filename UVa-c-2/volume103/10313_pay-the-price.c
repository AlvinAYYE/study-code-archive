/*
 * ==========================================================================
 * UVa 10313 - Pay the Price
 * Title-CN: 付出代價 (硬幣數目限制的整數拆分DP)
 * Difficulty: Medium
 * Tags: DP, Integer Partition
 * URL: https://onlinejudge.org/external/103/10313.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count integer partitions of N using parts 1..N with constraints on the number of parts used (at most L2, or between L1 and L2).
 *
 * [中文] 題目說明:
 *     求將整數 N 拆分為不超過 N 的正整數之和的拆分數，且限制使用的硬幣/拆分數目在給定區間內。
 *
 * [EN] Approach:
 *     DP state dp[i][j] = number of partitions of sum i using exactly j parts. Equivalently, partitions of i with largest part j. dp[i][j] = dp[i-1][j-1] + dp[i-j][j].
 * [中文] 思路:
 *     經典整數拆分動態規劃：dp[i][j] 表示和為 i 且恰好使用 j 個拆分項的方案數，轉移為 dp[i][j] = dp[i-1][j-1] + dp[i-j][j]。
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

long long count_partitions_parts(int n, int min_k, int max_k) {
    long long dp[305][305] = {0};
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - j][j];
        }
    }
    long long total = 0;
    if (max_k > n) max_k = n;
    for (int k = min_k; k <= max_k; k++) total += dp[n][k];
    return total;
}

int main(void) {

    long long cnt = count_partitions_parts(6, 1, 2); // 6 (1 part), 5+1, 4+2, 3+3 (3 of 2 parts) -> 4
    int ok = (cnt == 4);
    printf("%s: UVa 10313 - Pay the Price\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
