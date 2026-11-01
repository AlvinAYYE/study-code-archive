/*
 * ==========================================================================
 * UVa 10081 - Tight Words
 * Title-CN: 緊湊單詞機率 (相鄰數位差不超過1的DP)
 * Difficulty: Easy
 * Tags: DP, Probability
 * URL: https://onlinejudge.org/external/100/10081.pdf
 * ==========================================================================
 * [EN] Problem:
 *     A word of length n on alphabet {0..k} is tight if adjacent digits differ by at most 1. Find percentage of tight words.
 *
 * [中文] 題目說明:
 *     長度為 n 且字母取自 {0..k} 的單詞中，若相鄰數字差值絕對值不超過 1 則稱為緊湊單詞，求緊湊單詞所佔百分比。
 *
 * [EN] Approach:
 *     DP state dp[len][digit] = probability ending in digit. dp[len][d] = (dp[len-1][d-1] + dp[len-1][d] + dp[len-1][d+1]) / (k + 1).
 * [中文] 思路:
 *     機率動態規劃：dp[len][d] 表示當前末尾為 d 的機率，由上一長度相差不超過 1 的數位轉移除以 (k+1)。
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

double tight_word_percent(int k, int n) {
    double dp[105][15] = {0};
    for (int d = 0; d <= k; d++) dp[1][d] = 1.0 / (k + 1);
    for (int len = 2; len <= n; len++) {
        for (int d = 0; d <= k; d++) {
            dp[len][d] = dp[len-1][d];
            if (d > 0) dp[len][d] += dp[len-1][d-1];
            if (d < k) dp[len][d] += dp[len-1][d+1];
            dp[len][d] /= (k + 1);
        }
    }
    double sum = 0;
    for (int d = 0; d <= k; d++) sum += dp[n][d];
    return sum * 100.0;
}

int main(void) {

    double p = tight_word_percent(1, 1);
    int ok = (fabs(p - 100.0) < 1e-4);
    printf("%s: UVa 10081 - Tight Words\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
