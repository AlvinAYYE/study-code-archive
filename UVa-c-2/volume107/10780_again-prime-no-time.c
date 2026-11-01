/*
 * ==========================================================================
 * UVa 10780 - Again Prime? No Time.
 * Title-CN: 又是質數？沒時間了！ (勒讓德定理因數冪)
 * Difficulty: Easy
 * Tags: Math, Number Theory, Legendre Formula
 * URL: https://onlinejudge.org/external/107/10780.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the largest integer power p such that m^p divides n!.
 *
 * [中文] 題目說明:
 *     求使 m^p 整除 n! 的最大整數冪次 p（若 p=0 則輸出 Impossible）。
 *
 * [EN] Approach:
 *     Factorize m into prime powers q_i^k_i. For each prime factor, use Legendre's formula to count occurrences in n!: count = sum floor(n / q^j). Then p = min(count_i / k_i).
 * [中文] 思路:
 *     質因數分解 m = prod(q_i^k_i)，利用勒讓德公式計算各質數在 n! 中的總冪次，取各商數 count_i / k_i 的最小值。
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

int max_m_power_dividing_n_fact(int m, int n) {
    int min_p = 1000000;
    int temp = m;
    for (int d = 2; d * d <= temp; d++) {
        if (temp % d == 0) {
            int k = 0;
            while (temp % d == 0) { k++; temp /= d; }
            int count = 0;
            for (long long p = d; p <= n; p *= d) count += n / p;
            int power = count / k;
            if (power < min_p) min_p = power;
        }
    }
    if (temp > 1) {
        int d = temp, count = 0;
        for (long long p = d; p <= n; p *= d) count += n / p;
        if (count < min_p) min_p = count;
    }
    return min_p > 0 ? min_p : 0;
}

int main(void) {

    int p = max_m_power_dividing_n_fact(2, 4); // 4! = 24 has 2^3 -> p = 3
    int ok = (p == 3);
    printf("%s: UVa 10780 - Again Prime? No Time.\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
