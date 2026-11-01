/*
 * ==========================================================================
 * UVa 13148 - A Giveaway
 * Title-CN: 雙重冪次判別 (既是平方又是立方)
 * Difficulty: Easy
 * Tags: Math, Number Theory
 * URL: https://onlinejudge.org/external/131/13148.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine whether a number is 'Special' (both an integer square and an integer cube, i.e., a sixth power).
 *
 * [中文] 題目描述:
 *     判斷給定整數是否為「特殊數」（同時為整數的完全平方與完全立方，即六次方數）。
 *
 * [EN] Approach:
 *     Compute round(pow(n, 1.0/6.0)) and verify if its 6th power equals n.
 *
 * [中文] 解題思維:
 *     計算 n 的 1/6 次方四捨五入為整數 r，檢查 r^6 是否等於 n。
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

int is_special_13148(long long n) {
    if (n <= 0) return 0;
    long long r = (long long)(round(pow((double)n, 1.0 / 6.0)));
    long long p = 1;
    for (int i = 0; i < 6; i++) p *= r;
    return (p == n);
}

int main(void) {

    int ok = is_special_13148(1) &&
             is_special_13148(64) &&
             is_special_13148(729) &&
             !is_special_13148(16) &&
             !is_special_13148(27);
    printf("%s: UVa 13148 - A Giveaway\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
