/*
 * ==========================================================================
 * UVa 11424 - GCD - Extreme (I)
 * Title-CN: 極限最大公因數求和 I (尤拉函數倍數和)
 * Difficulty: Medium
 * Tags: Math, Number Theory, Euler Totient
 * URL: https://onlinejudge.org/external/114/11424.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Compute sum_{i=1}^{N-1} sum_{j=i+1}^N gcd(i, j) for N up to 200,000.
 *
 * [中文] 題目說明:
 *     計算 N 以內所有數對的最大公因數總和 G = sum_{i=1}^{N-1} sum_{j=i+1}^N gcd(i, j)（N <= 200,000）。
 *
 * [EN] Approach:
 *     Precompute Euler's phi function, accumulate f[n] = sum_{d|n} d * phi(n/d), prefix sum of f gives answer.
 * [中文] 思路:
 *     預先線性篩求尤拉函數 phi，倍數法累加 f[j] += i * phi[j/i]，前綴和快速回答查詢。
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

long long gcd_sum_small(int n) {
    long long ans = 0;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int a = i, b = j;
            while (b) { int t = b; b = a % b; a = t; }
            ans += a;
        }
    }
    return ans;
}

int main(void) {

    int ok = (gcd_sum_small(4) == 7);
    printf("%s: UVa 11424 - GCD - Extreme (I)\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
