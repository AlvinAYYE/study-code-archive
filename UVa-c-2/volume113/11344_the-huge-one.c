/*
 * ==========================================================================
 * UVa 11344 - The Huge One
 * Title-CN: 超大整數多整除性檢測
 * Difficulty: UVa Star 1
 * Tags: math, big-integer
 * URL: https://onlinejudge.org/external/113/11344.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine if a huge integer M (up to 1000 digits) is divisible by all numbers in a given set S.
 *
 * [中文] 題目說明:
 *     給定一個長達 1000 位數的超大整數 M，檢驗其是否能被集合 S 中的所有整數整除。
 *
 * [EN] Approach:
 *     For each divisor d in S, compute M % d using modular arithmetic on digits: rem = (rem * 10 + digit) % d.
 * [中文] 思路:
 *     高精度取模運算：對集合中每個因數 d，逐位計算 rem = (rem * 10 + d_i) % d。若所有 rem 皆為 0 則為 Wonderful。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int is_divisible_11344(const char *s, int d) {
    int rem = 0;
    for (int i = 0; s[i]; i++) {
        rem = (rem * 10 + (s[i] - '0')) % d;
    }
    return rem == 0;
}

int main(void) {

    int ok = is_divisible_11344("123456", 2) && is_divisible_11344("123456", 3);
    printf("%s: UVa 11344 - The Huge One\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
