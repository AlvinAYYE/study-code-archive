/*
 * ==========================================================================
 * UVa 12820 - Cool Word
 * Title-CN: 酷單字檢驗
 * Difficulty: UVa Star 1
 * Tags: string
 * ==========================================================================
 * [EN] Problem: Word is "cool" if >= 2 distinct letters and all letter frequencies are strictly unique.
 * [中文] 題目說明: 單字至少含 2 種不同英文字母，且所有字母的出現頻率各不相同，則為 Cool Word。
 * [EN] Approach: Count letter frequencies, check distinct types >= 2 and unique frequencies using frequency bucket.
 * [中文] 思路: 統計各字母次數，驗證相異字母數 >= 2 且出現次數無重複。
 * ==========================================================================
 */
#include <stdio.h>

int is_cool_word(const char *s) {
    int count[26] = {0};
    for (int i = 0; s[i]; i++) count[s[i] - 'a']++;
    int freq_seen[50] = {0};
    int types = 0;
    for (int i = 0; i < 26; i++) {
        if (count[i] > 0) {
            types++;
            if (freq_seen[count[i]]) return 0;
            freq_seen[count[i]] = 1;
        }
    }
    return (types >= 2);
}

int main(void) {
    int ok = is_cool_word("ada") && !is_cool_word("aa") && !is_cool_word("abba");
    printf("%s: UVa 12820 - Cool Word\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
