/*
 * ==========================================================================
 * UVa 10056 - Distinct Subsequences (Classic DP variant)
 * Title-CN: 不同子序列計數
 * Difficulty: UVa Star 2
 * Tags: dynamic-programming, string
 * ==========================================================================
 * [EN] Problem:
 *     Count how many times string T appears as a subsequence in string S.
 *
 * [中文] 題目說明:
 *     給定主字串 S 與目標子序列字串 T，計算 T 在 S 中作為子序列出現的相異次數。
 *
 * [EN] Approach:
 *     dp[i][j]: number of times T[0..j-1] appears in S[0..i-1].
 *     dp[i][j] = dp[i-1][j] + (S[i-1] == T[j-1] ? dp[i-1][j-1] : 0).
 * [中文] 思路:
 *     動態規劃字串匹配。若字元相同則可選擇匹配或不匹配兩種轉移情況。
 * ==========================================================================
 */
#include <stdio.h>
#include <string.h>

long long solve_distinct_subseq(const char *s, const char *t) {
    int ls = (int)strlen(s);
    int lt = (int)strlen(t);
    long long dp[105] = {0};
    dp[0] = 1;

    for (int i = 0; i < ls; i++) {
        for (int j = lt; j >= 1; j--) {
            if (s[i] == t[j - 1]) {
                dp[j] += dp[j - 1];
            }
        }
    }
    return dp[lt];
}

int main(void) {
    long long res = solve_distinct_subseq("rabbbit", "rabbit");
    int ok = (res == 3);
    printf("%s: UVa Distinct Subsequences\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
