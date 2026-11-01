/*
 * ==========================================================================
 * UVa 834 - Continued Fractions
 * Title-CN: 連分數展開 (歐幾里得輾轉相除)
 * Difficulty: UVa Star 1
 * Tags: math, number-theory
 * URL: https://onlinejudge.org/external/8/834.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Convert rational number a/b into continued fraction representation [b0; b1, b2, ...].
 *
 * [中文] 題目說明:
 *     將有理數 a/b 展開為連分數形式：求商數並將餘數倒數繼續輾轉相除。
 *
 * [EN] Approach:
 *     Euclidean division: repeatedly take quotient q = a / b, replace (a, b) with (b, a % b) until remainder is 0.
 * [中文] 思路:
 *     利用輾轉相除法求整數商數 q = a / b，更新 a, b = b, a % b，重複迭代直到餘數為 0。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void solve_uva834(int a, int b, int *terms, int *count) {
    *count = 0;
    while (b) {
        terms[(*count)++] = a / b;
        int rem = a % b;
        a = b;
        b = rem;
    }
}

int main(void) {

    int terms[20], cnt;
    solve_uva834(43, 19, terms, &cnt);
    int ok = (cnt == 4 && terms[0] == 2 && terms[1] == 3 && terms[2] == 1 && terms[3] == 4);
    printf("%s: UVa 834 - Continued Fractions\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
