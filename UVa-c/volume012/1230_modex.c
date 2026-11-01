/*
 * ==========================================================================
 * UVa 1230 - MODEX
 * Title-CN: 大數快速冪模運算
 * Difficulty: UVa Star 1
 * Tags: math, number-theory
 * URL: https://onlinejudge.org/external/12/1230.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Compute (x^y) mod n efficiently for large integers.
 *
 * [中文] 題目說明:
 *     高效計算大整數的次方取模運算 (x^y) mod n。
 *
 * [EN] Approach:
 *     Binary exponentiation (repeated squaring) in O(log y) time.
 * [中文] 思路:
 *     使用平方求冪二分快速冪演算法，時間複雜度為 O(log y)。
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

long long solve_uva1230(long long x, long long y, long long n) {
    long long res = 1;
    x %= n;
    while (y > 0) {
        if (y & 1) res = (res * x) % n;
        x = (x * x) % n;
        y >>= 1;
    }
    return res;
}

int main(void) {

    int ok = (solve_uva1230(2, 10, 1000) == 24 && solve_uva1230(3, 18132, 17) == 13);
    printf("%s: UVa 1230 - MODEX\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
