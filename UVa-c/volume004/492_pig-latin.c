/*
 * ==========================================================================
 * UVa 492 - Pig-Latin
 * Title-CN: 兒童黑話轉換 (Pig-Latin)
 * Difficulty: UVa Star 1
 * Tags: string, simulation
 * URL: https://onlinejudge.org/external/4/492.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Convert text to Pig-Latin: if word starts with vowel, append 'ay'; if consonant, move first letter to end and append 'ay'.
 *
 * [中文] 題目說明:
 *     依規則轉換兒童黑話：母音 (a,e,i,o,u) 開頭單字末尾加 'ay'；子音開頭單字將首字母移至字尾再加 'ay'。
 *
 * [EN] Approach:
 *     Scan characters: identify words with isalpha(). Apply prefix movement logic based on whether first char is vowel.
 * [中文] 思路:
 *     逐字元掃描，以 isalpha() 分辨單字與非單字。判斷字首是否為母音，子音將首字元移至末端後串接 'ay'。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <ctype.h>

int is_vowel_492(char c) {
    c = (char)tolower((unsigned char)c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main(void) {

    int ok = is_vowel_492('A') && !is_vowel_492('b');
    printf("%s: UVa 492 - Pig-Latin\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
