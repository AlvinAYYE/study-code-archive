/*
 * ==========================================================================
 * UVa 10212 - The Last Non-zero Digit.
 * Title-CN: 排列數最後一個非零數字
 * Difficulty: Easy
 * Tags: Math, Number Theory, Modulo
 * URL: https://onlinejudge.org/external/102/10212.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the last non-zero digit of the permutation P(N, M) = N! / (N - M)!.
 *
 * [中文] 題目說明:
 *     求排列數 P(N, M) = N * (N-1) * ... * (N-M+1) 的最後一個非零數字。
 *
 * [EN] Approach:
 *     Multiply factors from N down to N-M+1. Cancel factors of 2 and 5 (or maintain product mod 10^9 to avoid spurious zeros).
 * [中文] 思路:
 *     連乘 N 到 N-M+1 各項，過程中不斷除去因子 10，保持較高位數模算以避免溢位與末尾零干擾。
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

int last_nonzero_perm(long long n, long long m) {
    long long ans = 1;
    for (long long i = n; i > n - m; i--) {
        ans *= i;
        while (ans % 10 == 0) ans /= 10;
        ans %= 1000000000LL;
    }
    return ans % 10;
}

int main(void) {

    int ok = (last_nonzero_perm(10, 10) == 8); // 10! = 3628800 -> 8
    printf("%s: UVa 10212 - The Last Non-zero Digit.\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
