/*
 * ==========================================================================
 * UVa 10392 - Factoring Large Numbers
 * Title-CN: 大數質因數分解
 * Difficulty: Easy
 * Tags: Math, Number Theory, Prime Factorization
 * URL: https://onlinejudge.org/external/103/10392.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Factorize large 64-bit integers into prime factors in ascending order.
 *
 * [中文] 題目概述:
 *     將不超過 10^14 的大整數分解為質因數並依升序輸出。
 *
 * [EN] Approach:
 *     Trial division by 2 and odd numbers up to sqrt(N). Print each factor.
 * [中文] 解題思路:
 *     試除法：先除以 2，再用奇數試除至 sqrt(N)，印出所有質因數。
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

int factorize_64(long long n, long long *factors) {
    int count = 0;
    while (n % 2 == 0) { factors[count++] = 2; n /= 2; }
    for (long long d = 3; d * d <= n; d += 2) {
        while (n % d == 0) { factors[count++] = d; n /= d; }
    }
    if (n > 1) factors[count++] = n;
    return count;
}

int main(void) {

    long long f[50];
    int cnt = factorize_64(60, f);
    int ok = (cnt == 4 && f[0] == 2 && f[1] == 2 && f[2] == 3 && f[3] == 5);
    printf("%s: UVa 10392 - Factoring Large Numbers\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
