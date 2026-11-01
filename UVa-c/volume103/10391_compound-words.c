/*
 * ==========================================================================
 * UVa 10391 - Compound Words
 * Title-CN: 複合詞字典拆分快速比對
 * Difficulty: UVa Star 2
 * Tags: string, hash, sorting
 * URL: https://onlinejudge.org/external/103/10391.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find all compound words in a sorted dictionary that are formed by concatenating exactly two other words in the dictionary.
 *
 * [中文] 題目概述:
 *     在已排序的英文字典中，找出所有能恰好由字典內另外兩個單詞直接拼接而成的複合單詞。
 *
 * [EN] Approach:
 *     For each word, split at all possible split positions into prefix and suffix. Check if both prefix and suffix exist in hash table / sorted list.
 * [中文] 解題思路:
 *     逐一走訪字典單詞，窮舉每個分割點將單詞拆為前後兩半，二分搜尋檢驗前後兩半是否均為字典中的獨立單詞。
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

int check_compound(const char *word, int n_dict, char dict[][20]) {
    int len = strlen(word);
    for (int split = 1; split < len; split++) {
        char p[20], s[20];
        strncpy(p, word, split); p[split] = '\0';
        strcpy(s, word + split);
        int has_p = 0, has_s = 0;
        for (int i = 0; i < n_dict; i++) {
            if (strcmp(dict[i], p) == 0) has_p = 1;
            if (strcmp(dict[i], s) == 0) has_s = 1;
        }
        if (has_p && has_s) return 1;
    }
    return 0;
}

int main(void) {

    char d[3][20] = {"a", "alien", "lien"};
    int ok = check_compound("alien", 3, d); // "a" + "lien"
    printf("%s: UVa 10391 - Compound Words\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
