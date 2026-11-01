/*
 * ==========================================================================
 * UVa 10042 - Smith Numbers
 * Title-CN: 史密斯數
 * Difficulty: UVa Star 1
 * Tags: math, number-theory, prime
 * URL: https://onlinejudge.org/external/100/10042.pdf
 * ==========================================================================
 * [EN] Problem:
 *     A Smith number is a composite number whose sum of digits equals the sum
 *     of digits of its prime factors. Find the smallest Smith number > n.
 *
 * [中文] 題目說明:
 *     若一個合數的數字和，等於其質因數分解後所有質因數的數字和，則稱為史密斯數。
 *     求大於 n 的最小史密斯數。
 *
 * [EN] Approach:
 *     Iterate numbers > n. Check if composite and sum_digits(num) == sum_prime_factor_digits(num).
 * [中文] 思路:
 *     寫 sum_digits() 計算位數和；質因數分解並累加各質因數之位數和，比對兩者是否相等。
 * ==========================================================================
 */
#include <stdio.h>

static int sum_digits(long long n) {
    int s = 0;
    while (n) { s += (int)(n % 10); n /= 10; }
    return s;
}

int is_smith(long long n) {
    int orig_sum = sum_digits(n);
    int factor_sum = 0;
    long long temp = n;
    int is_composite = 0;

    for (long long d = 2; d * d <= temp; d++) {
        while (temp % d == 0) {
            factor_sum += sum_digits(d);
            temp /= d;
            is_composite = 1;
        }
    }
    if (temp > 1) {
        if (!is_composite) return 0; /* n is prime, not composite */
        factor_sum += sum_digits(temp);
    }
    return orig_sum == factor_sum;
}

long long solve_uva10042(long long n) {
    long long cand = n + 1;
    while (!is_smith(cand)) {
        cand++;
    }
    return cand;
}

int main(void) {
    long long res = solve_uva10042(4937774LL);
    int ok = (res == 4937775LL);
    printf("%s: UVa 10042 - Smith Numbers\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
