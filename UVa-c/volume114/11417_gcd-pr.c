/*
 * ==========================================================================
 * UVa 11417 - GCD
 * Title-CN: 雙重迴圈公因數總和
 * Difficulty: UVa Star 1
 * Tags: math, number-theory, gcd
 * URL: https://onlinejudge.org/external/114/11417.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Compute G = sum_{i=1}^{N-1} sum_{j=i+1}^N GCD(i, j) for N <= 500.
 *
 * [中文] 題目說明:
 *     計算所有數對 (i, j) (1 <= i < j <= N) 的最大公因數之和 G (N <= 500)。
 *
 * [EN] Approach:
 *     Precompute GCD table or evaluate double loop using Euclidean GCD algorithm.
 * [中文] 思路:
 *     歐幾里得輾轉相除法：雙重迴圈枚舉 1 <= i < j <= N 累加 gcd(i, j)。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

static int gcd_11417(int a, int b) { while (b) { int t = b; b = a % b; a = t; } return a; }

long long solve_uva11417(int n) {
    long long sum = 0;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            sum += gcd_11417(i, j);
        }
    }
    return sum;
}

int main(void) {

    int ok = (solve_uva11417(10) == 67);
    printf("%s: UVa 11417 - GCD\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
