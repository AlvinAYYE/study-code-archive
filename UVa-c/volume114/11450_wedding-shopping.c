/*
 * ==========================================================================
 * UVa 11450 - Wedding shopping
 * Title-CN: 婚禮採購預算最大化動態規劃
 * Difficulty: UVa Star 2
 * Tags: dynamic-programming
 * URL: https://onlinejudge.org/external/114/11450.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given budget M and C garment categories, pick one item from each category to maximize total spend <= M, or report no solution.
 *
 * [中文] 題目說明:
 *     在預算上限 M 內，於 C 類婚禮服飾中每類各挑選一件商品，求總花費小於等於 M 的最大支出金額。
 *
 * [EN] Approach:
 *     2D boolean DP: dp[garment_idx][spent_money] = 1. Update layer by layer; return maximum reachable money in final layer.
 * [中文] 思路:
 *     二維布林背包動態規劃：dp[c][money] 表示前 c 類商品是否能剛好湊出 money，逐層轉移取最終層最大合法金額。
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

int solve_uva11450(int m, int c, int k[20], int price[20][20]) {
    int dp[205] = {0};
    dp[0] = 1;
    for (int i = 0; i < c; i++) {
        int next_dp[205] = {0};
        for (int p = 0; p <= m; p++) {
            if (dp[p]) {
                for (int j = 0; j < k[i]; j++) {
                    if (p + price[i][j] <= m) {
                        next_dp[p + price[i][j]] = 1;
                    }
                }
            }
        }
        memcpy(dp, next_dp, sizeof(dp));
    }
    for (int p = m; p >= 0; p--) {
        if (dp[p]) return p;
    }
    return -1;
}

int main(void) {

    int k[3] = {3, 2, 2};
    int pr[20][20] = {{6, 4, 8}, {5, 10}, {1, 5}};
    int res = solve_uva11450(20, 3, k, pr);
    int ok = (res == 19); // 8 + 10 + 1 = 19
    printf("%s: UVa 11450 - Wedding shopping\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
