/*
 * ==========================================================================
 * UVa 11332 - Summing Digits
 * Title-CN: 數根計算 (反覆數位求和)
 * Difficulty: UVa Star 1
 * Tags: math
 * URL: https://onlinejudge.org/external/113/11332.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Repeatedly sum digits of integer n until a single-digit integer is produced (digital root).
 *
 * [中文] 題目說明:
 *     反覆將整數的各位十進位數字相加，直到最後得到個位數為止 (數根，等價於九餘數同餘定理)。
 *
 * [EN] Approach:
 *     Digital root formula: 1 + (n - 1) % 9 for n > 0.
 * [中文] 思路:
 *     數根公式：若 n > 0 且可被 9 整除則為 9，其餘為 n % 9 (即 1 + (n - 1) % 9)。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long long solve_uva11332(long long n) {
    if (n == 0) return 0;
    return 1 + (n - 1) % 9;
}

int main(void) {

    int ok = (solve_uva11332(47) == 2) && (solve_uva11332(11) == 2);
    printf("%s: UVa 11332 - Summing Digits\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
