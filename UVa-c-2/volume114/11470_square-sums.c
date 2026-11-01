/*
 * ==========================================================================
 * UVa 11470 - Square Sums
 * Title-CN: 方形層總和
 * Difficulty: UVa Star 1 / CPE 49 顆星必考題
 * Tags: 2d-array, simulation
 * URL: https://onlinejudge.org/external/114/11470.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Sum concentric square borders of an N x N matrix.
 *
 * [中文] 題目說明:
 *     由外而內計算 N x N 矩陣各層同心方框的元素和。
 *
 * [EN] Approach: Iterate layer by layer, sum edges.
 * [中文] 思路: 遍歷每圈上下左右四條邊界的數值加總。
 * ==========================================================================
 */
#include <stdio.h>

void solve_uva11470(int n, int mat[15][15], int *layer_sums) {
    int layers = (n + 1) / 2;
    for (int k = 0; k < layers; k++) {
        int sum = 0;
        int r1 = k, r2 = n - 1 - k;
        int c1 = k, c2 = n - 1 - k;
        if (r1 == r2) {
            sum += mat[r1][c1];
        } else {
            for (int c = c1; c <= c2; c++) sum += mat[r1][c] + mat[r2][c];
            for (int r = r1 + 1; r < r2; r++) sum += mat[r][c1] + mat[r][c2];
        }
        layer_sums[k] = sum;
    }
}

int main(void) {
    int mat[15][15] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int res[15];
    solve_uva11470(3, mat, res);
    int ok = (res[0] == 40 && res[1] == 5);
    printf("%s: UVa 11470 - Square Sums\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
