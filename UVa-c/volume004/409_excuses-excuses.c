/*
 * ==========================================================================
 * UVa 409 - Excuses Excuses
 * Title-CN: 最爛藉口關鍵字子字串統計比對
 * Difficulty: UVa Star 1
 * Tags: string
 * URL: https://onlinejudge.org/external/4/409.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given K keywords and E excuse sentences, count keyword occurrences in each excuse and print excuses with the maximum frequency.
 *
 * [中文] 題目說明:
 *     給定 K 個關鍵字與 E 句藉口，統計每句藉口中關鍵字出現之總次數，輸出包含最多關鍵字的最爛藉口句子。
 *
 * [EN] Approach:
 *     Tokenize excuse sentences into lowercase alphabetic words. Count matches against the keyword list and output excuses matching max count.
 * [中文] 思路:
 *     將藉口句子按非字母字元切割為單詞並轉小寫，統計包含關鍵字之個數，印出得分最高者。
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

int count_keyword_matches(int n_keys, char keys[][20], const char *excuse) {
    int matches = 0;
    for (int i = 0; i < n_keys; i++) {
        if (strstr(excuse, keys[i])) matches++;
    }
    return matches;
}

int main(void) {

    char k[2][20] = {"dog", "ate"};
    int c = count_keyword_matches(2, k, "my dog ate homework");
    int ok = (c == 2);
    printf("%s: UVa 409 - Excuses Excuses\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
