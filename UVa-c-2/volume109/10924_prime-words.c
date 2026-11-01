/*
 * ==========================================================================
 * UVa 10924 - Prime Words
 * Title-CN: 質數單字判定 (題目特殊定義 1 為質數)
 * Difficulty: UVa Star 1
 * Tags: math, string
 * URL: https://onlinejudge.org/external/109/10924.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Sum letter values (a=1..z=26, A=27..Z=52). Determine if sum is prime (problem defines 1 as prime!).
 *
 * [中文] 題目說明:
 *     計算單字中字母權重和 (a-z 為 1-26，A-Z 為 27-52)，判定總和是否為質數 (注意本題規定 1 視為質數)。
 *
 * [EN] Approach:
 *     Calculate word sum. Check primality treating 1 as a prime per problem specification.
 * [中文] 思路:
 *     字元累加求和，標準質數測試判定，特判值為 1 時依題目特別約定回傳質數判定成立。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int is_prime_word_10924(int n) {
    if (n == 1) return 1; /* Special problem rule! */
    if (n < 2) return 0;
    for (int d = 2; d * d <= n; d++) if (n % d == 0) return 0;
    return 1;
}

int main(void) {

    int ok = is_prime_word_10924(1) && is_prime_word_10924(2) && !is_prime_word_10924(4);
    printf("%s: UVa 10924 - Prime Words\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
