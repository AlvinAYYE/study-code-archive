/*
 * ==========================================================================
 * UVa 104 - Arbitrage
 * Title-CN: 套匯獲利鏈
 * Difficulty: UVa Star 3
 * Tags: graph, floyd-warshall, dynamic-programming
 * URL: https://onlinejudge.org/external/1/104.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find minimum length sequence of currency exchanges that yields > 1.01 profit.
 *
 * [中文] 題目說明:
 *     尋找貨幣兌換的最短交易鏈，使兌換回到原貨幣後獲利超過 1% (乘積 > 1.01)。
 *
 * [EN] Approach:
 *     Extended Floyd-Warshall DP: dist[step][i][j] stores max profit from i to j in 'step' exchanges.
 * [中文] 思路:
 *     擴展 Floyd-Warshall：記錄在 step 次兌換下從貨幣 i 到 j 的最大匯率乘積，並記錄路徑。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva104_exists_arbitrage(int n, double table[20][20]) {
    double dp[21][20][20] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[1][i][j] = table[i][j];
        }
    }
    for (int s = 2; s <= n; s++) {
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    double val = dp[s - 1][i][k] * table[k][j];
                    if (val > dp[s][i][j]) dp[s][i][j] = val;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (dp[s][i][i] > 1.01) return s;
        }
    }
    return 0;
}

int main(void) {

    double tbl[3][20] = {
        {1.0, 1.2, 0.8},
        {0.9, 1.0, 1.5},
        {1.1, 0.7, 1.0}
    };
    int s = solve_uva104_exists_arbitrage(3, tbl);
    int ok = (s >= 2);
    printf("%s: UVa 104 - Arbitrage\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
