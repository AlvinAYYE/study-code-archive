/*
 * ==========================================================================
 * UVa 10667 - Largest Block
 * Title-CN: 最大無障礙子矩陣
 * Difficulty: Medium
 * Tags: DP, Maximum Submatrix
 * URL: https://onlinejudge.org/external/106/10667.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the maximum area of a subgrid of all 1s (unblocked cells) in an S x S chessboard containing blocked rectangular areas.
 *
 * [中文] 題目說明:
 *     在含若干障礙矩形區塊的 S x S 棋盤中，求全為 1（無障礙）的最大子矩陣面積。
 *
 * [EN] Approach:
 *     Compress rows into 1D histograms of consecutive 1s and compute largest rectangle in histogram, or 2D prefix sums.
 * [中文] 思路:
 *     將二維矩陣每行轉為連續 1 的直方圖高度，利用單調棧或枚舉上下界求最大全 1 矩形面積。
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

int max_unblocked_block(int s, int grid[10][10]) {
    int max_area = 0;
    int h[10] = {0};
    for (int r = 0; r < s; r++) {
        for (int c = 0; c < s; c++) {
            h[c] = (grid[r][c] == 0 ? h[c] + 1 : 0);
        }
        for (int i = 0; i < s; i++) {
            int mn_h = h[i];
            for (int j = i; j < s; j++) {
                if (h[j] < mn_h) mn_h = h[j];
                int area = mn_h * (j - i + 1);
                if (area > max_area) max_area = area;
            }
        }
    }
    return max_area;
}

int main(void) {

    int g[10][10] = {{0, 0}, {0, 0}}; // all unblocked
    int ok = (max_unblocked_block(2, g) == 4);
    printf("%s: UVa 10667 - Largest Block\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
