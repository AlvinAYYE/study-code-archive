/*
 * ==========================================================================
 * UVa 10819 - Trouble of 13-Dots
 * Title-CN: 購物滿額回饋背包動態規劃
 * Difficulty: UVa Star 2
 * Tags: dynamic-programming
 * URL: https://onlinejudge.org/external/108/10819.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Buy items to maximize total favour within budget M. If total spending exceeds 2000, budget increases by a 200 credit-card bonus.
 *
 * [中文] 題目概述:
 *     在預算上限 M 內選購物品使喜愛度總和最大化；若總消費額超過 2000 元，則可額外享有 200 元的信用卡額度回饋。
 *
 * [EN] Approach:
 *     0/1 Knapsack with effective budget up to M + 200. Check validity: spending <= M, OR (spending > 2000 and spending <= M + 200).
 * [中文] 解題思路:
 *     0/1 背包動態規劃：將背包容量開至 M + 200，最後檢驗合法性 (花費 <= M 或 花費在 (2000, M+200] 區間內)，求喜愛度最大值。
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

int solve_uva10819(int m, int n, int *price, int *favour) {
    int cap = m > 1800 ? m + 200 : m;
    int dp[10500];
    for (int i = 0; i <= cap; i++) dp[i] = -1;
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = cap; j >= price[i]; j--) {
            if (dp[j - price[i]] != -1) {
                int val = dp[j - price[i]] + favour[i];
                if (val > dp[j]) dp[j] = val;
            }
        }
    }
    int best = 0;
    for (int j = 0; j <= cap; j++) {
        if (dp[j] > best) {
            if (j <= m || (j > 2000 && j <= m + 200)) best = dp[j];
        }
    }
    return best;
}

int main(void) {

    int p[] = {100, 200}, f[] = {5, 10};
    int res = solve_uva10819(300, 2, p, f);
    int ok = (res == 15);
    printf("%s: UVa 10819 - Trouble of 13-Dots\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
