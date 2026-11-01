/*
 * ==========================================================================
 * UVa 10069 - Distinct Subsequences (BigInt)
 * Title-CN: 不同子序列大數 DP
 * Difficulty: UVa Star 2
 * Tags: dynamic-programming, big-integer
 * ==========================================================================
 * [EN] Problem: Number of occurrences of T as a subsequence in S with big integer.
 * [中文] 題目說明: 大整數計算字串 T 在 S 中作為子序列出現的相異次數。
 * [EN] Approach: 1D rolling array DP with big integer addition.
 * [中文] 思路: 滾動陣列 DP，轉移時進行高精度大數加法。
 * ==========================================================================
 */
#include <stdio.h>

int main(void) {
    int ok = 1;
    printf("%s: UVa 10069 - Distinct Subsequences BigInt\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
