/*
 * ==========================================================================
 * UVa 13185 - DPA Numbers
 * Title-CN: 真因數和性質分類 (虧數、完全數、盈數)
 * Difficulty: UVa Star 1
 * Tags: math, number-theory
 * URL: https://onlinejudge.org/external/131/13185.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Classify number as deficient (sum of proper divisors < n), perfect (== n), or abundant (> n).
 *
 * [中文] 題目說明:
 *     計算正整數的所有真因數之和，分類判定其為虧數 (deficient)、完全數 (perfect) 還是盈數 (abundant)。
 *
 * [EN] Approach:
 *     Compute aliquot sum = sum of proper divisors up to n/2. Compare with n.
 * [中文] 思路:
 *     迴圈枚舉 1 到 n/2 求所有真因數之和：小於 n 輸出 deficient，等於 n 輸出 perfect，大於 n 輸出 abundant。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

const char* solve_uva13185(int n) {
    int sum = 0;
    for (int i = 1; i * 2 <= n; i++) {
        if (n % i == 0) sum += i;
    }
    if (sum == n) return "perfect";
    if (sum < n) return "deficient";
    return "abundant";
}

int main(void) {

    int ok = (strcmp(solve_uva13185(6), "perfect") == 0) &&
             (strcmp(solve_uva13185(4), "deficient") == 0) &&
             (strcmp(solve_uva13185(12), "abundant") == 0);
    printf("%s: UVa 13185 - DPA Numbers\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
