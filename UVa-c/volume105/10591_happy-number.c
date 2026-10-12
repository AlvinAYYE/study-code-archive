/*
 * ==========================================================================
 * UVa 10591 - Happy Number
 * Title-CN: 快樂數檢驗
 * Difficulty: UVa Star 1
 * Tags: math, simulation
 * ==========================================================================
 * [EN] Problem: Determine if number reaches 1 by summing squares of digits.
 * [中文] 題目說明: 各位數平方和不斷迭代，是否能收斂至 1。
 * [EN] Approach: If hits 4 or 1, terminate.
 * [中文] 思路: 任何非快樂數最終皆會進入含 4 的循環圈。
 * ==========================================================================
 */
#include <stdio.h>

static long long sum_sq(long long n) {
    long long s = 0;
    while (n) {
        long long d = n % 10;
        s += d * d;
        n /= 10;
    }
    return s;
}

int is_happy(long long n) {
    while (n != 1 && n != 4) {
        n = sum_sq(n);
    }
    return (n == 1);
}

int main(void) {
    int ok = is_happy(7) && is_happy(1) && !is_happy(4);
    printf("%s: UVa 10591 - Happy Number\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
