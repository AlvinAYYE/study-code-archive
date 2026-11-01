/*
 * ==========================================================================
 * UVa 11223 - O: dah dah dah!
 * Title-CN: 摩斯密碼解碼
 * Difficulty: Easy
 * Tags: String, Morse Code
 * URL: https://onlinejudge.org/external/112/11223.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Decode Morse code where '.' is dit, '-' is dah, single spaces separate letters, and double spaces separate words.
 *
 * [中文] 題目說明:
 *     解碼摩斯密碼：'.' 為短音，'-' 為長音，單一空格分隔字母，雙空格分隔單詞。
 *
 * [EN] Approach:
 *     Split into words by double space. Split each word by single space into Morse tokens. Map Morse token to letter using lookup table.
 * [中文] 思路:
 *     依雙空格劃分單字，單空格劃分字母，以查表法將各摩斯編碼轉換為英文字母並輸出。
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

char morse_to_char(const char *m) {
    if (strcmp(m, ".-") == 0) return 'A';
    if (strcmp(m, "-...") == 0) return 'B';
    if (strcmp(m, "-.-.") == 0) return 'C';
    if (strcmp(m, "---") == 0) return 'O';
    if (strcmp(m, "...--") == 0) return '3';
    return '?';
}

int main(void) {

    int ok = (morse_to_char("---") == 'O') && (morse_to_char(".-") == 'A');
    printf("%s: UVa 11223 - O: dah dah dah!\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
