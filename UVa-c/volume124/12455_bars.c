/*
 * ==========================================================================
 * UVa 12455 - Bars
 * Title-CN: 金屬條湊整長度子集和背包
 * Difficulty: UVa Star 1
 * Tags: dynamic-programming
 * URL: https://onlinejudge.org/external/124/12455.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given target length N and a set of p metal bars, determine if a subset of bars can be welded together to form length exactly N.
 *
 * [中文] 題目說明:
 *     給定目標長度 N 與 p 根金屬條的長度，判定是否能挑選若干根金屬條剛好拼湊成總長度 N (子集和背包問題)。
 *
 * [EN] Approach:
 *     Standard 0/1 knapsack subset sum boolean array dp[0..N].
 * [中文] 思路:
 *     標準 0/1 背包子集和演算法：dp[j] 表示長度 j 是否可達，由後向前更新轉移。
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

int solve_uva12455(int target, int p, int *bars) {
    int dp[1005] = {0};
    dp[0] = 1;
    for (int i = 0; i < p; i++) {
        for (int j = target; j >= bars[i]; j--) {
            if (dp[j - bars[i]]) dp[j] = 1;
        }
    }
    return dp[target];
}

int main(void) {

    int b[] = {10, 20, 5};
    int ok = solve_uva12455(25, 3, b) && !solve_uva12455(16, 3, b);
    printf("%s: UVa 12455 - Bars\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
