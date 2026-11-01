/*
 * ==========================================================================
 * UVa 990 - Diving for Gold
 * Title-CN: 潛水淘金
 * Difficulty: Medium
 * Tags: DP, Knapsack
 * URL: https://onlinejudge.org/external/9/990.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the maximum gold a diver can retrieve given total air time t and constant w (air cost = 3 * w * depth).
 *
 * [中文] 題目概述:
 *     給定潛水總氧氣時間 t 與常數 w（下潛與上升耗氣 = 3 * w * 深度），求潛水員可取得黃金的最大總價值。
 *
 * [EN] Approach:
 *     Standard 0/1 knapsack problem where item weight = 3 * w * depth and item value = gold. Backtrack for chosen treasures.
 * [中文] 解題思路:
 *     標準 0/1 背包問題：物品重量為 3 * w * depth，價值為 gold。使用 DP 求解並回溯找出選取的寶藏。
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

int diving_for_gold(int t, int w, int n, const int *depths, const int *golds) {
    int dp[1005] = {0};
    for (int i = 0; i < n; i++) {
        int cost = 3 * w * depths[i];
        for (int j = t; j >= cost; j--) {
            if (dp[j - cost] + golds[i] > dp[j]) {
                dp[j] = dp[j - cost] + golds[i];
            }
        }
    }
    return dp[t];
}

int main(void) {

    int d[] = {10, 20}, g[] = {100, 200};
    // cost 1: 3*2*10 = 60; cost 2: 3*2*20 = 120
    int res = diving_for_gold(200, 2, 2, d, g);
    int ok = (res == 300);
    printf("%s: UVa 990 - Diving for Gold\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
