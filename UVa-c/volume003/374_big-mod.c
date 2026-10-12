/*
 * ==========================================================================
 * UVa 374 - Big Mod
 * Title-CN: 大數快速冪模運算
 * Difficulty: UVa Star 1
 * Tags: math, number-theory, modular-exponentiation
 * ==========================================================================
 * [EN] Problem: Compute B^P mod M where B, P, M up to 2^31 - 1.
 * [中文] 題目說明: 計算 B^P mod M 的值。
 * [EN] Approach: Binary exponentiation in O(log P).
 * [中文] 思路: 二進位快速冪取模，時間複雜度 O(log P)。
 * ==========================================================================
 */
#include <stdio.h>

long long solve_uva374(long long b, long long p, long long m) {
    long long res = 1;
    b %= m;
    while (p > 0) {
        if (p % 2 == 1) res = (res * b) % m;
        b = (b * b) % m;
        p /= 2;
    }
    return res;
}

int main(void) {
    int ok = (solve_uva374(3, 18132, 17) == 13);
    printf("%s: UVa 374 - Big Mod\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
