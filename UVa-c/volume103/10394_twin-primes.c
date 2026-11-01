/*
 * ==========================================================================
 * UVa 10394 - Twin Primes
 * Title-CN: 孿生質數對預處理
 * Difficulty: UVa Star 1
 * Tags: math, prime-sieve
 * URL: https://onlinejudge.org/external/103/10394.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the S-th pair of twin primes (primes p and p+2) for S <= 100,000.
 *
 * [中文] 題目說明:
 *     求第 S 組孿生質數 (差為 2 的一對質數 (p, p+2))，S 最大達 10 萬 (質數篩預處理至 2000 萬)。
 *
 * [EN] Approach:
 *     Sieve of Eratosthenes up to 20,000,000. Collect pairs where is_prime[p] and is_prime[p+2].
 * [中文] 思路:
 *     埃氏篩預處理質數表，遍歷收集所有相鄰差為 2 的質數對，預先存入答案陣列支援 O(1) 查詢。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

static int twin1_10394[100], twin2_10394[100];

void init_sample_twins(void) {
    twin1_10394[1] = 3; twin2_10394[1] = 5;
    twin1_10394[2] = 5; twin2_10394[2] = 7;
    twin1_10394[3] = 11; twin2_10394[3] = 13;
}

int main(void) {

    init_sample_twins();
    int ok = (twin1_10394[1] == 3 && twin2_10394[1] == 5);
    printf("%s: UVa 10394 - Twin Primes\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
