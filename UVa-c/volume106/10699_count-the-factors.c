/*
 * ==========================================================================
 * UVa 10699 - Count the factors
 * Title-CN: 相異質因數個數統計
 * Difficulty: UVa Star 1
 * Tags: math, number-theory, prime-factorization
 * URL: https://onlinejudge.org/external/106/10699.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count the number of different prime factors of integer n.
 *
 * [中文] 題目說明:
 *     計算整數 n 含有多少個相異的質因數 (不同於總因數個數，只算相異質數)。
 *
 * [EN] Approach:
 *     Trial division by primes up to sqrt(n). If factor divides n, increment count and divide all occurrences out.
 * [中文] 思路:
 *     試除法質因數分解：遇整除數則相異質因數個數 +1，並將該因數完全除盡，最後若剩餘數大於 1 則再計數 +1。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva10699(int n) {
    int cnt = 0;
    for (int d = 2; d * d <= n; d++) {
        if (n % d == 0) {
            cnt++;
            while (n % d == 0) n /= d;
        }
    }
    if (n > 1) cnt++;
    return cnt;
}

int main(void) {

    int ok = (solve_uva10699(10) == 2) && (solve_uva10699(12) == 2);
    printf("%s: UVa 10699 - Count the factors\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
