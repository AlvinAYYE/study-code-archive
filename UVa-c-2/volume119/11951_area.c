/*
 * ==========================================================================
 * UVa 11951 - Area
 * Title-CN: 購地面積與最小開銷 (最大面積預算子矩陣)
 * Difficulty: Medium
 * Tags: DP, 2D Prefix Sums, Two Pointers
 * URL: https://onlinejudge.org/external/119/11951.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find a subgrid of maximum area within budget K. If multiple subgrids have the same maximum area, choose the one with minimum cost.
 *
 * [中文] 題目說明:
 *     在預算 K 內購買一塊面積最大的連續矩形土地；若面積相同，取購地花費最小者。
 *
 * [EN] Approach:
 *     Enumerate row bounds r1 and r2. Collapse columns into 1D array, then use two pointers to find maximum width with sum <= K.
 * [中文] 思路:
 *     枚舉上下邊界，列壓縮為一維陣列後使用雙指針（滑動窗口）在 O(C) 內求不超過預算 K 的最大寬度，更新全局最大面積與最小花費。
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

void max_land_area_cost(int R, int C, long long K, int price[10][10], int *best_area, long long *best_cost) {
    *best_area = 0;
    *best_cost = 0;
    for (int r1 = 0; r1 < R; r1++) {
        long long col_sum[10] = {0};
        for (int r2 = r1; r2 < R; r2++) {
            for (int c = 0; c < C; c++) col_sum[c] += price[r2][c];
            int l = 0;
            long long cur_sum = 0;
            for (int r = 0; r < C; r++) {
                cur_sum += col_sum[r];
                while (cur_sum > K && l <= r) { cur_sum -= col_sum[l++]; }
                if (cur_sum <= K && l <= r) {
                    int area = (r2 - r1 + 1) * (r - l + 1);
                    if (area > *best_area || (area == *best_area && cur_sum < *best_cost)) {
                        *best_area = area;
                        *best_cost = cur_sum;
                    }
                }
            }
        }
    }
}

int main(void) {

    int p[10][10] = {{1, 2}, {3, 4}};
    int a; long long c;
    max_land_area_cost(2, 2, 5, p, &a, &c);
    int ok = (a > 0 && c <= 5);
    printf("%s: UVa 11951 - Area\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
