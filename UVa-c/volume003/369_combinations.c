/*
 * ==========================================================================
 * UVa 369 - Combinations
 * Title-CN: 組合數精確計算 (防止溢位的 C(N, M))
 * Difficulty: UVa Star 1
 * Tags: math, combinatorics
 * URL: https://onlinejudge.org/external/3/369.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Compute exact combination C(N, M) for N <= 100 without intermediate 64-bit overflow.
 *
 * [中文] 題目說明:
 *     精確計算二項式係數 C(N, M) = N! / (M! * (N-M)!)，避免乘法中途發生數值溢位。
 *
 * [EN] Approach:
 *     Pascal's identity C(n, k) = C(n-1, k-1) + C(n-1, k) or running multiplication with GCD division.
 * [中文] 思路:
 *     以巴斯卡三角形動態規劃預先建表，或在乘法過程中逐項除以因子，確保計算中途數值不溢位。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long long solve_uva369(int n, int m) {
    if (m > n - m) m = n - m;
    long long ans = 1;
    for (int i = 1; i <= m; i++) {
        ans = ans * (n - i + 1) / i;
    }
    return ans;
}

int main(void) {

    int ok = (solve_uva369(100, 6) == 1192052400LL);
    printf("%s: UVa 369 - Combinations\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
