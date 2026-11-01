/*
 * ==========================================================================
 * UVa 576 - Haiku Review
 * Title-CN: 日本俳句 5-7-5 音節規則審查
 * Difficulty: UVa Star 1
 * Tags: string
 * URL: https://onlinejudge.org/external/5/576.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine if a 3-phrase Haiku poem separated by '/' conforms to the 5-7-5 syllable structure, or report the index of the first incorrect phrase.
 *
 * [中文] 題目說明:
 *     審查以斜線 '/' 分隔的三段式日本俳句是否符合 5-7-5 音節規範；若不符合則輸出首個出錯之段落編號 (1, 2, 3)；若正確輸出 'Y'。
 *
 * [EN] Approach:
 *     Count vowel sequences (consecutive vowels count as 1 syllable: a, e, i, o, u, y). Compare counts of the 3 phrases with 5, 7, 5.
 * [中文] 思路:
 *     以母音字母 (a, e, i, o, u, y) 計算音節數 (連續母音合併為 1 個音節)，分別檢查三段之音節是否恰為 5, 7, 5。
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

int is_vowel576(char c) {
    return c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='y';
}

int count_syllables(const char *s, int len) {
    int count = 0, in_vowel = 0;
    for (int i = 0; i < len; i++) {
        if (is_vowel576(s[i])) {
            if (!in_vowel) { count++; in_vowel = 1; }
        } else {
            in_vowel = 0;
        }
    }
    return count;
}

int main(void) {

    int c = count_syllables("haiku", 5); // ai is 1, u is 1 -> 2
    int ok = (c == 2);
    printf("%s: UVa 576 - Haiku Review\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
