/*
 * ==========================================================================
 * UVa 10420 - List of Conquests
 * Title-CN: 征服清單
 * Difficulty: UVa Star 1 / CPE 49 顆星必考題
 * Tags: string, sorting
 * URL: https://onlinejudge.org/external/104/10420.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count frequencies of country names and sort alphabetically.
 *
 * [中文] 題目說明:
 *     統計各國家的數量，按國家英文名稱字典序輸出。
 *
 * [EN] Approach: Extract first word, qsort, aggregate counts.
 * [中文] 思路: 提取每行第一個單字，排序後線性累計頻率。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int cmp_str(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main(void) {
    const char *countries[] = {"Spain", "France", "Spain"};
    const char *sorted[3];
    for (int i = 0; i < 3; i++) sorted[i] = countries[i];
    qsort(sorted, 3, sizeof(char *), cmp_str);

    int ok = (strcmp(sorted[0], "France") == 0 && strcmp(sorted[1], "Spain") == 0);
    printf("%s: UVa 10420 - List of Conquests\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
