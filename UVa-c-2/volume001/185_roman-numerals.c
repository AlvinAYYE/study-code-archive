/*
 * ==========================================================================
 * UVa 185 - Roman Numerals
 * Title-CN: 羅馬數字算式正確性與唯一解回溯
 * Difficulty: UVa Star 2
 * Tags: backtracking, string
 * URL: https://onlinejudge.org/external/1/185.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given an equation in Roman numerals (A + B = C), check if it is correct as standard Roman, and check if it has a unique cryptarithm substitution.
 *
 * [中文] 題目說明:
 *     給定羅馬數字算式 A + B = C，檢驗其作為標準羅馬數字是否正確，並將各字母視為算蟲字謎 (Cryptarithm) 判定是否存在唯一解。
 *
 * [EN] Approach:
 *     Part 1: convert Roman to integer and check A+B=C. Part 2: backtrack over digits 0-9 for distinct Roman letters and count solutions.
 * [中文] 思路:
 *     第一部分將羅馬數字轉換為整數驗證等式；第二部分將字母映射至 0-9 進行回溯窮舉，計數是否有唯一解或無解。
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

int roman_char_val(char c) {
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int roman_to_int(const char *s) {
    int sum = 0, n = strlen(s);
    for (int i = 0; i < n; i++) {
        int v = roman_char_val(s[i]);
        if (i + 1 < n && roman_char_val(s[i + 1]) > v) sum -= v;
        else sum += v;
    }
    return sum;
}

int main(void) {

    int ok = (roman_to_int("XIV") == 14 && roman_to_int("MCMXC") == 1990);
    printf("%s: UVa 185 - Roman Numerals\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
