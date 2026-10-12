/*
 * ==========================================================================
 * UVa 10306 - e-Coins
 * Title-CN: 電子硬幣 (二維完全背包)
 * Difficulty: UVa Star 2
 * Tags: dynamic-programming, knapsack
 * URL: https://onlinejudge.org/external/103/10306.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find minimal coin count to reach value S where value is sqrt(x^2 + y^2) = S.
 *
 * [中文] 題目說明:
 *     每枚電子硬幣有 (x, y) 兩屬性，求湊出 x^2 + y^2 = S^2 所需的最少硬幣數量。
 *
 * [EN] Approach:
 *     2D unbounded knapsack DP: dp[x][y] = min coin count to reach coordinate (x, y).
 * [中文] 思路:
 *     二維完全背包動態規劃，最後檢查所有滿足 x^2 + y^2 = S^2 的 dp[x][y] 取最小值。
 * ==========================================================================
 */
#include <stdio.h>

#define INF 1000000000
static inline int min_val(int a, int b) { return a < b ? a : b; }

int solve_uva10306(int m, int s, const int coins[][2]) {
    int dp[305][305];
    for (int i = 0; i <= s; i++) {
        for (int j = 0; j <= s; j++) dp[i][j] = INF;
    }
    dp[0][0] = 0;
    for (int k = 0; k < m; k++) {
        int cx = coins[k][0], cy = coins[k][1];
        for (int x = cx; x <= s; x++) {
            for (int y = cy; y <= s; y++) {
                if (dp[x - cx][y - cy] != INF) {
                    dp[x][y] = min_val(dp[x][y], dp[x - cx][y - cy] + 1);
                }
            }
        }
    }
    int s2 = s * s, ans = INF;
    for (int x = 0; x <= s; x++) {
        for (int y = 0; y <= s; y++) {
            if (x * x + y * y == s2) ans = min_val(ans, dp[x][y]);
        }
    }
    return (ans >= INF) ? -1 : ans;
}

int main(void) {
    int c[2][2] = {{0, 2}, {3, 0}}; /* (3, 4) distance = 5 using 1*(3,0) + 2*(0,2) = 3 coins? (3^2 + 4^2 = 25) */
    int res = solve_uva10306(2, 5, c);
    int ok = (res == 3);
    printf("%s: UVa 10306 - e-Coins\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
