/*
 * ==========================================================================
 * UVa 10852 - Less Prime
 * Title-CN: 稍小質數
 * Difficulty: Easy
 * Tags: Math, Number Theory, Prime
 * URL: https://onlinejudge.org/external/108/10852.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given N, find a prime p <= N such that N - p * p_mult is maximized (where p_mult is the largest multiplier such that p * p_mult <= N).
 *
 * [中文] 題目概述:
 *     給定 N，尋找質數 p <= N 使得 N - p * k 達到最大（其中 k 為滿足 p * k <= N 的最大整數）。
 *
 * [EN] Approach:
 *     Taking k = 1 gives remainder N - p. The remainder is maximized when p is the smallest prime strictly greater than N / 2.
 * [中文] 解題思路:
 *     當 k = 1 時餘數為 N - p。使餘數最大的最佳質數 p 即為嚴格大於 N / 2 的最小質數（此時 k=1 且 p 越小餘數越大）。
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

bool is_p(int x) {
    if (x < 2) return false;
    for (int d = 2; d * d <= x; d++) if (x % d == 0) return false;
    return true;
}
int find_less_prime(int n) {
    for (int p = n / 2 + 1; p <= n; p++) {
        if (is_p(p)) return p;
    }
    return n;
}

int main(void) {

    int ok = (find_less_prime(10) == 7); // 7 > 5, 10 - 7 = 3
    printf("%s: UVa 10852 - Less Prime\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
