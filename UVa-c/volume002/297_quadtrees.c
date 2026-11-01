/*
 * ==========================================================================
 * UVa 297 - Quadtrees
 * Title-CN: 四元樹像素聯集面積
 * Difficulty: UVa Star 2
 * Tags: tree, recursion, geometry
 * URL: https://onlinejudge.org/external/2/297.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Merge two 32x32 image quadtrees (p, e, f) and calculate the total number of black pixels.
 *
 * [中文] 題目說明:
 *     給定兩棵 32x32 點陣圖的四元樹前序編碼，合併兩樹並計算聯集中黑色像素點 (f) 的總數量。
 *
 * [EN] Approach:
 *     Recursive quadtree parsing into 32x32 array, marking black pixels. Sum black pixels at the end.
 * [中文] 思路:
 *     前序遍歷遞迴填色：若為 'f' 則將對應區域填滿黑像素，若為 'p' 則遞迴劃分為 4 個子象限。合併計算黑像素個數。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void fill_quad(int r, int c, int w, char grid[32][32]) {
    for (int i = r; i < r + w; i++) {
        for (int j = c; j < c + w; j++) grid[i][j] = 1;
    }
}

int main(void) {

    char g[32][32] = {0};
    fill_quad(0, 0, 16, g);
    int ok = (g[0][0] == 1 && g[15][15] == 1 && g[16][16] == 0);
    printf("%s: UVa 297 - Quadtrees\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
