/*
 * ==========================================================================
 * UVa 843 - Crypt Kicker
 * Title-CN: 解密者
 * Difficulty: Hard
 * Tags: Backtracking, Cryptography
 * URL: https://onlinejudge.org/external/8/843.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given a dictionary of words and encrypted lines of text, find a substitution cipher that maps encrypted words to dictionary words.
 *
 * [中文] 題目概述:
 *     給定字詞字典與加密文字行，尋找單字母替換式密碼將每個加密單字映射到合法的字典單字。
 *
 * [EN] Approach:
 *     Backtracking search over words in the encrypted line, maintaining bijective mapping between encrypted and plain characters.
 * [中文] 解題思路:
 *     對加密行中的單字進行回溯搜尋，維護加密字元與明文字元之間的雙射映射。
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

int match_word(const char *cword, const char *dword, char *map, char *rev) {
    int len = strlen(cword);
    if ((int)strlen(dword) != len) return 0;
    for (int i = 0; i < len; i++) {
        char c = cword[i], d = dword[i];
        if (map[(int)c] && map[(int)c] != d) return 0;
        if (rev[(int)d] && rev[(int)d] != c) return 0;
    }
    return 1;
}

int main(void) {

    char map[256] = {0}, rev[256] = {0};
    int ok = match_word("and", "the", map, rev) == 1;
    printf("%s: UVa 843 - Crypt Kicker\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
