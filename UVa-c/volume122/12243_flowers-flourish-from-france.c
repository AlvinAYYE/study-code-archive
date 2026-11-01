/*
 * ==========================================================================
 * UVa 12243 - Flowers Flourish from France
 * Title-CN: 頭韻全字母吻合檢測
 * Difficulty: Easy
 * Tags: String
 * URL: https://onlinejudge.org/external/122/12243.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine if a sentence is a tautogram (every word starts with the same letter, case-insensitive).
 *
 * [中文] 題目說明:
 *     判斷給定的句子是否為全頭韻句（每個單詞的首字母不分大小寫完全相同）。
 *
 * [EN] Approach:
 *     Extract the first letter of each word and verify case-insensitively that all initial letters match.
 * [中文] 思路:
 *     提取每個單詞的第一個字母轉為小寫，檢查全句所有單詞首字母是否皆與第一個單詞一致。
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

bool is_tautogram(const char *s) {
    char target = '\0';
    for (int i = 0; s[i]; i++) {
        if (s[i] != ' ' && (i == 0 || s[i - 1] == ' ')) {
            char c = tolower((unsigned char)s[i]);
            if (target == '\0') target = c;
            else if (c != target) return false;
        }
    }
    return true;
}

int main(void) {

    int ok = is_tautogram("Flowers Flourish from France") && !is_tautogram("Sam walked slowly down the street");
    printf("%s: UVa 12243 - Flowers Flourish from France\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
