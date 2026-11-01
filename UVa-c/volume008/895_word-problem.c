/*
 * ==========================================================================
 * UVa 895 - Word Problem
 * Title-CN: 猜單字遊戲 (字母子集包含計數)
 * Difficulty: Easy
 * Tags: String, Frequency Count
 * URL: https://onlinejudge.org/external/8/895.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given a dictionary of words and puzzles consisting of available letters, count how many dictionary words can be formed using the puzzle letters.
 *
 * [中文] 題目說明:
 *     給定字典，對每個由可用字母組成的謎題行，求字典中有多少個單字能完全由該行字母拼成（每字母使用次數不超過提供數）。
 *
 * [EN] Approach:
 *     Count letter frequencies for each dictionary word (26 ints). For each query, count query frequencies and test if word_freq[c] <= query_freq[c] for all c.
 * [中文] 思路:
 *     統計字典各單字的 26 個字母出現頻率，對每個詢問檢查單字所需各字母數量是否皆小於等於詢問給予的字母數量。
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

int count_formable_words(int dict_cnt, const char dict[][15], const char *puzzle) {
    int p_freq[26] = {0};
    for (int i = 0; puzzle[i]; i++) {
        if (puzzle[i] >= 'a' && puzzle[i] <= 'z') p_freq[puzzle[i] - 'a']++;
    }
    int formable = 0;
    for (int i = 0; i < dict_cnt; i++) {
        int w_freq[26] = {0};
        for (int j = 0; dict[i][j]; j++) w_freq[dict[i][j] - 'a']++;
        bool ok = true;
        for (int c = 0; c < 26; c++) {
            if (w_freq[c] > p_freq[c]) { ok = false; break; }
        }
        if (ok) formable++;
    }
    return formable;
}

int main(void) {

    char dict[3][15] = {"and", "ant", "cat"};
    int cnt = count_formable_words(3, dict, "a d n t"); // "and", "ant" formable, not "cat"
    int ok = (cnt == 2);
    printf("%s: UVa 895 - Word Problem\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
