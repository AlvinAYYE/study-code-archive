/*
 * ==========================================================================
 * UVa 10948 - The primary problem
 * Title-CN: 哥德巴赫猜想質數和分解
 * Difficulty: UVa Star 1
 * Tags: number-theory, math
 * URL: https://onlinejudge.org/external/109/10948.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Express an even integer N as the sum of two prime numbers p1 + p2 with maximum difference (p1 <= p2).
 *
 * [中文] 題目說明:
 *     將偶數整數 N 分解為兩質數之和 p1 + p2 (滿足 p1 <= p2 且 p1 盡可能小)。
 *
 * [EN] Approach:
 *     Precompute prime sieve. For each prime p1 starting at 2, check if N - p1 is also prime.
 * [中文] 思路:
 *     建立質數表，自 p1 = 2 開始循序檢驗 N - p1 是否亦為質數，找到首組解即為 p1 最小之最優解。
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

int is_prime10948(int n) {
    if (n < 2) return 0;
    for (int d = 2; d * d <= n; d++) if (n % d == 0) return 0;
    return 1;
}

int solve_uva10948(int n, int *p1, int *p2) {
    for (int p = 2; p <= n / 2; p++) {
        if (is_prime10948(p) && is_prime10948(n - p)) {
            *p1 = p; *p2 = n - p;
            return 1;
        }
    }
    return 0;
}

int main(void) {

    int p1, p2;
    int ok = solve_uva10948(10, &p1, &p2); // 3 + 7 = 10
    ok = ok && (p1 == 3 && p2 == 7);
    printf("%s: UVa 10948 - The primary problem\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
