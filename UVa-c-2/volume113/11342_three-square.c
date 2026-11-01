/*
 * ==========================================================================
 * UVa 11342 - Three-square
 * Title-CN: 三平方和定理
 * Difficulty: Easy
 * Tags: Math, Number Theory, Brute Force
 * URL: https://onlinejudge.org/external/113/11342.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find three non-negative integers a <= b <= c such that a^2 + b^2 + c^2 = K.
 *
 * [中文] 題目說明:
 *     求三個非負整數 a <= b <= c 使得 a^2 + b^2 + c^2 = K（三平方和）。
 *
 * [EN] Approach:
 *     Precompute square lookup. Iterate a from 0 up to sqrt(K/3), b from a up to sqrt((K - a^2)/2), and check if K - a^2 - b^2 is a square.
 * [中文] 思路:
 *     雙重迴圈枚舉 a 與 b，驗證餘數 c^2 = K - a^2 - b^2 是否為完全平方數且 c >= b。
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

bool three_squares(int k, int *a, int *b, int *c) {
    for (int i = 0; i * i * 3 <= k; i++) {
        for (int j = i; i * i + j * j * 2 <= k; j++) {
            int rem = k - i * i - j * j;
            int r = (int)(sqrt(rem) + 0.5);
            if (r * r == rem && r >= j) {
                *a = i; *b = j; *c = r;
                return true;
            }
        }
    }
    return false;
}

int main(void) {

    int a, b, c;
    bool ok = three_squares(29, &a, &b, &c); // 0^2 + 2^2 + 5^2 = 29
    ok = ok && (a*a + b*b + c*c == 29);
    printf("%s: UVa 11342 - Three-square\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
