/*
 * ==========================================================================
 * UVa 11517 - Exact Change
 * Title-CN: 精準找零超額付款與硬幣枚數最小化
 * Difficulty: UVa Star 2
 * Tags: dynamic-programming
 * URL: https://onlinejudge.org/external/115/11517.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given price P and n coin denominations, pay an amount >= P minimizing the overpaid amount, and minimizing the number of coins used.
 *
 * [中文] 題目說明:
 *     給定商品價格 P 與手頭上的 n 枚硬幣面額，付出大於等於 P 的最小金額，並在金額最小時使用最少數量的硬幣。
 *
 * [EN] Approach:
 *     0/1 Knapsack DP: dp[v] stores minimum coins needed to form exact amount v. Scan from P upwards to find smallest reachable amount.
 * [中文] 思路:
 *     0/1 背包動態規劃：dp[v] 記錄剛好湊出金額 v 所需之最少硬幣數，自 P 向上尋找第一個 dp[v] < INF 之金額。
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

void solve_uva11517(int price, int n, int *coins, int *best_pay, int *min_coins) {
    int dp[20005];
    for (int i = 0; i <= 20000; i++) dp[i] = 1e9;
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int v = 20000; v >= coins[i]; v--) {
            if (dp[v - coins[i]] + 1 < dp[v])
                dp[v] = dp[v - coins[i]] + 1;
        }
    }
    for (int v = price; v <= 20000; v++) {
        if (dp[v] < 1e8) {
            *best_pay = v;
            *min_coins = dp[v];
            return;
        }
    }
}

int main(void) {

    int c[] = {500, 1000, 2000};
    int pay, cnt;
    solve_uva11517(1400, 3, c, &pay, &cnt);
    int ok = (pay == 1500 && cnt == 2); // 500 + 1000 = 1500
    printf("%s: UVa 11517 - Exact Change\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
