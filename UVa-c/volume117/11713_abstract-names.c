/*
 * ==========================================================================
 * UVa 11713 - Abstract Names
 * Title-CN: 抽象姓名母音互換等價比對
 * Difficulty: UVa Star 1
 * Tags: string
 * URL: https://onlinejudge.org/external/117/11713.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Two names are equivalent if they have same length, consonants match identically, and any mismatch only substitutes a vowel for another vowel.
 *
 * [中文] 題目說明:
 *     若兩個名字長度相同、所有子音字母完全一致，且母音 (a, e, i, o, u) 僅能與其他母音互相替換，則判定兩名字等價。
 *
 * [EN] Approach:
 *     Check strlen equality. For each index, consonants must be identical; if one is vowel, both must be vowels.
 * [中文] 思路:
 *     比對兩字串長度，逐字元檢查：非母音者必須完全相等，若是母音則另一方也必須同為五大元音字母之一。
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

int is_vowel_11713(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int solve_uva11713(const char *s1, const char *s2) {
    if (strlen(s1) != strlen(s2)) return 0;
    for (int i = 0; s1[i]; i++) {
        if (is_vowel_11713(s1[i])) {
            if (!is_vowel_11713(s2[i])) return 0;
        } else {
            if (s1[i] != s2[i]) return 0;
        }
    }
    return 1;
}

int main(void) {

    int ok = solve_uva11713("tom", "tim") && !solve_uva11713("tom", "tammy");
    printf("%s: UVa 11713 - Abstract Names\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
