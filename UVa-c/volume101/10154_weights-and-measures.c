/*
 * ==========================================================================
 * UVa 10154 - Weights and Measures
 * Title-CN: 烏龜疊羅漢 (重量與承重)
 * Difficulty: Hard
 * Tags: DP, Greedy, Sorting
 * URL: https://onlinejudge.org/external/101/10154.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the maximum number of turtles that can be stacked on top of each other such that each turtle can support the total weight above it.
 *
 * [中文] 題目概述:
 *     求最多可將多少隻烏龜疊在一起，使得每隻烏龜都能承受其上方所有烏龜的重量總和。
 *
 * [EN] Approach:
 *     Sort turtles by capacity (strength) ascending. DP state dp[k] = minimum weight of a stack of k turtles. dp[k] = min(dp[k], dp[k-1] + w) if dp[k-1] + w <= s.
 * [中文] 解題思路:
 *     依照承重能力升序排序。動態規劃 dp[k] 表示堆疊 k 隻烏龜的最小總重量，更新 dp[k] = min(dp[k], dp[k-1] + w)。
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

int max_turtles(int n, const int *w, const int *s) {
    int dp[105];
    for (int i = 0; i <= n; i++) dp[i] = 1000000000;
    dp[0] = 0;
    int max_k = 0;
    for (int i = 0; i < n; i++) {
        for (int k = max_k; k >= 0; k--) {
            if (dp[k] + w[i] <= s[i] && dp[k] + w[i] < dp[k + 1]) {
                dp[k + 1] = dp[k] + w[i];
                if (k + 1 > max_k) max_k = k + 1;
            }
        }
    }
    return max_k;
}

int main(void) {

    int w[] = {300, 1000, 200}, s[] = {1000, 1200, 600};
    int ok = (max_turtles(3, w, s) == 2);
    printf("%s: UVa 10154 - Weights and Measures\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
