/*
 * ==========================================================================
 * UVa 151 - Power Crisis
 * Title-CN: 約瑟夫環危機最後停電區域求解
 * Difficulty: UVa Star 1
 * Tags: math, simulation
 * URL: https://onlinejudge.org/external/1/151.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given N regions with region 1 shutting off first, find the minimum step m such that region 13 is the last region shut off.
 *
 * [中文] 題目說明:
 *     給定 N 個供電區域，第 1 區最先停電，求最小每步間隔 m，使得第 13 區剛好是最後一個被停電的區域。
 *
 * [EN] Approach:
 *     Simulate Josephus elimination on N - 1 remaining elements starting after 1. Increment m until the last remaining element is 13.
 * [中文] 思路:
 *     自第 1 區停電後，對剩餘 N - 1 個區域進行約瑟夫環遞推模擬，枚舉間隔 m 直到最後勝出者編號為 13。
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

int solve_uva151(int n) {
    for (int m = 1; ; m++) {
        int pos = 0; // index among 1 to n-1 elements
        for (int i = 2; i <= n - 1; i++) {
            pos = (pos + m) % i;
        }
        // In original 2..n numbering, pos corresponds to (pos + 2)
        if (pos + 2 == 13) return m;
    }
}

int main(void) {

    int m = solve_uva151(17);
    int ok = (m == 7);
    printf("%s: UVa 151 - Power Crisis\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
