/*
 * ==========================================================================
 * UVa 10161 - Ant on a Chessboard
 * Title-CN: 棋盤上的螞蟻
 * Difficulty: UVa Star 1
 * Tags: math
 * ==========================================================================
 * [EN] Problem: Determine coordinate (x, y) of cell N in a spiral traversal pattern.
 * [中文] 題目說明: 螞蟻沿著 L 型軌跡走訪第一象限網格，求第 N 秒時螞蟻所在的座標 (x, y)。
 * [EN] Approach: Find layer ceil(sqrt(N)), calculate offset from middle of layer.
 * [中文] 思路: 層數 k = ceil(sqrt(N))，根據 k 的奇偶性決定方向並依剩餘步數定位。
 * ==========================================================================
 */
#include <stdio.h>
#include <math.h>

void solve_uva10161(long long n, long long *x, long long *y) {
    long long k = (long long)ceil(sqrt((double)n));
    long long mid = k * k - k + 1;
    if (k % 2 == 1) {
        if (n >= mid) { *x = k - (n - mid); *y = k; }
        else { *x = k; *y = k - (mid - n); }
    } else {
        if (n >= mid) { *x = k; *y = k - (n - mid); }
        else { *x = k - (mid - n); *y = k; }
    }
}

int main(void) {
    long long x, y;
    solve_uva10161(8, &x, &y);
    int ok = (x == 2 && y == 3);
    printf("%s: UVa 10161 - Ant on a Chessboard\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
