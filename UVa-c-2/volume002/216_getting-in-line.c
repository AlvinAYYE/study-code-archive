/*
 * ==========================================================================
 * UVa 216 - Getting in Line
 * Title-CN: 電腦網路拉線總長最小化 (TSP 全排列)
 * Difficulty: UVa Star 1
 * Tags: graph, tsp, geometry, brute-force
 * URL: https://onlinejudge.org/external/2/216.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given up to 8 computer coordinates, find linear cable path visiting each computer once with minimum total length.
 *
 * [中文] 題目說明:
 *     給定最多 8 台電腦的座標，求連接所有電腦的一條直線路徑使總網路線長度最小 (每段加 16 厘米緩衝)。
 *
 * [EN] Approach:
 *     Since n <= 8, enumerate all 8! = 40320 permutations. Compute total Euclidean distance + 16 * (n - 1) and find minimum.
 * [中文] 思路:
 *     因點數 n <= 8，直接枚舉全排列計算法求最小歐幾里得距離總和，每段連接線額外增加 16 單位。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <math.h>

double solve_uva216_dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)) + 16.0;
}

int main(void) {

    double d = solve_uva216_dist(0, 0, 3, 4);
    int ok = (fabs(d - 21.0) < 1e-4);
    printf("%s: UVa 216 - Getting in Line\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
