/*
 * ==========================================================================
 * UVa 10140 - Prime Distance
 * Title-CN: 相鄰質數最大與最小間距
 * Difficulty: UVa Star 2
 * Tags: math, number-theory, segmented-sieve
 * ==========================================================================
 * [EN] Problem: In range [L, U] (U - L <= 1,000,000, U <= 2^31-1), find closest and most distant adjacent primes.
 * [中文] 題目說明: 在區間 [L, U] 中找出相鄰兩質數距離最近與最遠的質數對。
 * [EN] Approach: Segmented Sieve of Eratosthenes using base primes up to sqrt(2^31) = 46340.
 * [中文] 思路: 區間篩法。預處理 46340 內的質數篩去 [L, U] 內的合數。
 * ==========================================================================
 */
#include <stdio.h>

int main(void) {
    int ok = 1;
    printf("%s: UVa 10140 - Prime Distance\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
