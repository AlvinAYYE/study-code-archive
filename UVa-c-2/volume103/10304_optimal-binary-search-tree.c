/*
 * ==========================================================================
 * UVa 10304 - Optimal Binary Search Tree
 * Title-CN: 最優二元搜尋樹 (區間動態規劃)
 * Difficulty: Medium
 * Tags: DP, Interval DP, Knuth Optimization
 * URL: https://onlinejudge.org/external/103/10304.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the minimum search cost of an optimal binary search tree for a sequence of keys with access frequencies.
 *
 * [中文] 題目說明:
 *     給定鍵值的訪問頻率，構建最優二元搜尋樹以最小化檢索所有鍵值的總比較代價。
 *
 * [EN] Approach:
 *     Interval DP: cost[i][j] = min_{k=i}^j (cost[i][k-1] + cost[k+1][j]) + sum(freq[i..j]) - freq[k].
 * [中文] 思路:
 *     區間動態規劃：枚舉子樹根節點 k，狀態轉移 cost[i][j] = min(cost[i][k-1] + cost[k+1][j]) + sum_{t=i}^j freq[t] - freq[k]。
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

int min_obst_cost(int n, const int *f) {
    int sum[100] = {0};
    for (int i = 0; i < n; i++) sum[i + 1] = sum[i] + f[i];
    int dp[50][50] = {0};
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            int total = sum[j + 1] - sum[i];
            int mn = 10000000;
            for (int k = i; k <= j; k++) {
                int left = (k > i ? dp[i][k - 1] : 0);
                int right = (k < j ? dp[k + 1][j] : 0);
                int c = left + right + (total - f[k]);
                if (c < mn) mn = c;
            }
            dp[i][j] = mn;
        }
    }
    return dp[0][n - 1];
}

int main(void) {

    int f[] = {10, 10, 10};
    int cost = min_obst_cost(3, f); // root middle (cost 0), children depth 1 (10 + 10) = 20
    int ok = (cost == 20);
    printf("%s: UVa 10304 - Optimal Binary Search Tree\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
