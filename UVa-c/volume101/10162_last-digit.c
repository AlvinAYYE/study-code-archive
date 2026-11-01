/*
 * ==========================================================================
 * UVa 10162 - Last Digit
 * Title-CN: 冪次和最後一位數字 (週期性)
 * Difficulty: Easy
 * Tags: Math, Periodicity
 * URL: https://onlinejudge.org/external/101/10162.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the last digit of sum_{i=1}^N i^i for large integer N.
 *
 * [中文] 題目說明:
 *     求 sum_{i=1}^N i^i 的個位數字（N 為大整數）。
 *
 * [EN] Approach:
 *     The sequence of last digits of sum_{i=1}^N i^i repeats with period 100. Evaluate S(N % 100).
 * [中文] 思路:
 *     i^i mod 10 以 100 為週期重複循環。將大數 N 取模 100 後直接查表前綴和即為最後一位數字。
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

int last_digit_sum(long long n_mod_100) {
    int sum = 0;
    for (int i = 1; i <= n_mod_100; i++) {
        int term = 1;
        for (int p = 0; p < i; p++) term = (term * (i % 10)) % 10;
        sum = (sum + term) % 10;
    }
    return sum;
}

int main(void) {

    int ok = (last_digit_sum(1) == 1) && (last_digit_sum(2) == 5); // 1^1 + 2^2 = 5
    printf("%s: UVa 10162 - Last Digit\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
