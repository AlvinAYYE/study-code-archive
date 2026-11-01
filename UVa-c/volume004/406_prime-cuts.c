/*
 * ==========================================================================
 * UVa 406 - Prime Cuts
 * Title-CN: 質數序列居中切割截取
 * Difficulty: UVa Star 1
 * Tags: math, prime-sieve
 * URL: https://onlinejudge.org/external/4/406.pdf
 * ==========================================================================
 * [EN] Problem:
 *     List all primes <= N (counting 1 as a prime). Output 2C (or 2C-1) primes centered in the list.
 *
 * [中文] 題目說明:
 *     列出小於等於 N 的質數 (本題將 1 視為質數)。若質數總數為偶數則從正中央截取 2C 個，為奇數則截取 2C-1 個。
 *
 * [EN] Approach:
 *     Sieve of Eratosthenes up to 1000. Find center indices and output slice.
 * [中文] 思路:
 *     埃拉托斯特尼質數篩法預處理 (含 1)。若總數小於截取長度則輸出全部，否則計算中央起訖索引印出區間。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva406_slice(int total_primes, int c, int *start, int *count) {
    int take = (total_primes % 2 == 0) ? (2 * c) : (2 * c - 1);
    if (take >= total_primes) {
        *start = 0;
        *count = total_primes;
    } else {
        *start = (total_primes - take) / 2;
        *count = take;
    }
    return *count;
}

int main(void) {

    int s, cnt;
    solve_uva406_slice(5, 1, &s, &cnt);
    int ok = (s == 2 && cnt == 1);
    printf("%s: UVa 406 - Prime Cuts\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
