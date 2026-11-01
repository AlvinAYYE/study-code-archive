/*
 * ==========================================================================
 * UVa 103 - Stacking Boxes
 * Title-CN: 多維箱子巢狀堆疊
 * Difficulty: UVa Star 2
 * Tags: dynamic-programming, dag, sorting, lis
 * URL: https://onlinejudge.org/external/1/103.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given k n-dimensional boxes, find the longest sequence of nested boxes.
 *
 * [中文] 題目說明:
 *     給定 k 個 n 維箱子，判定維度排序後能否完全嵌套，求最長嵌套序列 (DAG 最長路 / LIS)。
 *
 * [EN] Approach:
 *     Sort dimensions of each box. Box A nests in B if each dim of A < B. Build DAG and find longest path with DP.
 * [中文] 思路:
 *     每個箱子的各維度先由小到大排序。若 A 的各維度皆小於 B 則可嵌套。建 DAG 用 DP 求最長路徑。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva103(int k, int n, int boxes[30][10]) {
    for (int i = 0; i < k; i++) {
        for (int a = 0; a < n - 1; a++) {
            for (int b = a + 1; b < n; b++) {
                if (boxes[i][a] > boxes[i][b]) {
                    int t = boxes[i][a]; boxes[i][a] = boxes[i][b]; boxes[i][b] = t;
                }
            }
        }
    }
    int dp[30];
    for (int i = 0; i < k; i++) dp[i] = 1;
    for (int step = 0; step < k; step++) {
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (i == j) continue;
                int can_nest = 1;
                for (int d = 0; d < n; d++) {
                    if (boxes[j][d] >= boxes[i][d]) { can_nest = 0; break; }
                }
                if (can_nest && dp[j] + 1 > dp[i]) dp[i] = dp[j] + 1;
            }
        }
    }
    int max_len = 0;
    for (int i = 0; i < k; i++) if (dp[i] > max_len) max_len = dp[i];
    return max_len;
}

int main(void) {

    int b[5][10] = {{3, 4}, {2, 3}, {1, 2}, {5, 6}, {4, 5}};
    int ok = (solve_uva103(5, 2, b) == 5);
    printf("%s: UVa 103 - Stacking Boxes\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
