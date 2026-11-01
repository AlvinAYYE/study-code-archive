/*
 * ==========================================================================
 * UVa 270 - Lining Up
 * Title-CN: 最多共線點數 (幾何斜率枚舉)
 * Difficulty: UVa Star 2
 * Tags: geometry, math, brute-force
 * URL: https://onlinejudge.org/external/2/270.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given up to 700 2D points, find maximum number of points lying on a single straight line.
 *
 * [中文] 題目說明:
 *     給定平面上最多 700 個點，求能位在同一條直線上的最大點數。
 *
 * [EN] Approach:
 *     For each point i, compute slopes to all other points j, sort slopes and find maximum frequency.
 * [中文] 思路:
 *     對每個基準點 i 計算與其他點的斜率 (以化簡分數表示)，排序斜率統計出現頻率的最大值。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva270_collinear(int n, int x[], int y[]) {
    int max_pts = (n >= 2) ? 2 : n;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int cnt = 2;
            long long dx = x[j] - x[i], dy = y[j] - y[i];
            for (int k = j + 1; k < n; k++) {
                if ((long long)(x[k] - x[i]) * dy == (long long)(y[k] - y[i]) * dx) cnt++;
            }
            if (cnt > max_pts) max_pts = cnt;
        }
    }
    return max_pts;
}

int main(void) {

    int px[4] = {0, 1, 2, 5};
    int py[4] = {0, 1, 2, 9};
    int ok = (solve_uva270_collinear(4, px, py) == 3);
    printf("%s: UVa 270 - Lining Up\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
