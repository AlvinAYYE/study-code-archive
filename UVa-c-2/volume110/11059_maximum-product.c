/*
 * ==========================================================================
 * UVa 11059 - Maximum Product
 * Title-CN: 最大連續子序列乘積
 * Difficulty: UVa Star 1
 * Tags: math, dynamic-programming
 * URL: https://onlinejudge.org/external/110/11059.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the maximum product of contiguous subsegment (return 0 if all products are negative).
 *
 * [中文] 題目說明:
 *     求陣列中連續子序列的最大乘積（若所有乘積皆為負數則回傳 0）。
 *
 * [EN] Approach:
 *     O(N^2) double loop product accumulation with 64-bit integer.
 * [中文] 思路:
 *     由於 N <= 18，使用 64 位元整數進行雙重迴圈枚舉連續區間乘積取最大值。
 * ==========================================================================
 */
#include <stdio.h>

long long solve_uva11059(int n, const int *arr) {
    long long max_p = 0;
    for (int i = 0; i < n; i++) {
        long long cur = 1;
        for (int j = i; j < n; j++) {
            cur *= arr[j];
            if (cur > max_p) max_p = cur;
        }
    }
    return max_p;
}

int main(void) {
    int a[3] = {2, 4, -3};
    long long res = solve_uva11059(3, a);
    int ok = (res == 8);
    printf("%s: UVa 11059 - Maximum Product\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
