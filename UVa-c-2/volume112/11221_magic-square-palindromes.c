/*
 * ==========================================================================
 * UVa 11221 - Magic square palindromes.
 * Title-CN: 魔方回文
 * Difficulty: Easy
 * Tags: String, Palindrome
 * URL: https://onlinejudge.org/external/112/11221.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine if a cleaned sentence (letters only) forms an K x K magic square palindrome (reads same along rows and columns forward and backward).
 *
 * [中文] 題目概述:
 *     判斷去除標點符號後的純英文字串是否為 K x K 的魔方回文（水平與垂直正反讀皆完全一致）。
 *
 * [EN] Approach:
 *     Filter out non-alpha chars. Check if length L is a perfect square K*K. If so, verify palindrome and symmetric grid transpose.
 * [中文] 解題思路:
 *     過濾純字母，檢查長度 L 是否為完全平方數 K*K，若是則驗證是否為回文且網格對稱。
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

int magic_square_palindrome_size(const char *s) {
    char clean[10000];
    int len = 0;
    for (int i = 0; s[i]; i++) {
        if (isalpha((unsigned char)s[i])) clean[len++] = tolower((unsigned char)s[i]);
    }
    clean[len] = '\0';
    int k = (int)(sqrt(len) + 0.5);
    if (k * k != len) return 0;
    for (int i = 0; i < len / 2; i++) {
        if (clean[i] != clean[len - 1 - i]) return 0;
    }
    for (int r = 0; r < k; r++) {
        for (int c = 0; c < k; c++) {
            if (clean[r * k + c] != clean[c * k + r]) return 0;
        }
    }
    return k;
}

int main(void) {

    int k = magic_square_palindrome_size("sator arepo tenet opera rotas");
    int ok = (k == 5);
    printf("%s: UVa 11221 - Magic square palindromes.\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
