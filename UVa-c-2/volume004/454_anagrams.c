/*
 * ==========================================================================
 * UVa 454 - Anagrams
 * Title-CN: 字謎對 (忽略空白排序對齊)
 * Difficulty: Easy
 * Tags: String, Sorting, Hash
 * URL: https://onlinejudge.org/external/4/454.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given a list of words or phrases, find all pairs that are anagrams of each other (ignoring spaces).
 *
 * [中文] 題目說明:
 *     在字詞列表中找出所有互為重組字謎（忽略所有空白符號）的詞對並按字典序輸出。
 *
 * [EN] Approach:
 *     Extract letters from each phrase, sort letters alphabetically to create signature. Phrases with identical signatures are anagrams.
 * [中文] 思路:
 *     濾除空格後將字母排序生成特徵字串，特徵相同的短語即互為重組字謎對。
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

void anagram_sig(const char *s, char *sig) {
    int len = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] != ' ') sig[len++] = s[i];
    }
    // bubble sort signature
    for (int i = 0; i < len - 1; i++)
        for (int j = i + 1; j < len; j++)
            if (sig[i] > sig[j]) { char t = sig[i]; sig[i] = sig[j]; sig[j] = t; }
    sig[len] = '\0';
}
bool are_anagrams(const char *s1, const char *s2) {
    char sig1[100], sig2[100];
    anagram_sig(s1, sig1);
    anagram_sig(s2, sig2);
    return strcmp(sig1, sig2) == 0;
}

int main(void) {

    int ok = are_anagrams("dormitory", "dirty room");
    printf("%s: UVa 454 - Anagrams\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
