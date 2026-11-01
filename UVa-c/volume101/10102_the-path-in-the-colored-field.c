/*
 * ==========================================================================
 * UVa 10102 - The path in the colored field
 * Title-CN: 著色棋盤最短抵達最大值 (Minimax 曼哈頓距離)
 * Difficulty: UVa Star 1
 * Tags: brute-force, grid, geometry
 * URL: https://onlinejudge.org/external/101/10102.pdf
 * ==========================================================================
 * [EN] Problem:
 *     For all '1's in grid, find distance to closest '3'. Maximize this distance over all '1's.
 *
 * [中文] 題目說明:
 *     對網格中所有數字 '1' 尋找最近的數字 '3' 的曼哈頓距離，求所有 '1' 到其最近 '3' 的距離的最大值 (Minimax)。
 *
 * [EN] Approach:
 *     Enumerate each '1' and find min |r1 - r3| + |c1 - c3| to all '3's. Take maximum among all '1's.
 * [中文] 思路:
 *     雙重枚舉：記錄所有 '1' 與 '3' 的座標，對每個 '1' 計算其到所有 '3' 的曼哈頓距離最小值，再取全局最大值。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <stdlib.h>

int solve_uva10102(int n1, int r1[], int c1[], int n3, int r3[], int c3[]) {
    int max_d = 0;
    for (int i = 0; i < n1; i++) {
        int min_d = 1e9;
        for (int j = 0; j < n3; j++) {
            int d = abs(r1[i] - r3[j]) + abs(c1[i] - c3[j]);
            if (d < min_d) min_d = d;
        }
        if (min_d > max_d) max_d = min_d;
    }
    return max_d;
}

int main(void) {

    int r1[1] = {0}, c1[1] = {0};
    int r3[1] = {2}, c3[1] = {2};
    int ok = (solve_uva10102(1, r1, c1, 1, r3, c3) == 4);
    printf("%s: UVa 10102 - The path in the colored field\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
