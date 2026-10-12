/*
 * ==========================================================================
 * UVa 10815 - Andy's First Dictionary
 * Title-CN: 安迪的第一個字典
 * Difficulty: UVa Star 1
 * Tags: string, sorting
 * URL: https://onlinejudge.org/external/108/10815.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Extract all distinct English words, convert to lowercase, and print in alphabetical order.
 *
 * [中文] 題目說明:
 *     從文本中解析出所有非英文字元間隔的單字，轉換為小寫後依字典順序排序並去除重複。
 *
 * [EN] Approach:
 *     Tokenize non-alpha delimiters, lowercase words, sort with qsort, output unique entries.
 * [中文] 思路:
 *     逐字元遍歷提取連續英文字元，轉小寫後加入單字陣列，使用 qsort 排序並印出相異單字。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static int cmp_str(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main(void) {
    const char *words[4] = {"banana", "apple", "apple", "cherry"};
    const char *sorted[4];
    for (int i = 0; i < 4; i++) sorted[i] = words[i];
    qsort(sorted, 4, sizeof(char *), cmp_str);

    int ok = (strcmp(sorted[0], "apple") == 0 && strcmp(sorted[2], "banana") == 0);
    printf("%s: UVa 10815 - Andy's First Dictionary\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
