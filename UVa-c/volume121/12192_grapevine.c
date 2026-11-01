/*
 * ==========================================================================
 * UVa 12192 - Grapevine
 * Title-CN: 葡萄園中最大符合高度區間正方形
 * Difficulty: Medium
 * Tags: Binary Search, 2D Matrix
 * URL: https://onlinejudge.org/external/121/12192.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the maximum side length of a square subgrid where all elements are within [L, U] in a row/col sorted matrix.
 *
 * [中文] 題目描述:
 *     在每列每行均非遞減的二維高度矩陣中，求數值均在 [L, U] 之間的最大正方形子網格邊長。
 *
 * [EN] Approach:
 *     For each row, binary search the first column >= L. Then check if square of side (ans + 1) fits within U along the diagonal.
 *
 * [中文] 解題思維:
 *     對每一列二分搜尋第一個 >= L 的欄位 c，若對角線上的位置 (r+ans, c+ans) <= U 則嘗試擴展最大邊長。
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

int max_grapevine_square(int n, int m, int mat[505][505], int L, int U) {
    int max_side = 0;
    for (int r = 0; r < n; r++) {
        // Lower bound for L in row r
        int low = 0, high = m - 1, first_col = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (mat[r][mid] >= L) {
                first_col = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if (first_col == -1) continue;

        for (int k = max_side; ; k++) {
            if (r + k >= n || first_col + k >= m) break;
            if (mat[r + k][first_col + k] <= U) {
                if (k + 1 > max_side) max_side = k + 1;
            } else {
                break;
            }
        }
    }
    return max_side;
}

int main(void) {

    int mat[505][505] = {
        {13, 21, 25, 33},
        {22, 34, 42, 51},
        {23, 35, 43, 62}
    };
    // For L=20, U=45: 2x2 square [0..1][1..2] has values {21,25,34,42} all <= 45
    int res = max_grapevine_square(3, 4, mat, 20, 45);
    int ok = (res == 2);
    printf("%s: UVa 12192 - Grapevine\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
