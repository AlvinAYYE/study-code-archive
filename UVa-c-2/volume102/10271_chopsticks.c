/*
 * ==========================================================================
 * UVa 10271 - Chopsticks
 * Title-CN: 筷子配對 (動態規劃)
 * Difficulty: Hard
 * Tags: DP, Sorting
 * URL: https://onlinejudge.org/external/102/10271.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Choose K+8 sets of 3 chopsticks (A <= B <= C) from N chopsticks to minimize the sum of (A - B)^2.
 *
 * [中文] 題目說明:
 *     從 N 根長度已知的筷子中選出 K+8 組 3 根筷子 (A <= B <= C)，使各組中兩根短筷子長度差平方和 sum((A-B)^2) 最小。
 *
 * [EN] Approach:
 *     Sort descending so that C is safely available. DP state dp[i][j] = min badness picking j triples from first i chopsticks.
 * [中文] 思路:
 *     將筷子降序排序以確保長筷子 C 的存在。動態規劃 dp[i][j] 表示前 i 根筷子中湊出 j 組的最小壞度。
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

int min_chopsticks_badness(int k_sets, int n, const int *len) {
    int dp[50][50] = {0};
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k_sets; j++) dp[i][j] = 10000000;
    for (int i = 3; i <= n; i++) {
        for (int j = 1; j * 3 <= i && j <= k_sets; j++) {
            int diff = len[i-1] - len[i-2];
            int badness = diff * diff;
            int take = dp[i-2][j-1] + badness;
            int leave = dp[i-1][j];
            dp[i][j] = (take < leave ? take : leave);
        }
    }
    return dp[n][k_sets];
}

int main(void) {

    int l[] = {20, 19, 10, 9, 8, 5};
    int res = min_chopsticks_badness(1, 6, l);
    int ok = (res >= 0);
    printf("%s: UVa 10271 - Chopsticks\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
