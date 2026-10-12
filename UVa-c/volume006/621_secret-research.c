/*
 * ==========================================================================
 * UVa 621 - Secret Research
 * Title-CN: 秘密實驗結果加密辨識
 * Difficulty: UVa Star 1
 * Tags: string
 * ==========================================================================
 * [EN] Problem: Match string pattern to identify status (+, -, *, ?).
 * [中文] 題目說明: 判斷字串後綴或前後綴：為 1, 4, 78 輸出 +；以 35 結尾輸出 -；1 開頭 4 結尾輸出 *；9 開頭 4 結尾輸出 ?。
 * [EN] Approach: Pattern matching on length and ends.
 * [中文] 思路: 根據長度與首尾字元判斷所屬分類。
 * ==========================================================================
 */
#include <stdio.h>
#include <string.h>

char solve_uva621(const char *s) {
    int len = (int)strlen(s);
    if (strcmp(s, "1") == 0 || strcmp(s, "4") == 0 || strcmp(s, "78") == 0) return '+';
    if (len >= 2 && s[len - 2] == '3' && s[len - 1] == '5') return '-';
    if (len >= 2 && s[0] == '9' && s[len - 1] == '4') return '*';
    return '?';
}

int main(void) {
    int ok = (solve_uva621("78") == '+') && (solve_uva621("135") == '-');
    printf("%s: UVa 621 - Secret Research\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
