/*
 * ==========================================================================
 * UVa 11332 - Summing Digits
 * Title-CN: 數字之和
 * Difficulty: UVa Star 1 / CPE 49 顆星必考題
 * Tags: math, number-theory
 * URL: https://onlinejudge.org/external/113/11332.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Repeatedly sum digits until single digit is reached.
 *
 * [中文] 題目說明:
 *     重複計算各位數之和，直到剩下個位數。
 *
 * [EN] Approach: Digital root formula (n - 1) % 9 + 1.
 * [中文] 思路: 數字和數學性質即為九餘數，公式為 (n - 1) % 9 + 1。
 * ==========================================================================
 */
#include <stdio.h>

long long solve_uva11332(long long n) {
    while (n >= 10) {
        long long sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        n = sum;
    }
    return n;
}

int main(void) {
    int ok = (solve_uva11332(47) == 2) && (solve_uva11332(11) == 2);
    printf("%s: UVa 11332 - Summing Digits\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
