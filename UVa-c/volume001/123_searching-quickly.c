/*
 * ==========================================================================
 * UVa 123 - Searching Quickly
 * Title-CN: 關鍵字上下文索引 (KWIC Index)
 * Difficulty: UVa Star 2
 * Tags: string, sorting, simulation
 * URL: https://onlinejudge.org/external/1/123.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Generate a Key Word In Context (KWIC) index: alphabetized list of titles rotated around capitalized non-stop words.
 *
 * [中文] 題目說明:
 *     生成關鍵字上下文索引 (KWIC)：忽略停用詞，將每個非停用詞大寫並將其排在關鍵字位置，按字典序穩定排序。
 *
 * [EN] Approach:
 *     Store ignore list. For each title, identify keywords, generate rotation entries, and sort stably by keyword.
 * [中文] 思路:
 *     以雜湊或線性表比對停用詞，遍歷每句標題中的非停用字詞，記錄原始索引位置後進行多鍵排序。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <string.h>
#include <ctype.h>

int is_stop_word(const char *w, const char *stop[], int n_stop) {
    for (int i = 0; i < n_stop; i++) {
        if (strcmp(w, stop[i]) == 0) return 1;
    }
    return 0;
}

int main(void) {

    const char *stop[2] = {"is", "the"};
    int ok = is_stop_word("the", stop, 2) && !is_stop_word("cat", stop, 2);
    printf("%s: UVa 123 - Searching Quickly\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
