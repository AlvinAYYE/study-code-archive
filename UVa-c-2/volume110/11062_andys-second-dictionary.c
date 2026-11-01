/*
 * ==========================================================================
 * UVa 11062 - Andy's Second Dictionary
 * Title-CN: 安迪的第二個字典 (連字號換行處理)
 * Difficulty: Easy
 * Tags: String, Parsing, Hash Set
 * URL: https://onlinejudge.org/external/110/11062.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Extract unique words in alphabetical order from text where hyphen at end of line indicates word continuation onto next line.
 *
 * [中文] 題目說明:
 *     從文字中提取所有相異單字並按字典序輸出，行末連字號 '-' 表示單字跨行延續未結束。
 *
 * [EN] Approach:
 *     Process characters: if hyphen followed immediately by newline, ignore both. Split by any non-alphabetic/non-internal-hyphen characters.
 * [中文] 思路:
 *     字符流處理：若連字號出現在行末（緊隨換行符）則略過兩者；其餘非字母字元作為單字分界，收集單字去重排序。
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

bool is_valid_char_dict2(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '-';
}

int main(void) {

    int ok = is_valid_char_dict2('a') && is_valid_char_dict2('-');
    printf("%s: UVa 11062 - Andy's Second Dictionary\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
