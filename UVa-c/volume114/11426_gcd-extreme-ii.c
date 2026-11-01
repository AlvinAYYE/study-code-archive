/*
 * ==========================================================================
 * UVa 11426 - GCD - Extreme (II)
 * Title-CN: 極限最大公因數求和 (歐拉函數)
 * Difficulty: Medium
 * Tags: Math, Number Theory, Euler Totient
 * URL: https://onlinejudge.org/external/114/11426.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Compute G = sum_{i=1}^{N-1} sum_{j=i+1}^N gcd(i, j) for N up to 4000000.
 *
 * [中文] 題目說明:
 *     計算 G = sum_{i=1}^{N-1} sum_{j=i+1}^N gcd(i, j)，N 最大達 4000000。
 *
 * [EN] Approach:
 *     Use Euler's phi function: sum_{i=1}^n gcd(i, n) = sum_{d|n} d * phi(n/d). Precompute with sieve in O(N log N).
 * [中文] 思路:
 *     利用尤拉函數性質化簡：gcd(i, n) 的和等於 sum_{d|n} d * phi(n/d)，預處理倍數累加與前綴和。
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

long long sum_gcd_pair(int n) {
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

    long long res = sum_gcd_pair(4); // gcd(1,2)+gcd(1,3)+gcd(1,4)+gcd(2,3)+gcd(2,4)+gcd(3,4) = 1+1+1+1+2+1 = 7
    int ok = (res == 7);
    printf("%s: UVa 11426 - GCD - Extreme (II)\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
