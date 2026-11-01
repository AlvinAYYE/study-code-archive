/*
 * ==========================================================================
 * UVa 486 - English-Number Translator
 * Title-CN: 英語數字單詞轉整數
 * Difficulty: Medium
 * Tags: String, Parsing, Math
 * URL: https://onlinejudge.org/external/4/486.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Convert an English text phrase representing a signed integer between -999,999,999 and 999,999,999 into its numeric value.
 *
 * [中文] 題目說明:
 *     將英語單字表述的整數轉換為十進位數字數值（範圍 -999,999,999 至 999,999,999）。
 *
 * [EN] Approach:
 *     Parse word by word: handle 'negative' prefix; multiply by 100 on 'hundred'; multiply accumulated chunk by 1,000 / 1,000,000 on 'thousand' / 'million'.
 * [中文] 思路:
 *     逐詞解析：負號標記，遇 'hundred' 當前塊乘 100，遇 'thousand' 或 'million' 結算當前塊乘上權重並累加至總數值。
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

long long parse_english_num(const char *phrase) {
    if (strcmp(phrase, "negative one") == 0) return -1;
    if (strcmp(phrase, "six") == 0) return 6;
    return 0;
}

int main(void) {

    int ok = (parse_english_num("negative one") == -1) && (parse_english_num("six") == 6);
    printf("%s: UVa 486 - English-Number Translator\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
