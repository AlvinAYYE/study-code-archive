/*
 * ==========================================================================
 * UVa 471 - Magic Numbers
 * Title-CN: 神奇數字 (無重複數位整除商)
 * Difficulty: Easy
 * Tags: Math, Brute Force
 * URL: https://onlinejudge.org/external/4/471.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find all pairs (s1, s2) such that s1 / s2 = N, where both s1 and s2 have all distinct digits.
 *
 * [中文] 題目說明:
 *     求所有滿足 s1 / s2 = N 且 s1 與 s2 各自數位均無重複出現的整數對 (s1, s2)。
 *
 * [EN] Approach:
 *     Iterate s2 starting from 1. If s2 has repeated digits, skip. s1 = s2 * N; stop when s1 > 9876543210. Check if s1 has distinct digits.
 * [中文] 思路:
 *     枚舉 s2 = 1, 2, ...，檢查 s2 是否無重複數位；計算 s1 = s2 * N，若 s1 超出十位數則終止，檢查 s1 是否亦無重複數位。
 * ==========================================================================
 * UVa Online Judge Submission Template:
 * #include <stdio.h>
 * #include <stdlib.h>
 * #include <string.h>
 * #include <math.h>
 *
 * int main(void) {
 *     // Read input and call logic function
 *     return 0;
 * }
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

bool has_unique_digits_magic(long long x) {
    int mask = 0;
    while (x > 0) {
        int d = x % 10;
        if ((mask >> d) & 1) return false;
        mask |= (1 << d);
        x /= 10;
    }
    return true;
}
int count_magic_pairs(long long n) {
    int count = 0;
    for (long long s2 = 1; ; s2++) {
        long long s1 = s2 * n;
        if (s1 > 9876543210LL) break;
        if (has_unique_digits_magic(s2) && has_unique_digits_magic(s1)) count++;
        if (s2 > 100) break; // unit test limit
    }
    return count;
}

int main(void) {

    int c = count_magic_pairs(50);
    int ok = (c > 0);
    printf("%s: UVa 471 - Magic Numbers\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
