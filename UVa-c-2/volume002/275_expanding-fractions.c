/*
 * ==========================================================================
 * UVa 275 - Expanding Fractions
 * Title-CN: 分數循環小數展開與週期計算
 * Difficulty: UVa Star 2
 * Tags: math, simulation
 * URL: https://onlinejudge.org/external/2/275.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given numerator and denominator of a fraction in (0, 1), compute its decimal expansion.
 *     Determine whether it terminates or repeats, and if it repeats, find the length of the recurring cycle.
 *
 * [中文] 題目說明:
 *     給定介於 (0, 1) 的真分數分子與分母，計算其十進位小數展開。
 *     判斷該小數為有限小數或循環小數；若為循環小數，求其循環節長度。
 *
 * [EN] Approach:
 *     Simulate long division. Maintain an array recording the step at which each remainder was first seen.
 *     If remainder becomes 0, expansion terminates. If a remainder reappears, cycle length is current step minus previous step.
 * [中文] 思路:
 *     長除法模擬：以陣列記錄每個餘數首次出現的小數位數。
 *     若餘數變為 0 則為有限小數；若同一餘數再次出現，則循環節長度為當前位數減去該餘數上次出現之位數。
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

int solve_uva275(int num, int den, char *digits, int *cycle_len) {
    int pos[1005];
    memset(pos, 0, sizeof(pos));
    int len = 0;
    int rem = num % den;

    while (rem != 0 && pos[rem] == 0) {
        pos[rem] = ++len;
        rem *= 10;
        digits[len - 1] = (rem / den) + '0';
        rem %= den;
    }

    digits[len] = '\0';
    if (rem == 0) {
        *cycle_len = 0; // terminates
    } else {
        *cycle_len = len - pos[rem] + 1; // recurring cycle length
    }
    return len;
}

int main(void) {
    char d[100];
    int cycle;
    int len = solve_uva275(3, 7, d, &cycle);
    // 3/7 = 0.428571... length 6 cycle 6
    int ok = (len == 6 && cycle == 6 && strcmp(d, "428571") == 0);

    len = solve_uva275(1, 4, d, &cycle);
    // 1/4 = 0.25 terminates
    ok = ok && (len == 2 && cycle == 0 && strcmp(d, "25") == 0);

    printf("%s: UVa 275 - Expanding Fractions\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
