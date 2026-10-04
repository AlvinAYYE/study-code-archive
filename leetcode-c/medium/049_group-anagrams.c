/*
 * ==========================================================================
 * LeetCode 049. Group Anagrams
 * Title-CN: 字母異位詞分組
 * Difficulty: Medium
 * Tags: array, hash-table, string, sorting
 * URL: https://leetcode.com/problems/group-anagrams/
 * ==========================================================================
 * [EN] Problem (official statement, source: github mcaupybugs/leetcode-problems-db)
 *     Given an array of strings strs, group the anagrams together. You can
 *     return the answer in any order.
 *
 * [中文] 題目說明 (翻譯自官方英文題面)
 *     把互為字母異位詞的字串分到同一群。
 *
 * Examples:
 *   Example 1:
 *     Input: strs = ["eat","tea","tan","ate","nat","bat"]
 *     Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
 *     Explanation:
 *   Example 2:
 *     Input: strs = [""]
 *     Output: [[""]]
 *   Example 3:
 *     Input: strs = ["a"]
 *     Output: [["a"]]
 *
 * Constraints:
 *   - 1 <= strs.length <= 10^4
 *   - 0 <= strs[i].length <= 100
 *   - strs[i] consists of lowercase English letters.
 *
 * LeetCode official C stub (函式簽名):
 *   char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
 *   }
 *
 * [EN] Approach: Canonical key = sorted letters; hash map groups by key (here: open addressing with string keys). Time O(n*k log k).
 * [中文] 思路: 以「排序後的字母」當標準鍵，用雜湊表按鍵分群。時間 O(n·k log k)。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ---------- LeetCode submission / 提交區 ---------- */
static int cmpch(const void *a, const void *b) { return *(const char *)a - *(const char *)b; }

static unsigned strhash(const char *s) {
    unsigned h = 2166136261U;
    for (; *s; ++s) { h ^= (unsigned char)*s; h *= 16777619U; }
    return h;
}

char ***groupAnagrams(char **strs, int strsSize, int *returnSize, int **returnColumnSizes) {
    int cap = 4, i, gcnt = 0;
    char **keys; int *gids, *slotUsed;
    char ***out; int *cols, *cursor;
    int *id, *cntPerG;
    while (cap < strsSize * 2) cap <<= 1;
    keys      = (char **)calloc((size_t)cap, sizeof(char *));
    gids      = (int *)calloc((size_t)cap, sizeof(int));
    slotUsed  = (int *)calloc((size_t)cap, sizeof(int));
    id        = (int *)malloc((size_t)strsSize * sizeof(int));  /* group id per word */
    cntPerG   = (int *)calloc((size_t)strsSize, sizeof(int));
    for (i = 0; i < strsSize; ++i) {
        size_t L = strlen(strs[i]);
        char *key = (char *)malloc(L + 1);
        int h;
        memcpy(key, strs[i], L + 1);
        qsort(key, L, 1, cmpch);
        h = (int)(strhash(key) & (unsigned)(cap - 1));
        while (slotUsed[h] && strcmp(keys[h], key) != 0) h = (h + 1) & (cap - 1);
        if (!slotUsed[h]) { slotUsed[h] = 1; keys[h] = key; gids[h] = gcnt++; }
        else free(key);
        id[i] = gids[h];
        cntPerG[id[i]]++;
    }
    out     = (char ***)malloc((size_t)gcnt * sizeof(char **));
    cols    = (int *)malloc((size_t)gcnt * sizeof(int));
    cursor  = (int *)calloc((size_t)gcnt, sizeof(int));
    for (i = 0; i < gcnt; ++i) {
        out[i]  = (char **)malloc((size_t)cntPerG[i] * sizeof(char *));
        cols[i] = cntPerG[i];
    }
    for (i = 0; i < strsSize; ++i) {
        size_t L = strlen(strs[i]);
        char *cp = (char *)malloc(L + 1);
        memcpy(cp, strs[i], L + 1);
        out[id[i]][cursor[id[i]]++] = cp;
    }
    *returnSize = gcnt;
    *returnColumnSizes = cols;
    for (i = 0; i < cap; ++i) if (slotUsed[i]) free(keys[i]);
    free(keys); free(gids); free(slotUsed); free(cursor);
    return out;
}
/* ---------- end submission ---------- */

static int isAnagram(const char *a, const char *b) {
    int c[256] = {0}, i;
    if (strlen(a) != strlen(b)) return 0;
    for (i = 0; a[i]; ++i) { c[(unsigned char)a[i]]++; c[(unsigned char)b[i]]--; }
    for (i = 0; i < 256; ++i) if (c[i]) return 0;
    return 1;
}

int main(void) {
    int ok = 1, rs = 0; int *cols = NULL; int i, j, total;
    char *strs[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    char ***out = groupAnagrams(strs, 6, &rs, &cols);
    total = 0; for (i = 0; i < rs; ++i) total += cols[i];
    ok = ok && total == 6 && rs == 3;
    /* every pair inside a group must be anagrams, and every word appears once */
    for (i = 0; i < rs && ok; ++i) {
        for (j = 1; j < cols[i]; ++j)
            if (!isAnagram(out[i][0], out[i][j])) { printf("  fail: group %d not anagram\n", i); ok = 0; }
    }
    for (i = 0; i < 6; ++i) {
        int found = 0;
        for (j = 0; j < rs && !found; ++j) { int k; for (k = 0; k < cols[j]; ++k) if (strcmp(out[j][k], strs[i]) == 0) found = 1; }
        if (!found) { printf("  fail: word %s lost\n", strs[i]); ok = 0; }
    }
    printf("%s: 049 group-anagrams\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
