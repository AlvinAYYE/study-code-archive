/*
 * ==========================================================================
 * UVa 10994 - Simple Addition
 * Title-CN: 簡單加法數列 (末位非零數遞歸求和)
 * Difficulty: Easy
 * Tags: Math, Recursion
 * URL: https://onlinejudge.org/external/109/10994.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Function F(n) = n % 10 if n % 10 > 0, else F(n / 10). Compute sum of F(i) for i from p to q.
 *
 * [中文] 題目描述:
 *     函數 F(n)：若末位大於 0 則為末位數字，否則為 F(n/10)。求 F(i) 在區間 [p, q] 上的總和。
 *
 * [EN] Approach:
 *     Evaluate S(n) = sum_{i=1}^n F(i). In each block of 10 numbers, sum of non-zero last digits is 45. Multiples of 10 recurse as S(n / 10). Answer = S(q) - S(p - 1).
 *
 * [中文] 解題思維:
 *     求前綴和 S(n) = sum_{i=1}^n F(i)：每 10 個數產生一個 1..9 和 45，結尾為 0 的數除以 10 遞迴累加 S(n/10)。
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

long long sum_f(long long n) {
    if (n <= 0) return 0;
    long long total = 0;
    while (n > 0) {
        long long q = n / 10, r = n % 10;
        total += q * 45;
        total += r * (r + 1) / 2;
        n /= 10;
    }
    return total;
}
long long range_sum_f(long long p, long long q) {
    return sum_f(q) - sum_f(p - 1);
}

int main(void) {

    long long s = range_sum_f(1, 10); // 1..9 (45) + F(10)=1 -> 46
    int ok = (s == 46);
    printf("%s: UVa 10994 - Simple Addition\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
