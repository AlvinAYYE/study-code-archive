/*
 * ==========================================================================
 * UVa 201 - Squares
 * Title-CN: 正方形計數 (網格點連線幾何)
 * Difficulty: UVa Star 2
 * Tags: geometry, simulation, grid
 * URL: https://onlinejudge.org/external/2/201.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given horizontal and vertical segments between n x n points, count how many squares of each size k exist.
 *
 * [中文] 題目說明:
 *     在 n x n 的點陣圖中給定水平與垂直連接線段，統計所有邊長為 k 的封閉正方形總數。
 *
 * [EN] Approach:
 *     Precompute right and down continuous segment lengths from each point. Check 4 corners for each size k.
 * [中文] 思路:
 *     預先計算每個點向右與向下的連續邊長長度。枚舉左上角點 (r, c) 與邊長 k，若四邊皆存在長度至少為 k 則計數 +1。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int count_squares_201(int n, int h[10][10], int v[10][10], int size) {
    int cnt = 0;
    for (int r = 1; r + size <= n; r++) {
        for (int c = 1; c + size <= n; c++) {
            int valid = 1;
            for (int k = 0; k < size; k++) {
                if (!h[r][c + k] || !h[r + size][c + k] || !v[r + k][c] || !v[r + k][c + size]) {
                    valid = 0; break;
                }
            }
            if (valid) cnt++;
        }
    }
    return cnt;
}

int main(void) {

    int h[10][10] = {0}, v[10][10] = {0};
    h[1][1] = h[2][1] = 1;
    v[1][1] = v[1][2] = 1;
    int ok = (count_squares_201(2, h, v, 1) == 1);
    printf("%s: UVa 201 - Squares\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
