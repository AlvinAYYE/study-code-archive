/*
 * ==========================================================================
 * UVa 169 - A New Factoring Method
 * Title-CN: 整數因數分解篩法
 * Difficulty: UVa Star 2
 * Tags: math, number-theory
 * URL: https://onlinejudge.org/external/1/169.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Factorize integers by testing small prime candidates and extracting prime factors efficiently.
 *
 * [中文] 題目說明:
 *     利用試除法與質數表高效提取整數之質因數分解。
 *
 * [EN] Approach:
 *     Trial division with precomputed primes up to sqrt(N). Factor out each prime divisor completely.
 * [中文] 思路:
 *     預先計算 sqrt(N) 內的質數，循序試除並記錄質因數與對應冪次，剩餘大於 1 之數即為最後質因數。
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

int count_prime_factors(int n) {
    int cnt = 0;
    for (int d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            cnt++;
            n /= d;
        }
    }
    if (n > 1) cnt++;
    return cnt;
}

int main(void) {

    int ok = (count_prime_factors(12) == 3 && count_prime_factors(13) == 1);
    printf("%s: UVa 169 - A New Factoring Method\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
