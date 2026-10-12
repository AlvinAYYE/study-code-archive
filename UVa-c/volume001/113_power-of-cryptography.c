/*
 * ==========================================================================
 * UVa 113 - Power of Cryptography
 * Title-CN: 密碼學的威力
 * Difficulty: UVa Star 1
 * Tags: math
 * ==========================================================================
 * [EN] Problem: Given n and p = k^n, compute integer k (p up to 10^101).
 * [中文] 題目說明: 已知 n 與 p = k^n（p 高達 10^101），求整數 k。
 * [EN] Approach: IEEE 754 double floating point precision pow(p, 1.0 / n) + 0.5.
 * [中文] 思路: 利用標準 double 的 53 位尾數足以在對數尺度下精確還原 k = round(pow(p, 1.0 / n))。
 * ==========================================================================
 */
#include <stdio.h>
#include <math.h>

long long solve_uva113(double n, double p) {
    return (long long)round(pow(p, 1.0 / n));
}

int main(void) {
    int ok = (solve_uva113(2, 16) == 4) && (solve_uva113(7, 4357186184021382204544.0) == 1234);
    printf("%s: UVa 113 - Power of Cryptography\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
