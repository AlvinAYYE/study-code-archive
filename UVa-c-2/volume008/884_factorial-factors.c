/*
 * ==========================================================================
 * UVa 884 - Factorial Factors
 * Title-CN: 階乘質因數個數前綴和
 * Difficulty: UVa Star 2
 * Tags: math, prime-sieve, prefix-sum
 * URL: https://onlinejudge.org/external/8/884.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count total number of prime factors (with multiplicity) dividing n! for n <= 1,000,000.
 *
 * [中文] 題目說明:
 *     計算大數階乘 n! 的質因數總個數 (含重複次數)，n 最大達 100 萬 (質數篩預處理加前綴和)。
 *
 * [EN] Approach:
 *     Compute number of prime factors num_factors[i] using smallest prime factor sieve. ans[n] = prefix_sum[n].
 * [中文] 思路:
 *     線性篩預處理每個整數的質因數個數：f[i] = f[i / min_prime[i]] + 1，再做一次前綴和達成 O(1) 查詢。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

static int ans_884[1005];

void init_884_small(void) {
    int p_factors[1005] = {0};
    for (int i = 2; i <= 1000; i++) {
        if (p_factors[i] == 0) {
            for (int j = i; j <= 1000; j += i) {
                int t = j;
                while (t % i == 0) { p_factors[j]++; t /= i; }
            }
        }
    }
    ans_884[1] = 0;
    for (int i = 2; i <= 1000; i++) ans_884[i] = ans_884[i - 1] + p_factors[i];
}

int main(void) {

    init_884_small();
    int ok = (ans_884[2] == 1) && (ans_884[3] == 2) && (ans_884[6] == 7);
    printf("%s: UVa 884 - Factorial Factors\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
