/*
 * ==========================================================================
 * UVa 152 - Tree's a Crowd
 * Title-CN: 擁擠的樹林 (3D 歐式距離分佈)
 * Difficulty: UVa Star 1
 * Tags: geometry, math, brute-force
 * URL: https://onlinejudge.org/external/1/152.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given up to 5000 3D tree coordinates, find distance to closest neighbor for each tree and build histogram.
 *
 * [中文] 題目說明:
 *     給定最多 5000 棵樹的 3D 座標，計算每棵樹與最近鄰樹的距離，並統計 0..9 距離區間的樹木數量直方圖。
 *
 * [EN] Approach:
 *     Pairwise 3D Euclidean distance calculation. Find minimum distance per tree and increment histogram bin.
 * [中文] 思路:
 *     雙重迴圈枚舉點對計算 3D 距離平方。對每棵樹求最近鄰距離，並將結果累加至對應區間桶中。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <math.h>

void solve_uva152(int n, int x[], int y[], int z[], int hist[10]) {
    for (int i = 0; i < 10; i++) hist[i] = 0;
    for (int i = 0; i < n; i++) {
        double min_d = 1e9;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            double dx = x[i] - x[j], dy = y[i] - y[j], dz = z[i] - z[j];
            double d = sqrt(dx*dx + dy*dy + dz*dz);
            if (d < min_d) min_d = d;
        }
        int bin = (int)floor(min_d);
        if (bin >= 0 && bin < 10) hist[bin]++;
    }
}

int main(void) {

    int x[3] = {0, 3, 100};
    int y[3] = {0, 4, 100};
    int z[3] = {0, 0, 100};
    int h[10];
    solve_uva152(3, x, y, z, h);
    int ok = (h[5] == 2);
    printf("%s: UVa 152 - Tree's a Crowd\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
