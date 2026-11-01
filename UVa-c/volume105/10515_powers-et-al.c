/*
 * ==========================================================================
 * UVa 10515 - Powers Et Al.
 * Title-CN: 大數冪次末位數 (週期性循環取模)
 * Difficulty: UVa Star 1
 * Tags: math, number-theory
 * URL: https://onlinejudge.org/external/105/10515.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the last decimal digit of m^n where m and n are huge integers.
 *
 * [中文] 題目說明:
 *     求超大整數冪次 m^n 的最後一位十進位數字 (m, n 最長達 101 位數)。
 *
 * [EN] Approach:
 *     Last digit depends only on (m % 10). Last digits of powers have periods of at most 4. Compute n % 4.
 * [中文] 思路:
 *     末位數僅取決於底數個位數 (m % 10)。任何個位數的冪次末位週期最多為 4，以指數末兩位計算 n % 4 查表即可。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva10515(int base_last, int exp_mod4) {
    if (exp_mod4 == 0) exp_mod4 = 4;
    int p = 1;
    for (int i = 0; i < exp_mod4; i++) p = (p * base_last) % 10;
    return p;
}

int main(void) {

    int ok = (solve_uva10515(2, 4) == 6) && (solve_uva10515(3, 1) == 3);
    printf("%s: UVa 10515 - Powers Et Al.\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
