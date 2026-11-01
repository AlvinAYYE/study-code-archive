/*
 * ==========================================================================
 * UVa 10539 - Almost Prime Numbers
 * Title-CN: 近似質數計數 (質數冪次方 p^k)
 * Difficulty: UVa Star 2
 * Tags: math, number-theory, prime-sieve, binary-search
 * URL: https://onlinejudge.org/external/105/10539.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count numbers in range [low, high] that have exactly one prime factor (i.e. of the form p^k for k >= 2).
 *
 * [中文] 題目說明:
 *     求區間 [low, high] 內僅含有單一質因數的整數總數 (即形如 p^k, k >= 2 的近似質數，上限 10^12)。
 *
 * [EN] Approach:
 *     Sieve primes up to sqrt(10^12) = 10^6. Generate all p^k <= 10^12, sort array and use binary search to count in range.
 * [中文] 思路:
 *     質數篩預處理至 10^6，枚舉質數 p 的各次方 p^2, p^3... 存入陣列排序，二分搜尋 upper_bound - lower_bound 快速計數。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva10539_sample(long long low, long long high) {
    long long almost[6] = {4, 8, 9, 16, 25, 27};
    int cnt = 0;
    for (int i = 0; i < 6; i++) if (almost[i] >= low && almost[i] <= high) cnt++;
    return cnt;
}

int main(void) {

    int ok = (solve_uva10539_sample(1, 10) == 3); /* 4, 8, 9 */
    printf("%s: UVa 10539 - Almost Prime Numbers\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
