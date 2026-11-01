/*
 * ==========================================================================
 * UVa 10791 - Minimum Sum LCM
 * Title-CN: 最小公倍數最小和
 * Difficulty: Medium
 * Tags: Math, Number Theory, Prime Factorization
 * URL: https://onlinejudge.org/external/107/10791.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the minimum sum of two or more positive integers whose least common multiple is N.
 *
 * [中文] 題目說明:
 *     求至少兩個正整數的最小可能和，使得它們的最小公倍數恰好為 N。
 *
 * [EN] Approach:
 *     Prime factorize N = p1^a1 * p2^a2 * ... Minimum sum is achieved by taking each prime power p_i^a_i. If only 1 prime power, add 1.
 * [中文] 思路:
 *     對 N 進行質因數分解：N = p1^a1 * p2^a2 * ...，取各質因數冪次之和；若只有一種質因數則需加上 1。
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

long long min_sum_lcm(long long n) {
    if (n == 1) return 2;
    long long sum = 0;
    int count = 0;
    long long temp = n;
    for (long long d = 2; d * d <= temp; d++) {
        if (temp % d == 0) {
            long long factor = 1;
            while (temp % d == 0) { factor *= d; temp /= d; }
            sum += factor;
            count++;
        }
    }
    if (temp > 1) { sum += temp; count++; }
    if (count == 1) sum += 1;
    return sum;
}

int main(void) {

    int ok = (min_sum_lcm(12) == 7); // 4 + 3 = 7
    ok = ok && (min_sum_lcm(10) == 7); // 2 + 5 = 7
    printf("%s: UVa 10791 - Minimum Sum LCM\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
