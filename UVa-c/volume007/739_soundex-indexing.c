/*
 * ==========================================================================
 * UVa 739 - Soundex Indexing
 * Title-CN: 聲學索引編碼
 * Difficulty: Easy
 * Tags: String, Soundex
 * URL: https://onlinejudge.org/external/7/739.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Encode a surname using the Soundex system (letter followed by 3 digits, padding with zeros, omitting vowels, collapsing duplicates).
 *
 * [中文] 題目概述:
 *     使用 Soundex 聲學編碼系統將姓氏轉換為 1 個首字母與 3 位數字的編碼（母音不編碼，相鄰同碼合併，補 0 至 4 位）。
 *
 * [EN] Approach:
 *     Keep first letter. Map rest according to Soundex rules. Skip code 0. Skip adjacent identical codes. Pad/truncate to 4 chars.
 * [中文] 解題思路:
 *     保留首字母，其餘字母按 Soundex 規則映射；略過代碼 0 及連續相同代碼，最後補 0 或截斷至 4 字元。
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

char soundex_code(char c) {
    switch (c) {
        case 'B': case 'P': case 'F': case 'V': return '1';
        case 'C': case 'S': case 'K': case 'G': case 'J': case 'Q': case 'X': case 'Z': return '2';
        case 'D': case 'T': return '3';
        case 'L': return '4';
        case 'M': case 'N': return '5';
        case 'R': return '6';
        default: return '0';
    }
}
void soundex(const char *name, char *out) {
    out[0] = name[0];
    int idx = 1;
    char last = soundex_code(name[0]);
    for (int i = 1; name[i] && idx < 4; i++) {
        char c = soundex_code(name[i]);
        if (c != '0' && c != last) {
            out[idx++] = c;
        }
        last = c;
    }
    while (idx < 4) out[idx++] = '0';
    out[4] = '\0';
}

int main(void) {

    char code[10];
    soundex("MILLER", code);
    int ok = (strcmp(code, "M460") == 0);
    printf("%s: UVa 739 - Soundex Indexing\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
