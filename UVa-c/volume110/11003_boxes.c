/*
 * ==========================================================================
 * UVa 11003 - Boxes
 * Title-CN: 箱子堆疊 (重量與承重極限DP)
 * Difficulty: Medium
 * Tags: DP, Knapsack, LIS
 * URL: https://onlinejudge.org/external/110/11003.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Stack boxes of given weights and load capacities from top to bottom such that each box supports the total weight of all boxes above it. Maximize count.
 *
 * [中文] 題目說明:
 *     依順序自頂向下疊放箱子，每隻箱子所承載的上方箱子總重量不可超過其負重上限，求最多能疊放的箱子數量。
 *
 * [EN] Approach:
 *     DP state dp[w] = maximum number of boxes stacked with total weight w. For each box from top to bottom, update dp[w + weight[i]] = max(dp[w] + 1) for w <= load[i].
 * [中文] 思路:
 *     動態規劃：dp[w] 表示當前上方總重為 w 時最多能堆疊的箱子數。對每隻箱子，在 w <= load 時更新 dp[w + weight] = max(dp[w] + 1)。
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

int max_stacked_boxes(int n, const int *weight, const int *load) {
    int dp[3005];
    for (int i = 0; i <= 3000; i++) dp[i] = -1;
    dp[0] = 0;
    int max_cnt = 0;
    for (int i = 0; i < n; i++) {
        int w = weight[i], l = load[i];
        for (int j = l; j >= 0; j--) {
            if (dp[j] != -1 && j + w <= 3000) {
                if (dp[j] + 1 > dp[j + w]) {
                    dp[j + w] = dp[j] + 1;
                    if (dp[j + w] > max_cnt) max_cnt = dp[j + w];
                }
            }
        }
    }
    return max_cnt;
}

int main(void) {

    int w[] = {19, 7, 5}, l[] = {15, 6, 100};
    int res = max_stacked_boxes(3, w, l);
    int ok = (res == 2);
    printf("%s: UVa 11003 - Boxes\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
