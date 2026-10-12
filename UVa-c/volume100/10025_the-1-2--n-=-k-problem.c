/*
 * ==========================================================================
 * UVa 10025 - The 1 2 ... n = k problem
 * Title-CN: 加減符號求和問題
 * Difficulty: UVa Star 1
 * Tags: math, greedy
 * URL: https://onlinejudge.org/external/100/10025.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find minimum n such that +/- 1 +/- 2 +/- ... +/- n = k.
 *
 * [中文] 題目說明:
 *     在 1 到 n 每個數前加上正負號，使其和等於 k。求最小的正整數 n。
 *
 * [EN] Approach:
 *     Let S = n*(n+1)/2 >= |k|. If (S - |k|) % 2 == 0, n is minimal answer.
 *     Otherwise increment n until condition is met.
 * [中文] 思路:
 *     取絕對值 k = |k|。尋找最小 n 使得 1+2+...+n = S >= k 且 (S - k) 為偶數。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>

long long solve_uva10025(long long k) {
    if (k < 0) k = -k;
    if (k == 0) return 3; /* 1 + 2 - 3 = 0, n=3 */
    long long n = 1;
    long long s = 1;
    while (s < k || (s - k) % 2 != 0) {
        n++;
        s += n;
    }
    return n;
}

int main(void) {
    int ok = (solve_uva10025(12) == 7) && (solve_uva10025(1) == 1);
    printf("%s: UVa 10025 - The 1 2 ... n = k problem\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
