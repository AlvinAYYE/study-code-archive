/*
 * ==========================================================================
 * UVa 11577 - Letter Frequency
 * Title-CN: 字母最高頻率統計 (不分大小寫)
 * Difficulty: UVa Star 1
 * Tags: string, simulation
 * URL: https://onlinejudge.org/external/115/11577.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count case-insensitive frequency of letters in text. Output letters with highest frequency in alphabetical order.
 *
 * [中文] 題目說明:
 *     統計文字中英文字母出現頻率 (不分大小寫)，將出現次數達到最高峰的所有字母按字典序輸出。
 *
 * [EN] Approach:
 *     Count letter frequencies using 26-element array. Find max frequency, then print all letters achieving that max.
 * [中文] 思路:
 *     陣列統計 26 個字母出現次數，找出最大頻率 max_freq，二次掃描將所有次數等於 max_freq 的小寫字母印出。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <ctype.h>

void solve_uva11577(const char *s, char *out) {
    int cnt[26] = {0};
    for (int i = 0; s[i]; i++) {
        if (isalpha((unsigned char)s[i])) {
            cnt[tolower((unsigned char)s[i]) - 'a']++;
        }
    }
    int max_f = 0;
    for (int i = 0; i < 26; i++) if (cnt[i] > max_f) max_f = cnt[i];
    int idx = 0;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] == max_f) out[idx++] = 'a' + i;
    }
    out[idx] = '\0';
}

int main(void) {

    char res[30];
    solve_uva11577("Computers account for only 5% of the country's commercial electricity consumption.", res);
    int ok = (res[0] == 'c' || res[0] == 'o' || res[0] == 'e');
    printf("%s: UVa 11577 - Letter Frequency\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
