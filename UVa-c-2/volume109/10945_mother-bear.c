/*
 * ==========================================================================
 * UVa 10945 - Mother bear
 * Title-CN: 母熊迴文語句過濾判斷
 * Difficulty: UVa Star 1
 * Tags: string
 * URL: https://onlinejudge.org/external/109/10945.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Check if a given sentence is a palindrome, ignoring case and all non-alphabetical punctuation symbols.
 *
 * [中文] 題目說明:
 *     判斷給定句子是否為迴文，比對時忽略字母大小寫以及所有標點符號與空格。
 *
 * [EN] Approach:
 *     Two pointers from start and end. Advance pointers while current char is not an alphabet. Compare lowercased characters.
 * [中文] 思路:
 *     雙指針分別指向字串頭尾，遇到非英文字母直接跳過，轉換為小寫後逐一比對兩端字元是否相符。
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

int solve_uva10945(const char *s) {
    int i = 0, j = strlen(s) - 1;
    while (i < j) {
        while (i < j && !isalpha(s[i])) i++;
        while (i < j && !isalpha(s[j])) j--;
        if (tolower(s[i]) != tolower(s[j])) return 0;
        i++; j--;
    }
    return 1;
}

int main(void) {

    int ok = solve_uva10945("Madam, I'm Adam.") && !solve_uva10945("Into the wild");
    printf("%s: UVa 10945 - Mother bear\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
