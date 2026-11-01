/*
 * ==========================================================================
 * UVa 756 - Biorhythms
 * Title-CN: 生物節律 (中國剩餘定理)
 * Difficulty: Easy
 * Tags: Math, Chinese Remainder Theorem
 * URL: https://onlinejudge.org/external/7/756.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the number of days until the physical (23d), emotional (28d), and intellectual (33d) cycles peak on the exact same day.
 *
 * [中文] 題目說明:
 *     體力（23天）、情緒（28天）、智力（33天）三個生物節律週期，求從給定日 d 起最快多少天後三者再次同時達到峰值。
 *
 * [EN] Approach:
 *     Chinese Remainder Theorem: x = p mod 23, x = e mod 28, x = i mod 33. Period is 23*28*33 = 21252. Output (x - d - 1) % 21252 + 1.
 * [中文] 思路:
 *     中國剩餘定理：CRT 求解模 23, 28, 33 的同餘方程，在 (d, d + 21252] 範圍內求最小正整數解。
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

int days_to_next_triple_peak(int p, int e, int i, int d) {
    int ans = (5544 * p + 14421 * e + 1288 * i - d) % 21252;
    if (ans <= 0) ans += 21252;
    return ans;
}

int main(void) {

    int ans = days_to_next_triple_peak(0, 0, 0, 0);
    int ok = (ans == 21252);
    printf("%s: UVa 756 - Biorhythms\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
