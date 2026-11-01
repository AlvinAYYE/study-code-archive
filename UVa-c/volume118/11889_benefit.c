/*
 * ==========================================================================
 * UVa 11889 - Benefit
 * Title-CN: 利益最大化 (LCM逆算與最小B值)
 * Difficulty: Medium
 * Tags: Math, Number Theory, LCM, GCD
 * URL: https://onlinejudge.org/external/118/11889.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given A and C, find the smallest positive integer B such that LCM(A, B) = C. If no such B exists, output 'NO SOLUTION'.
 *
 * [中文] 題目說明:
 *     給定整數 A 與 C，求滿足 LCM(A, B) = C 的最小正整數 B；若無解輸出 NO SOLUTION。
 *
 * [EN] Approach:
 *     C must be divisible by A. Prime factorize A and C. For each prime, if power in C > power in A, B must contain prime^(power in C).
 * [中文] 思路:
 *     若 C % A != 0 則無解。對 A 與 C 做質因數分解：若 C 中質因數冪次大於 A，則 B 必須包含該質因數在 C 中的全部冪次。
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

long long solve_benefit(long long a, long long c) {
    if (c % a != 0) return -1;
    long long b = c / a;
    // ensure lcm(a, b) == c
    long long temp_a = a;
    while (1) {
        long long g = 0;
        long long ta = temp_a, tb = b;
        while (tb) { long long t = tb; tb = ta % tb; ta = t; }
        g = ta;
        if (g == 1) break;
        b *= g;
        temp_a /= g;
    }
    return b;
}

int main(void) {

    int ok = (solve_benefit(2, 6) == 3) && (solve_benefit(3, 5) == -1);
    printf("%s: UVa 11889 - Benefit\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
