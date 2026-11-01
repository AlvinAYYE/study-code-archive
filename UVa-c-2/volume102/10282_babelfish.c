/*
 * ==========================================================================
 * UVa 10282 - Babelfish
 * Title-CN: 巴別魚字典
 * Difficulty: UVa Star 1
 * Tags: hash-table, string, sorting
 * URL: https://onlinejudge.org/external/102/10282.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given foreign-to-English dictionary entries, translate queried foreign words. Output "eh" if not found.
 *
 * [中文] 題目說明:
 *     輸入外語對應英文的字典清單。針對後續查詢的外語單字，印出英文單字；若不存在則輸出 "eh"。
 *
 * [EN] Approach: Sort dictionary by foreign word, use binary search (bsearch).
 * [中文] 思路: 結構體儲存單字對，按外語單字 qsort 後，以二分搜尋 (bsearch) 高效查詢。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char eng[15];
    char fgn[15];
} DictEntry;

static int cmp_entry(const void *a, const void *b) {
    return strcmp(((const DictEntry *)a)->fgn, ((const DictEntry *)b)->fgn);
}

const char *lookup_word(int n, DictEntry *dict, const char *foreign) {
    DictEntry key;
    strcpy(key.fgn, foreign);
    DictEntry *res = (DictEntry *)bsearch(&key, dict, (size_t)n, sizeof(DictEntry), cmp_entry);
    return res ? res->eng : "eh";
}

int main(void) {
    DictEntry dict[3] = {
        {"dog", "ogday"},
        {"cat", "atcay"},
        {"pig", "igpay"}
    };
    qsort(dict, 3, sizeof(DictEntry), cmp_entry);

    int ok1 = (strcmp(lookup_word(3, dict, "atcay"), "cat") == 0);
    int ok2 = (strcmp(lookup_word(3, dict, "unknown"), "eh") == 0);
    int ok = ok1 && ok2;
    printf("%s: UVa 10282 - Babelfish\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
