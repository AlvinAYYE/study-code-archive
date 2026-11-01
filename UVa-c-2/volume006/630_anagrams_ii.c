/*
 * ==========================================================================
 * UVa 630 - Anagrams (II)
 * Title-CN: 字彙變位詞檢索
 * Difficulty: Easy
 * Tags: String, Sorting, Hash Table
 * URL: https://onlinejudge.org/external/6/630.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given a vocabulary list, find and list all vocabulary words that are anagrams of a given query word.
 *
 * [中文] 題目描述:
 *     給定字彙字典，對於每次查詢單字，輸出字典中所有由相同字母組成的變位詞（保持字典中的出現順序）。
 *
 * [EN] Approach:
 *     Sort characters of words to create signatures or count character frequency distributions to test anagram equivalence.
 *
 * [中文] 解題思維:
 *     統計 26 個英文字母頻率分佈或字母排序簽名，比對查詢單字與字典中單字是否為變位詞。
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

static int is_anagram_630(const char *s1, const char *s2) {
    int cnt[26];
    memset(cnt, 0, sizeof(cnt));
    int len1 = 0, len2 = 0;
    for (; s1[len1]; len1++) cnt[s1[len1] - 'a']++;
    for (; s2[len2]; len2++) cnt[s2[len2] - 'a']--;
    if (len1 != len2) return 0;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] != 0) return 0;
    }
    return 1;
}

int find_anagrams_list(int vocab_size, char vocab[][25], const char *query, int out_indices[]) {
    int count = 0;
    for (int i = 0; i < vocab_size; i++) {
        if (is_anagram_630(vocab[i], query)) {
            out_indices[count++] = i;
        }
    }
    return count;
}

int main(void) {

    char dict[3][25] = {"cat", "dog", "act"};
    int idx[3];
    int count = find_anagrams_list(3, dict, "tac", idx);
    int ok = (count == 2 && idx[0] == 0 && idx[1] == 2);
    printf("%s: UVa 630 - Anagrams (II)\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
