/*
 * ==========================================================================
 * UVa 850 - Crypt Kicker II
 * Title-CN: 龐格蘭字母全字母句置換解密
 * Difficulty: UVa Star 2
 * Tags: string
 * URL: https://onlinejudge.org/external/8/850.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Decrypt encrypted lines by finding a ciphertext line that matches the pangram pattern 'the quick brown fox jumps over the lazy dog'.
 *
 * [中文] 題目說明:
 *     比對密文列表中是否存在與標準英文字母全字母句 "the quick brown fox jumps over the lazy dog" 模式完全相符的句子，推算出解密對照表並解密全文。
 *
 * [EN] Approach:
 *     Find line with identical word lengths matching the 43-character target phrase. Build 1-to-1 bijection cipher table and decrypt all lines.
 * [中文] 思路:
 *     逐行比對單詞長度與空格分佈是否與 43 字元的目標全字母句完全一致，構造單射對照表並將全篇密文字串解密還原。
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

int match_pangram(const char *cipher, char *table) {
    const char *target = "the quick brown fox jumps over the lazy dog";
    if (strlen(cipher) != strlen(target)) return 0;
    char m[256] = {0}, rev[256] = {0};
    for (int i = 0; cipher[i]; i++) {
        char c = cipher[i], t = target[i];
        if (c == ' ' || t == ' ') {
            if (c != t) return 0;
        } else {
            if (m[(unsigned char)c] && m[(unsigned char)c] != t) return 0;
            if (rev[(unsigned char)t] && rev[(unsigned char)t] != c) return 0;
            m[(unsigned char)c] = t;
            rev[(unsigned char)t] = c;
        }
    }
    memcpy(table, m, 256);
    return 1;
}

int main(void) {

    char tbl[256];
    int ok = match_pangram("the quick brown fox jumps over the lazy dog", tbl);
    ok = ok && (tbl['t'] == 't' && tbl['q'] == 'q');
    printf("%s: UVa 850 - Crypt Kicker II\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
