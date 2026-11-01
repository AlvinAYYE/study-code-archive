/*
 * ==========================================================================
 * UVa 10892 - LCM Cardinality
 * Title-CN: 最小公倍數基數
 * Difficulty: Medium
 * Tags: Math, Number Theory, GCD, LCM
 * URL: https://onlinejudge.org/external/108/10892.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count the number of pairs (a, b) such that 1 <= a <= b and lcm(a, b) = N.
 *
 * [中文] 題目概述:
 *     計算滿足 1 <= a <= b 且 lcm(a, b) = N 的整數對 (a, b) 的數量。
 *
 * [EN] Approach:
 *     Both a and b must be divisors of N. Find all divisors of N, then test each pair (d1, d2) if lcm(d1, d2) == N.
 * [中文] 解題思路:
 *     a 與 b 必為 N 的因數。先找出 N 的所有因數，雙重迴圈枚舉因數對檢查 lcm(d1, d2) 是否等於 N。
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

long long gcd_ll(long long a, long long b) { return b == 0 ? a : gcd_ll(b, a % b); }
long long lcm_ll(long long a, long long b) { return (a / gcd_ll(a, b)) * b; }

int lcm_cardinality(long long n) {
    long long divs[1500];
    int cnt = 0;
    for (long long d = 1; d * d <= n; d++) {
        if (n % d == 0) {
            divs[cnt++] = d;
            if (d * d != n) divs[cnt++] = n / d;
        }
    }
    int ans = 0;
    for (int i = 0; i < cnt; i++) {
        for (int j = i; j < cnt; j++) {
            if (lcm_ll(divs[i], divs[j]) == n) ans++;
        }
    }
    return ans;
}

int main(void) {

    int ok = (lcm_cardinality(2) == 2); // (1,2), (2,2)
    ok = ok && (lcm_cardinality(12) == 8);
    printf("%s: UVa 10892 - LCM Cardinality\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
