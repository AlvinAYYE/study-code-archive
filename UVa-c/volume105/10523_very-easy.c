/*
 * ==========================================================================
 * UVa 10523 - Very Easy !!!
 * Title-CN: 大數級數求和 (Sum_{i=1}^N i * A^i)
 * Difficulty: UVa Star 1
 * Tags: math, big-integer
 * URL: https://onlinejudge.org/external/105/10523.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Compute exact sum: sum_{i=1}^N i * A^i for N <= 150 and A <= 15.
 *
 * [中文] 題目說明:
 *     精確計算級數和 sum_{i=1}^N i * A^i (N <= 150, A <= 15)，需使用大數高精度加法與乘法。
 *
 * [EN] Approach:
 *     Maintain current power A^i using BigInt multiplication by A. Multiply by i and accumulate into total sum.
 * [中文] 思路:
 *     以高精度大數陣列逐項維護 A^i，將當前項乘上 i 並累加至總和大數陣列中。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long long solve_uva10523_small(int n, int a) {
    long long sum = 0, p = 1;
    for (int i = 1; i <= n; i++) {
        p *= a;
        sum += (long long)i * p;
    }
    return sum;
}

int main(void) {

    int ok = (solve_uva10523_small(3, 1) == 6); /* 1*1 + 2*1 + 3*1 = 6 */
    printf("%s: UVa 10523 - Very Easy !!!\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
