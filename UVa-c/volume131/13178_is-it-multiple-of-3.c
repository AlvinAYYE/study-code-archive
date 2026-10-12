/*
 * ==========================================================================
 * UVa 13178 - Is it multiple of 3?
 * Title-CN: 連續整數拼接數是否為 3 的倍數
 * Difficulty: UVa Star 1
 * Tags: math, number-theory
 * ==========================================================================
 * [EN] Problem: Concatenation 1234...N is divisible by 3 iff sum_{i=1}^N i is divisible by 3 (N % 3 != 1).
 * [中文] 題目說明: 將 1 到 N 依序拼接成大數，判斷是否為 3 的倍數。
 * [EN] Approach: Sum 1..N = N*(N+1)/2. Divisible by 3 iff N % 3 == 0 or N % 3 == 2.
 * [中文] 思路: 各位數之和即 1+2+...+N，能被 3 整除等價於 N % 3 != 1。
 * ==========================================================================
 */
#include <stdio.h>

int is_multiple_of_3(long long n) {
    return (n % 3 != 1);
}

int main(void) {
    int ok = is_multiple_of_3(2) && is_multiple_of_3(3) && !is_multiple_of_3(1);
    printf("%s: UVa 13178 - Is it multiple of 3\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
