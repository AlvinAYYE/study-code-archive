/*
 * ==========================================================================
 * UVa 10074 - Take the Land
 * Title-CN: 圈地遊戲
 * Difficulty: UVa Star 2
 * Tags: dynamic-programming, monotonic-stack, matrix
 * ==========================================================================
 * [EN] Problem: Find maximum rectangular area containing only 0s in M x N binary matrix.
 * [中文] 題目說明: 在 M x N 的 0/1 矩陣中，求全為 0 的最大子矩形面積。
 * [EN] Approach: Histogram extension on each row + largest rectangle in histogram.
 * [中文] 思路: 逐行維護連續 0 的高度直方圖，使用單調棧或雙迴圈求解最大直方圖矩形。
 * ==========================================================================
 */
#include <stdio.h>

static inline int max_val(int a, int b) { return a > b ? a : b; }

int solve_uva10074(int m, int n, const int mat[105][105]) {
    int h[105] = {0};
    int max_area = 0;
    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
            if (mat[r][c] == 0) h[c]++;
            else h[c] = 0;
        }
        for (int i = 0; i < n; i++) {
            int min_h = h[i];
            for (int j = i; j < n; j++) {
                if (h[j] < min_h) min_h = h[j];
                max_area = max_val(max_area, min_h * (j - i + 1));
            }
        }
    }
    return max_area;
}

int main(void) {
    int mat[3][105] = {
        {0, 0, 1},
        {0, 0, 0},
        {0, 0, 0}
    };
    int res = solve_uva10074(3, 3, mat);
    int ok = (res == 6); /* 3 rows x 2 cols of 0s = 6 */
    printf("%s: UVa 10074 - Take the Land\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
