/*
 * ==========================================================================
 * UVa 1583 - Digit Generator
 * Title-CN: 最小生成元數值逆向查找
 * Difficulty: UVa Star 1
 * Tags: math
 * URL: https://onlinejudge.org/external/15/1583.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the smallest generator M such that M + sum_of_digits(M) = N, or 0 if no generator exists.
 *
 * [中文] 題目說明:
 *     若整數 M 加上其各數位之和等於 N，則稱 M 為 N 的生成元。求 N 的最小生成元，若不存在則回傳 0。
 *
 * [EN] Approach:
 *     Since digit sum of M <= 9 * log10(N), test M from max(1, N - 9 * num_digits) up to N.
 * [中文] 思路:
 *     數位和上限為 9 * 位數，只需從 max(1, N - 9 * 位數) 向上枚舉至 N，驗證 M + digit_sum(M) 是否等於 N。
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

int digit_sum(int m) {
    int s = m;
    while (m > 0) { s += m % 10; m /= 10; }
    return s;
}

int solve_uva1583(int n) {
    int start = n - 60;
    if (start < 1) start = 1;
    for (int m = start; m < n; m++) {
        if (digit_sum(m) == n) return m;
    }
    return 0;
}

int main(void) {

    int ok = (solve_uva1583(216) == 198 && solve_uva1583(121) == 0);
    printf("%s: UVa 1583 - Digit Generator\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
