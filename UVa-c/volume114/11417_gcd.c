/*
 * ==========================================================================
 * UVa 11417 - GCD
 * Title-CN: 最大公因數求和
 * Difficulty: UVa Star 1 / CPE 49 顆星必考題
 * Tags: math, gcd, number-theory
 * URL: https://onlinejudge.org/external/114/11417.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Compute G = sum_{i=1}^{N-1} sum_{j=i+1}^N gcd(i, j).
 *
 * [中文] 題目說明:
 *     計算 G = sum_{i=1}^{N-1} sum_{j=i+1}^N gcd(i, j) 的值。
 *
 * [EN] Approach: Nested loops with Euclidean GCD algorithm for N <= 500.
 * [中文] 思路: 由於 N <= 500，雙重迴圈結合輾轉相除法求 GCD 加總。
 * ==========================================================================
 */
#include <stdio.h>

static int gcd(int a, int b) {
    while (b) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

long long solve_uva11417(int n) {
    long long g = 0;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            g += gcd(i, j);
        }
    }
    return g;
}

int main(void) {
    int ok = (solve_uva11417(10) == 67);
    printf("%s: UVa 11417 - GCD\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
