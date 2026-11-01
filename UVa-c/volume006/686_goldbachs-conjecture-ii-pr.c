/*
 * ==========================================================================
 * UVa 686 - Goldbach's Conjecture (II)
 * Title-CN: 哥德巴赫猜想 (II) 質數對總數統計
 * Difficulty: UVa Star 1
 * Tags: math, prime-sieve, number-theory
 * URL: https://onlinejudge.org/external/6/686.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count the number of distinct prime pairs (p1, p2) with p1 <= p2 such that p1 + p2 = 2n for even 2n < 2^15.
 *
 * [中文] 題目說明:
 *     計算偶數 2n 表達成兩個質數之和 p1 + p2 = 2n (p1 <= p2) 的相異質數對數量。
 *
 * [EN] Approach:
 *     Sieve primes up to 2^15 = 32768. Loop p1 from 2 up to n, count pairs where both p1 and (2n - p1) are prime.
 * [中文] 思路:
 *     質數篩預處理至 32768，由 2 枚舉質數 p1 至 n，若 2n - p1 亦為質數則計數 +1。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva686(int n) {
    static char is_p[33000];
    static int ready = 0;
    if (!ready) {
        for (int i = 2; i < 33000; i++) is_p[i] = 1;
        for (int i = 2; i * i < 33000; i++) {
            if (is_p[i]) {
                for (int j = i * i; j < 33000; j += i) is_p[j] = 0;
            }
        }
        ready = 1;
    }
    int cnt = 0;
    for (int p1 = 2; p1 <= n / 2; p1++) {
        if (is_p[p1] && is_p[n - p1]) cnt++;
    }
    return cnt;
}

int main(void) {

    int ok = (solve_uva686(10) == 2); /* 3+7, 5+5 */
    printf("%s: UVa 686 - Goldbach's Conjecture (II)\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
