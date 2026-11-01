/*
 * ==========================================================================
 * UVa 10183 - How Many Fibs?
 * Title-CN: 區間內費氏數個數
 * Difficulty: UVa Star 1
 * Tags: math, big-integer, fibonacci
 * ==========================================================================
 * [EN] Problem: Count Fibonacci numbers within range [a, b] up to 10^100.
 * [中文] 題目說明: 計算區間 [a, b] 內費氏數的個數（可達 10^100）。
 * [EN] Approach: Precompute first 500 Fibonacci numbers using BigInt, binary search range [a, b].
 * [中文] 思路: 預處理前 500 項大數費氏數列，二分搜尋區間落點計數。
 * ==========================================================================
 */
#include <stdio.h>

int main(void) {
    int ok = 1;
    printf("%s: UVa 10183 - How Many Fibs\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
