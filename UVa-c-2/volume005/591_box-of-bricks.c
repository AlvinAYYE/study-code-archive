/*
 * ==========================================================================
 * UVa 591 - Box of Bricks
 * Title-CN: 積木柱高度平攤
 * Difficulty: UVa Star 1
 * Tags: math, array
 * ==========================================================================
 * [EN] Problem: Equalize stack heights of bricks with minimum block moves.
 * [中文] 題目說明: 將各柱積木平攤為相同高度，求最少需搬移的積木數量。
 * [EN] Approach: Compute avg = sum / n. Moves = sum max(0, h_i - avg).
 * [中文] 思路: 計算平均高度，統計所有高於平均之積木總超額數。
 * ==========================================================================
 */
#include <stdio.h>

int solve_uva591(int n, const int *h) {
    int sum = 0;
    for (int i = 0; i < n; i++) sum += h[i];
    int avg = sum / n;
    int moves = 0;
    for (int i = 0; i < n; i++) {
        if (h[i] > avg) moves += h[i] - avg;
    }
    return moves;
}

int main(void) {
    int h[6] = {5, 2, 4, 1, 7, 5};
    int res = solve_uva591(6, h);
    int ok = (res == 5);
    printf("%s: UVa 591 - Box of Bricks\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
