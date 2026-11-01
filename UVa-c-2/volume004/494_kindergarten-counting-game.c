/*
 * ==========================================================================
 * UVa 494 - Kindergarten Counting Game
 * Title-CN: 幼稚園單字計數
 * Difficulty: UVa Star 1
 * Tags: string
 * ==========================================================================
 * [EN] Problem: Count words (consecutive alphabetical sequences) in a line.
 * [中文] 題目說明: 統計一行文字中連續英文字母構成的單字個數。
 * [EN] Approach: State flag `in_word`, count transitions from non-alpha to alpha.
 * [中文] 思路: 狀態機旗標判斷單字邊界。
 * ==========================================================================
 */
#include <stdio.h>
#include <ctype.h>

int count_words(const char *s) {
    int count = 0, in_word = 0;
    for (int i = 0; s[i]; i++) {
        if (isalpha((unsigned char)s[i])) {
            if (!in_word) { count++; in_word = 1; }
        } else {
            in_word = 0;
        }
    }
    return count;
}

int main(void) {
    int ok = (count_words("Me and my friend, we are 12 boys.") == 7);
    printf("%s: UVa 494 - Kindergarten Counting Game\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
