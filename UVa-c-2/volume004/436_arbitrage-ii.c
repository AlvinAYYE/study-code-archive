/*
 * ==========================================================================
 * UVa 436 - Arbitrage (II)
 * Title-CN: 套匯 II (貨幣乘積正環Floyd-Warshall)
 * Difficulty: Medium
 * Tags: Graph, Floyd-Warshall, Shortest Path
 * URL: https://onlinejudge.org/external/4/436.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine if an arbitrage opportunity exists in a currency exchange market (a sequence of trades that starts and ends at the same currency with net gain > 1).
 *
 * [中文] 題目說明:
 *     判斷外匯市場中是否存在套匯套利機會（透過一系列貨幣兌換回到原貨幣後價值嚴格大於 1）。
 *
 * [EN] Approach:
 *     Floyd-Warshall for maximum product: dist[i][j] = max(dist[i][j], dist[i][k] * dist[k][j]). Arbitrage exists if dist[i][i] > 1.0 for any currency i.
 * [中文] 思路:
 *     變形 Floyd-Warshall 求最大匯率連乘積：dist[i][j] = max(dist[i][j], dist[i][k] * dist[k][j])，檢查是否存在 dist[i][i] > 1.0。
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

bool has_arbitrage(int n, double rate[10][10]) {
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (rate[i][k] * rate[k][j] > rate[i][j])
                    rate[i][j] = rate[i][k] * rate[k][j];
    for (int i = 0; i < n; i++) if (rate[i][i] > 1.0001) return true;
    return false;
}

int main(void) {

    double r[10][10] = {{1.0, 2.0}, {0.6, 1.0}}; // 2.0 * 0.6 = 1.2 > 1.0
    int ok = has_arbitrage(2, r);
    printf("%s: UVa 436 - Arbitrage (II)\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
