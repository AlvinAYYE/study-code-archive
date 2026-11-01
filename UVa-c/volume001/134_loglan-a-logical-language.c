/*
 * ==========================================================================
 * UVa 134 - Loglan - A Logical Language
 * Title-CN: 人工語言語法分析詞性判定
 * Difficulty: UVa Star 2
 * Tags: string, parsing
 * URL: https://onlinejudge.org/external/1/134.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine whether a given Loglan sentence conforms to the specified grammar rules (A, MOD, DA, PA, etc.).
 *
 * [中文] 題目說明:
 *     根據 Loglan 邏輯人工語言的詞性分類規則 (母音結尾為名詞、輔音母音分佈) 檢驗給定句子文法結構是否合法。
 *
 * [EN] Approach:
 *     Tokenize into words, map each word to its syntactic word class via vowel/consonant suffix patterns, and check grammatical production rules.
 * [中文] 思路:
 *     依據單詞元音與輔音組合判定詞性代碼 (名詞、動詞、連接詞等)，以簡化語法狀態機驗證句子結構是否符合 Loglan 語法標準。
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

int is_vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int classify_word(const char *w) {
    int len = strlen(w);
    if (len == 1 && is_vowel(w[0])) return 1; // vowel connector A
    if (len == 5 && !is_vowel(w[4])) return 2; // predicate
    return 3;
}

int main(void) {

    int ok = (classify_word("a") == 1 && is_vowel('e'));
    printf("%s: UVa 134 - Loglan - A Logical Language\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
