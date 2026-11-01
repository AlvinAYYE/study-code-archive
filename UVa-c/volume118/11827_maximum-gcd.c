/*
 * ==========================================================================
 * UVa 11827 - Maximum GCD
 * Title-CN: 整數數列兩兩最大公因數之極大值
 * Difficulty: UVa Star 1
 * Tags: math, number-theory
 * URL: https://onlinejudge.org/external/118/11827.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given N integers, find the maximum greatest common divisor (GCD) among all possible pairs (a_i, a_j) with i != j.
 *
 * [中文] 題目說明:
 *     給定包含 N 個整數的數列，求任兩數 (a_i, a_j) 間的最大公因數 (GCD) 之最大值。
 *
 * [EN] Approach:
 *     Pairwise enumeration: compute gcd(a[i], a[j]) for all 0 <= i < j < N using Euclidean algorithm, and keep track of maximum.
 * [中文] 思路:
 *     雙重迴圈枚舉所有數對，以輾轉相除法求每對之 GCD，動態維護最大值並回傳。
 * ==========================================================================
 * UVa Online Judge Submission Template:
 * #include <stdio.h>
 * #include <stdlib.h>
 * #include <string.h>
 * #include <math.h>
 *
 * int main(void) {
 *     // Read input and call logic function
 *     return 0;
 * }
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

int gcd11827(int a, int b) {
    while (b) { int t = a % b; a = b; b = t; }
    return a;
}

int solve_uva11827(int n, int *a) {
    int max_g = 1;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int g = gcd11827(a[i], a[j]);
            if (g > max_g) max_g = g;
        }
    }
    return max_g;
}

int main(void) {

    int a[] = {10, 20, 30, 40};
    int ans = solve_uva11827(4, a);
    int ok = (ans == 20); // gcd(20, 40) = 20
    printf("%s: UVa 11827 - Maximum GCD\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
