/*
 * ==========================================================================
 * UVa 12820 - Cool Word
 * Title-CN: 酷單字 (字母相異頻率計數)
 * Difficulty: UVa Star 1
 * Tags: string, hash-table
 * URL: https://onlinejudge.org/external/128/12820.pdf
 * ==========================================================================
 * [EN] Problem:
 *     A word is cool if it has at least 2 distinct letters and all letter frequencies are pairwise distinct.
 *
 * [中文] 題目說明:
 *     酷單字定義：至少含有 2 種相異字母，且所有出現字母的頻率兩兩互不相同。
 *
 * [EN] Approach:
 *     Count letter frequencies. Check >= 2 distinct letters and ensure no two frequencies are equal.
 * [中文] 思路:
 *     陣列統計字母出現頻率，檢查字母種數 >= 2，並用標記陣列確認所有非零頻率互不相同。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva12820(const char *s) {
    int cnt[26] = {0};
    for (int i = 0; s[i]; i++) cnt[s[i] - 'a']++;
    int distinct_letters = 0;
    int freq_used[50] = {0};
    for (int i = 0; i < 26; i++) {
        if (cnt[i] > 0) {
            distinct_letters++;
            if (freq_used[cnt[i]]) return 0;
            freq_used[cnt[i]] = 1;
        }
    }
    return distinct_letters >= 2;
}

int main(void) {

    int ok = solve_uva12820("ada") && !solve_uva12820("aa");
    printf("%s: UVa 12820 - Cool Word\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
