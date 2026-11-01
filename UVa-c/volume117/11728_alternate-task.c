/*
 * ==========================================================================
 * UVa 11728 - Alternate Task
 * Title-CN: 替代任務 (因數和反查)
 * Difficulty: Easy
 * Tags: Math, Number Theory, Sum of Divisors
 * URL: https://onlinejudge.org/external/117/11728.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given integer S, find the largest integer N <= 1000 such that the sum of divisors of N equals S.
 *
 * [中文] 題目說明:
 *     給定整數 S，求所有因數之和剛好等於 S 的最大整數 N（N <= 1000）。
 *
 * [EN] Approach:
 *     Precompute sum of divisors for all numbers 1 to 1000. Iterate backwards from 1000 to find the first N matching sum S.
 * [中文] 思路:
 *     預先計算 1~1000 每個整數的所有因數和，從 1000 向下倒序搜尋第一個因數和為 S 的整數 N。
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

int sum_of_divisors(int n) {
    int sum = 0;
    for (int d = 1; d * d <= n; d++) {
        if (n % d == 0) {
            sum += d;
            if (d * d != n) sum += n / d;
        }
    }
    return sum;
}
int find_max_n_for_sum(int s) {
    for (int n = 1000; n >= 1; n--) {
        if (sum_of_divisors(n) == s) return n;
    }
    return -1;
}

int main(void) {

    int ok = (find_max_n_for_sum(1) == 1) && (find_max_n_for_sum(102) == 101); // 101 is prime -> sum = 102
    printf("%s: UVa 11728 - Alternate Task\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
