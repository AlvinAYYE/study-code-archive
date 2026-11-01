/*
 * ==========================================================================
 * UVa 108 - Maximum Sum
 * Title-CN: 最大二維子矩陣和
 * Difficulty: UVa Star 2
 * Tags: dynamic-programming, 2d-kadane
 * ==========================================================================
 * [EN] Problem: Find maximum submatrix sum in an N x N matrix.
 * [中文] 題目說明: 求 N x N 矩陣中子矩陣元素和的最大值。
 * [EN] Approach: Compress rows between r1 and r2 into 1D array, apply 1D Kadane's algorithm in O(N^3).
 * [中文] 思路: 壓縮上下邊界轉為一維，使用 Kadane 最大子陣列演算法（$O(N^3)$）。
 * ==========================================================================
 */
#include <stdio.h>

static inline int max_val(int a, int b) { return a > b ? a : b; }

int solve_uva108(int n, const int mat[105][105]) {
    int max_sum = -1e9;
    for (int r1 = 0; r1 < n; r1++) {
        int col_sum[105] = {0};
        for (int r2 = r1; r2 < n; r2++) {
            for (int c = 0; c < n; c++) col_sum[c] += mat[r2][c];
            int cur = 0;
            for (int c = 0; c < n; c++) {
                cur = max_val(col_sum[c], cur + col_sum[c]);
                max_sum = max_val(max_sum, cur);
            }
        }
    }
    return max_sum;
}

int main(void) {
    int mat[4][105] = {
        {0, -2, -7, 0},
        {9, 2, -6, 2},
        {-4, 1, -4, 1},
        {-1, 8, 0, -2}
    };
    int res = solve_uva108(4, mat);
    int ok = (res == 15);
    printf("%s: UVa 108 - Maximum Sum\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
