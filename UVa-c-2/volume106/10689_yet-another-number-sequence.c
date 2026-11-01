/*
 * ==========================================================================
 * UVa 10689 - Yet another Number Sequence
 * Title-CN: 斐波那契數列 Pisano 週期與矩陣快速冪
 * Difficulty: Medium
 * Tags: Math, Matrix Exponentiation, Pisano Period
 * URL: https://onlinejudge.org/external/106/10689.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the last m digits of the n-th generalized Fibonacci number f(n) = f(n-1) + f(n-2) with f(0)=a, f(1)=b.
 *
 * [中文] 題目說明:
 *     求廣義費氏數列 f(n) = f(n-1) + f(n-2)（初值 a, b）的後 m 位數字（m = 1..4）。
 *
 * [EN] Approach:
 *     Pisano period for modulo 10^m: period for 10 is 60, 100 is 300, 1000 is 1500, 10000 is 15000. Take n mod period, then iterate.
 * [中文] 思路:
 *     模 10^m 的皮薩諾週期 (Pisano Period)：模 10 週期 60、模 100 週期 300、模 1000 週期 1500、模 10000 週期 15000。將 n 取模週期後線性遞推即可。
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

int last_m_digits_fib(int a, int b, long long n, int m) {
    int mod = 1;
    for (int i = 0; i < m; i++) mod *= 10;
    int period[] = {0, 60, 300, 1500, 15000};
    n %= period[m];
    if (n == 0) return a % mod;
    if (n == 1) return b % mod;
    int f0 = a % mod, f1 = b % mod, f2;
    for (int i = 2; i <= n; i++) {
        f2 = (f0 + f1) % mod;
        f0 = f1;
        f1 = f2;
    }
    return f1;
}

int main(void) {

    int res = last_m_digits_fib(0, 1, 10, 2); // 10th fib = 55
    int ok = (res == 55);
    printf("%s: UVa 10689 - Yet another Number Sequence\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
