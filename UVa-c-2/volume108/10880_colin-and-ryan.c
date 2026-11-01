/*
 * ==========================================================================
 * UVa 10880 - Colin and Ryan
 * Title-CN: 柯林與萊恩 (因數分解除數條件)
 * Difficulty: Easy
 * Tags: Math, Number Theory, Divisors
 * URL: https://onlinejudge.org/external/108/10880.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given total cookies C and remaining cookies R, find all possible guest counts Q such that C % Q = R (so Q > R and Q divides C - R).
 *
 * [中文] 題目說明:
 *     已知總餅乾數 C 與剩餘餅乾數 R，求所有可能的賓客人數 Q（滿足 C % Q = R，即 Q > R 且 Q 整除 C - R）。
 *
 * [EN] Approach:
 *     If C == R, Q = 0 is unique solution. Otherwise, find all divisors Q of (C - R) such that Q > R, and sort in ascending order.
 * [中文] 思路:
 *     若 C == R，則客人數為 0；否則在 (C - R) 的所有因數中挑選嚴格大於 R 的數值並升序輸出。
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

int find_possible_guests(long long c, long long r, long long *guests) {
    if (c == r) { guests[0] = 0; return 1; }
    long long diff = c - r;
    int count = 0;
    for (long long d = 1; d * d <= diff; d++) {
        if (diff % d == 0) {
            if (d > r) guests[count++] = d;
            if (d * d != diff && diff / d > r) guests[count++] = diff / d;
        }
    }
    for (int i = 0; i < count - 1; i++)
        for (int j = i + 1; j < count; j++)
            if (guests[i] > guests[j]) { long long t = guests[i]; guests[i] = guests[j]; guests[j] = t; }
    return count;
}

int main(void) {

    long long g[20];
    int cnt = find_possible_guests(10, 2, g); // diff = 8, divisors > 2: 4, 8
    int ok = (cnt == 2 && g[0] == 4 && g[1] == 8);
    printf("%s: UVa 10880 - Colin and Ryan\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
