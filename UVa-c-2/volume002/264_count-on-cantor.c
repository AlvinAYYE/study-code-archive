/*
 * ==========================================================================
 * UVa 264 - Count on Cantor
 * Title-CN: 康托爾數列
 * Difficulty: UVa Star 1
 * Tags: math
 * ==========================================================================
 * [EN] Problem: Find numerator and denominator of N-th rational number on Cantor's zigzag diagonal.
 * [中文] 題目說明: 康托爾 Z 字形對角線走訪，求第 N 個分數的分子與分母。
 * [EN] Approach: Determine diagonal layer k using triangular numbers, compute offset.
 * [中文] 思路: 由三角數找出所在第 k 條對角線，根據奇偶方向計算分子與分母。
 * ==========================================================================
 */
#include <stdio.h>
#include <math.h>

void solve_uva264(int n, int *num, int *den) {
    int k = 1;
    while (k * (k + 1) / 2 < n) k++;
    int prev = (k - 1) * k / 2;
    int offset = n - prev;
    if (k % 2 == 1) {
        *num = k - offset + 1;
        *den = offset;
    } else {
        *num = offset;
        *den = k - offset + 1;
    }
}

int main(void) {
    int n, d;
    solve_uva264(7, &n, &d);
    int ok = (n == 1 && d == 4);
    printf("%s: UVa 264 - Count on Cantor\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
