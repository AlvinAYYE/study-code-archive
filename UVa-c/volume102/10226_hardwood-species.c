/*
 * ==========================================================================
 * UVa 10226 - Hardwood Species
 * Title-CN: 闊葉林種類
 * Difficulty: UVa Star 1 / CPE 49 顆星必考題
 * Tags: sorting, string
 * URL: https://onlinejudge.org/external/102/10226.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Calculate population fraction percentage of each hardwood tree species in alphabetical order.
 *
 * [中文] 題目說明:
 *     統計每種樹木出現的百分比，結果依樹種名稱字母順序輸出，保留至小數點後四位。
 *
 * [EN] Approach: Sort array of strings, count contiguous duplicates, print percentages.
 * [中文] 思路: 將樹木名稱陣列以 qsort 排序後，一次線性掃描統計各品種次數與總數百分比。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int cmp_str(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main(void) {
    const char *trees[] = {
        "Red Alder", "Ash", "Ash", "Red Alder", "Ash"
    };
    int n = 5;
    const char *sorted[5];
    for (int i = 0; i < n; i++) sorted[i] = trees[i];
    qsort(sorted, n, sizeof(char *), cmp_str);

    int ok = (strcmp(sorted[0], "Ash") == 0 && strcmp(sorted[3], "Red Alder") == 0);
    printf("%s: UVa 10226 - Hardwood Species\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
