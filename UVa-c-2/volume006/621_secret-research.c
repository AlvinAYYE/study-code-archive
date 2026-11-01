/*
 * ==========================================================================
 * UVa 621 - Secret Research
 * Title-CN: 秘密實驗結果加密模式解密
 * Difficulty: UVa Star 1
 * Tags: string, pattern-matching
 * URL: https://onlinejudge.org/external/6/621.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given encrypted result string, determine encryption type: '+' (positive), '-' (negative), '*' (failed), '?' (not completed).
 *
 * [中文] 題目說明:
 *     根據字串前後綴判斷實驗結果：'1', '4', '78' 判定為 '+'；結尾 '35' 判定為 '-'；開頭 '9' 結尾 '4' 判定為 '*'；開頭 '190' 判定為 '?'。
 *
 * [EN] Approach:
 *     Check string length and prefix/suffix using strcmp and string slicing.
 * [中文] 思路:
 *     字串模式比對：若為 "1", "4", "78" 輸出 '+'；末兩位為 "35" 輸出 '-'；首為 '9' 尾為 '4' 輸出 '*'；其餘為 '?'。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char solve_uva621(const char *s) {
    int len = (int)strlen(s);
    if (strcmp(s, "1") == 0 || strcmp(s, "4") == 0 || strcmp(s, "78") == 0) return '+';
    if (len >= 2 && s[len - 2] == '3' && s[len - 1] == '5') return '-';
    if (len >= 2 && s[0] == '9' && s[len - 1] == '4') return '*';
    return '?';
}

int main(void) {

    int ok = (solve_uva621("78") == '+') && (solve_uva621("135") == '-') && (solve_uva621("924") == '*');
    printf("%s: UVa 621 - Secret Research\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
