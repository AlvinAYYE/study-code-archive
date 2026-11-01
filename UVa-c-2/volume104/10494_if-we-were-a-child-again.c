/*
 * ==========================================================================
 * UVa 10494 - If We Were a Child Again
 * Title-CN: 大數除以單精度整數之商與餘數
 * Difficulty: UVa Star 1
 * Tags: bigint, math
 * URL: https://onlinejudge.org/external/104/10494.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Perform integer division or modulo between a large integer (up to 1000 digits) and a regular integer.
 *
 * [中文] 題目說明:
 *     計算大整數 (長達 1000 位) 除以一般整數的除法商數或餘數運算。
 *
 * [EN] Approach:
 *     Simulate elementary school long division: maintain remainder rem = rem * 10 + digit, append rem / div to quotient, rem = rem % div.
 * [中文] 思路:
 *     模擬長除法：維護當前餘數 rem = rem * 10 + d，計算每一步商數 rem / div 並記錄，餘數更新為 rem % div。
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

long long solve_uva10494_mod(const char *num, long long div) {
    long long rem = 0;
    for (int i = 0; num[i]; i++) {
        rem = (rem * 10 + (num[i] - '0')) % div;
    }
    return rem;
}

int main(void) {

    long long r = solve_uva10494_mod("110", 10);
    int ok = (r == 0 && solve_uva10494_mod("115", 10) == 5);
    printf("%s: UVa 10494 - If We Were a Child Again\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
