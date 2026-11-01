/*
 * ==========================================================================
 * UVa 1210 - Sum of Consecutive Prime Numbers
 * Title-CN: 連續質數之和
 * Difficulty: Easy
 * Tags: Math, Number Theory, Sliding Window
 * URL: https://onlinejudge.org/external/12/1210.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count how many representations of integer N exist as the sum of one or more consecutive prime numbers.
 *
 * [中文] 題目說明:
 *     計算整數 N 可表示為連續一個或多個質數之和的方案數。
 *
 * [EN] Approach:
 *     Precompute primes up to 10000. Use sliding window or prefix sums to count ranges of primes whose sum equals N.
 * [中文] 思路:
 *     預先篩出 10000 內質數，使用滑動窗口或雙指針遍歷連續質數區間，統計和為 N 的區間數量。
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

int count_consecutive_prime_sums(int n) {
    int primes[1300], p_cnt = 0;
    bool is_p[10005];
    memset(is_p, true, sizeof(is_p));
    for (int p = 2; p <= 10000; p++) {
        if (is_p[p]) {
            primes[p_cnt++] = p;
            for (int i = p * 2; i <= 10000; i += p) is_p[i] = false;
        }
    }
    int ans = 0;
    for (int i = 0; i < p_cnt && primes[i] <= n; i++) {
        int sum = 0;
        for (int j = i; j < p_cnt; j++) {
            sum += primes[j];
            if (sum == n) { ans++; break; }
            if (sum > n) break;
        }
    }
    return ans;
}

int main(void) {

    int ok = (count_consecutive_prime_sums(53) == 2); // 53, 5+7+11+13+17
    printf("%s: UVa 1210 - Sum of Consecutive Prime Numbers\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
