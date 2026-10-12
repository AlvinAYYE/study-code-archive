/*
 * ==========================================================================
 * UVa 10130 - SuperSale
 * Title-CN: 超級特賣會
 * Difficulty: UVa Star 1
 * Tags: dynamic-programming, knapsack
 * URL: https://onlinejudge.org/external/101/10130.pdf
 * ==========================================================================
 * [EN] Problem:
 *     0-1 Knapsack problem for multiple people with individual carrying limits.
 *
 * [中文] 題目說明:
 *     給定多件物品的價格與重量，每人有各自的最大負重，每件物品每人至多拿一件，求全家最大總價值。
 *
 * [EN] Approach: Compute 0-1 knapsack dp array up to max weight 30. Sum dp[w_i] for all family members.
 * [中文] 思路: 經典 0-1 背包動態規劃，預先計算上限 30 的背包 DP，累加每位家庭成員最大承重的值。
 * ==========================================================================
 */
#include <stdio.h>

static inline int max_val(int a, int b) { return a > b ? a : b; }

int solve_uva10130(int n, const int price[], const int weight[], int g, const int max_w[]) {
    int dp[35] = {0};
    for (int i = 0; i < n; i++) {
        for (int w = 30; w >= weight[i]; w--) {
            dp[w] = max_val(dp[w], dp[w - weight[i]] + price[i]);
        }
    }
    int total = 0;
    for (int i = 0; i < g; i++) {
        total += dp[max_w[i]];
    }
    return total;
}

int main(void) {
    int p[] = {72, 44, 31};
    int w[] = {17, 23, 24};
    int mw[] = {26};
    int res = solve_uva10130(3, p, w, 1, mw);
    int ok = (res == 72);
    printf("%s: UVa 10130 - SuperSale\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
