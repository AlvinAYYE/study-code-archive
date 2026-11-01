/*
 * ==========================================================================
 * UVa 10139 - Factovisors
 * Title-CN: 階乘被除數整除性勒讓德檢驗
 * Difficulty: UVa Star 2
 * Tags: math, number-theory
 * URL: https://onlinejudge.org/external/101/10139.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine whether integer M divides N! (N factorial).
 *
 * [中文] 題目說明:
 *     判定整數 M 是否能整除 N! (N 的階乘)。
 *
 * [EN] Approach:
 *     Prime factorize M. For each prime power p^k in M, verify that Legendre's formula sum_{i=1} floor(N / p^i) >= k.
 * [中文] 思路:
 *     將 M 進行質因數分解，利用勒讓德公式計算 N! 中包含該質因數 p 的總冪次，若對所有質因數冪次皆 >= M 中之冪次則整除。
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

long long legendre_count(long long n, long long p) {
    long long cnt = 0;
    while (n > 0) {
        cnt += n / p;
        n /= p;
    }
    return cnt;
}

int solve_uva10139(long long n, long long m) {
    if (m == 0) return 0;
    if (m <= n) return 1;
    long long temp = m;
    for (long long d = 2; d * d <= temp; d++) {
        if (temp % d == 0) {
            long long k = 0;
            while (temp % d == 0) { k++; temp /= d; }
            if (legendre_count(n, d) < k) return 0;
        }
    }
    if (temp > 1) {
        if (legendre_count(n, temp) < 1) return 0;
    }
    return 1;
}

int main(void) {

    int ok = solve_uva10139(6, 9) && !solve_uva10139(6, 27); // 6! = 720 divisible by 9, not 27
    printf("%s: UVa 10139 - Factovisors\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
