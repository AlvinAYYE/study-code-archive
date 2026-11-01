/*
 * ==========================================================================
 * UVa 483 - Word Scramble
 * Title-CN: 單字字元原地反轉
 * Difficulty: UVa Star 1
 * Tags: string
 * ==========================================================================
 * [EN] Problem: Reverse letters in each word while preserving whitespace formatting.
 * [中文] 題目說明: 將句子中的每個單字反轉輸出，保留原本的空格與換行。
 * [EN] Approach: Identify word boundaries, reverse characters in-place.
 * [中文] 思路: 雙指標找到每個單字的起點與終點進行反轉。
 * ==========================================================================
 */
#include <stdio.h>
#include <string.h>

void reverse_words(char *s) {
    int i = 0, start = 0;
    while (s[i]) {
        if (s[i] == ' ' || s[i] == '\n') {
            int l = start, r = i - 1;
            while (l < r) { char t = s[l]; s[l] = s[r]; s[r] = t; l++; r--; }
            start = i + 1;
        }
        i++;
    }
    int l = start, r = i - 1;
    while (l < r) { char t = s[l]; s[l] = s[r]; s[r] = t; l++; r--; }
}

int main(void) {
    char s[32] = "I love you";
    reverse_words(s);
    int ok = (strcmp(s, "I evol uoy") == 0);
    printf("%s: UVa 483 - Word Scramble\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
