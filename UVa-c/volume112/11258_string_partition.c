/*
 * ==========================================================================
 * UVa 11258 - String Partition
 * Title-CN: 字串分割求最大 32 位元整數總和
 * Difficulty: Medium
 * Tags: Dynamic Programming, String
 * URL: https://onlinejudge.org/external/112/11258.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Partition a digit string into integers each <= 2^31 - 1 (2147483647) such that their sum is maximized.
 *
 * [中文] 題目描述:
 *     將數字字串劃分成多個不超過 32 位元有號整數上限（2147483647）的整數，求劃分後整數總和的最大值。
 *
 * [EN] Approach:
 *     1D DP: dp[i] = max_{1 <= len <= 10}(dp[i - len] + val) where val <= 2147483647.
 *
 * [中文] 解題思維:
 *     一維動態規劃：dp[i] 表示前 i 個數字的最大總和，枚舉最後一段長度 1~10，若其數值小於等於 2147483647 則進行轉移。
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

long long max_partition_sum(const char *digits) {
    int n = (int)strlen(digits);
    long long dp[505];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++) {
        long long val = 0;
        for (int len = 1; len <= 10 && len <= i; len++) {
            int start = i - len;
            // Parse substring digits[start..i-1]
            val = 0;
            for (int k = start; k < i; k++) {
                val = val * 10 + (digits[k] - '0');
            }
            if (val <= 2147483647LL) {
                long long cand = dp[start] + val;
                if (cand > dp[i]) dp[i] = cand;
            }
        }
    }
    return dp[n];
}

int main(void) {

    long long s1 = max_partition_sum("12345"); // 12345
    long long s2 = max_partition_sum("9999999999"); // 999999999 + 9 = 1000000008
    int ok = (s1 == 12345 && s2 == 1000000008LL);
    printf("%s: UVa 11258 - String Partition\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
