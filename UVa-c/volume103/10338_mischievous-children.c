/*
 * ==========================================================================
 * UVa 10338 - Mischievous Children
 * Title-CN: 字母異位詞多項式排列計數
 * Difficulty: UVa Star 1
 * Tags: math, combinatorics
 * URL: https://onlinejudge.org/external/103/10338.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the number of distinct word anagrams that can be formed using all letters of a given uppercase word.
 *
 * [中文] 題目說明:
 *     計算給定英文字串中所有字母能組合出的相異排列字串總數 (多項式係數 N! / (c1! * c2! * ... * ck!))。
 *
 * [EN] Approach:
 *     Multinomial permutation formula: L! / prod(count[c]!). Precompute factorials using 64-bit unsigned integers.
 * [中文] 思路:
 *     套用多項式排列公式：總長度階乘除以各相異字母出現次數的階乘積，以 64 位元整數累乘計算。
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

long long solve_uva10338(const char *s) {
    int cnt[26] = {0};
    int len = strlen(s);
    for (int i = 0; i < len; i++) cnt[s[i] - 'A']++;
    long long ans = 1;
    for (int i = 1; i <= len; i++) ans *= i;
    for (int i = 0; i < 26; i++) {
        for (int j = 1; j <= cnt[i]; j++) ans /= j;
    }
    return ans;
}

int main(void) {

    int ok = (solve_uva10338("AAB") == 3 && solve_uva10338("ABC") == 6);
    printf("%s: UVa 10338 - Mischievous Children\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
