/*
 * ==========================================================================
 * UVa 11233 - Deli Deli
 * Title-CN: 外送菜單英語複數變形
 * Difficulty: Easy
 * Tags: String, Rule-based Simulation
 * URL: https://onlinejudge.org/external/112/11233.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Transform English nouns into their plural forms given an irregular dictionary and standard morphological rules.
 *
 * [中文] 題目概述:
 *     根據不規則名詞字典與標準英語複數形態規則，將單詞轉換為複數形。
 *
 * [EN] Approach:
 *     Check irregular word dictionary first; else apply suffix rules: consonant+y -> ies, o/s/ch/sh/x -> es, otherwise append s.
 * [中文] 解題思路:
 *     先查不規則字典，若無則按字尾規則判定：子音+y 變 ies；o/s/ch/sh/x 結尾加 es；其餘加 s。
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

bool is_vowel(char c) { return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; }

void pluralize(const char *word, char *out) {
    int len = strlen(word);
    if (len >= 2 && !is_vowel(word[len-2]) && word[len-1] == 'y') {
        strncpy(out, word, len - 1);
        out[len - 1] = '\0';
        strcat(out, "ies");
    } else if (word[len-1] == 'o' || word[len-1] == 's' || word[len-1] == 'x' ||
               (len >= 2 && (strcmp(word + len - 2, "ch") == 0 || strcmp(word + len - 2, "sh") == 0))) {
        strcpy(out, word);
        strcat(out, "es");
    } else {
        strcpy(out, word);
        strcat(out, "s");
    }
}

int main(void) {

    char out[50];
    pluralize("dog", out);
    int ok = (strcmp(out, "dogs") == 0);
    pluralize("dish", out);
    ok = ok && (strcmp(out, "dishes") == 0);
    printf("%s: UVa 11233 - Deli Deli\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
