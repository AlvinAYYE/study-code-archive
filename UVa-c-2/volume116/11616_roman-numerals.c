/*
 * ==========================================================================
 * UVa 11616 - Roman Numerals
 * Title-CN: 羅馬數字與阿拉伯數字雙向轉換
 * Difficulty: Easy
 * Tags: String, Number Base, Simulation
 * URL: https://onlinejudge.org/external/116/11616.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Convert standard Roman numerals (I, V, X, L, C, D, M) to Arabic numbers, and vice versa.
 *
 * [中文] 題目描述:
 *     實現羅馬數字與十進位阿拉伯數字之間的雙向自動辨識與轉換。
 *
 * [EN] Approach:
 *     If input starts with digit: convert int to Roman greedily with subtraction symbols (IV, IX, etc.). If starts with letter: parse Roman to int.
 *
 * [中文] 解題思維:
 *     依首字元判斷：若為數字則貪心構造羅馬字串；若為字母則按羅馬數字符號累計數值（小數在大數前則減去）。
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

int roman_val(char c) {
    switch (c) {
        case 'I': return 1; case 'V': return 5; case 'X': return 10;
        case 'L': return 50; case 'C': return 100; case 'D': return 500;
        case 'M': return 1000; default: return 0;
    }
}
int roman_to_arabic(const char *s) {
    int total = 0, len = strlen(s);
    for (int i = 0; i < len; i++) {
        int v = roman_val(s[i]);
        if (i + 1 < len && v < roman_val(s[i + 1])) total -= v;
        else total += v;
    }
    return total;
}

int main(void) {

    int ok = (roman_to_arabic("III") == 3) && (roman_to_arabic("IV") == 4) && (roman_to_arabic("IX") == 9);
    printf("%s: UVa 11616 - Roman Numerals\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
