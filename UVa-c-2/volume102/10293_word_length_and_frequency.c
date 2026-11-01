/*
 * ==========================================================================
 * UVa 10293 - Word Length and Frequency
 * Title-CN: 單字長度與出現頻率統計
 * Difficulty: Easy
 * Tags: String, Parsing, Hash Table
 * URL: https://onlinejudge.org/external/102/10293.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count the frequency of each word length in a text, ignoring punctuation except apostrophes and end-of-line hyphens.
 *
 * [中文] 題目描述:
 *     統計文章中各單字長度的出現頻率，單字由英文字母組成，忽略標點符號（單字內的撇號與行尾連字號除外）。
 *
 * [EN] Approach:
 *     Parse text line by line. If line ends with '-', continue word to next line. Filter out punctuation. Record lengths in frequency array.
 *
 * [中文] 解題思維:
 *     逐行解析字元，若以 '-' 結尾則字詞延續至下一行；跳過單字中的撇號與標點符號，將單字長度累加至頻率計數陣列。
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

void count_word_lengths(const char *text, int freq[35]) {
    memset(freq, 0, sizeof(int) * 35);
    int len = 0;
    for (int i = 0; text[i]; i++) {
        char c = text[i];
        if (isalpha(c)) {
            len++;
        } else if (c == '\'' || c == '-') {
            // Internal punctuation, doesn't terminate word
            continue;
        } else {
            if (len > 0 && len < 35) {
                freq[len]++;
                len = 0;
            }
        }
    }
    if (len > 0 && len < 35) freq[len]++;
}

int main(void) {

    int freq[35];
    count_word_lengths("Hello world, don't stop!", freq);
    // "Hello" (5), "world" (5), "dont" (4), "stop" (4)
    int ok = (freq[5] == 2 && freq[4] == 2);
    printf("%s: UVa 10293 - Word Length and Frequency\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
