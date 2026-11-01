/*
 * ==========================================================================
 * UVa 10664 - Luggage
 * Title-CN: 行李雙車等重平分背包判定
 * Difficulty: UVa Star 2
 * Tags: dynamic-programming
 * URL: https://onlinejudge.org/external/106/10664.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine if a set of suitcase weights can be divided into two cars with exactly equal total weight.
 *
 * [中文] 題目說明:
 *     給定一組行李箱重量，判定是否能將行李完全均分為總重恰好相等的兩份 (子集和問題)。
 *
 * [EN] Approach:
 *     Subset sum DP: check if sum % 2 == 0 and if target = sum / 2 is achievable using 0/1 knapsack.
 * [中文] 思路:
 *     子集和動態規劃：若總重為奇數則必無法平分；若為偶數，則以 0/1 背包判斷能否剛好湊出 target = sum / 2。
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

int solve_uva10664(int n, int *w) {
    int sum = 0;
    for (int i = 0; i < n; i++) sum += w[i];
    if (sum % 2 != 0) return 0;
    int target = sum / 2;
    int dp[205] = {0};
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = target; j >= w[i]; j--) {
            if (dp[j - w[i]]) dp[j] = 1;
        }
    }
    return dp[target];
}

int main(void) {

    int w1[] = {1, 2, 1, 2}; // sum 6, target 3 -> YES
    int w2[] = {2, 3, 4};    // sum 9 -> NO
    int ok = solve_uva10664(4, w1) && !solve_uva10664(3, w2);
    printf("%s: UVa 10664 - Luggage\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
