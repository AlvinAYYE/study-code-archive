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
 * [中文] 題目說明
 *     給定字串陣列 strs，將互為字母異位詞的字串分在同一組後回傳。
 *     字母異位詞由相同字母以不同順序排列而成；答案與各組的順序不限。
 *
 * [中文] 範例
 *   範例 1：
 *     輸入：strs = ["eat","tea","tan","ate","nat","bat"]
 *     輸出：[["bat"],["nat","tan"],["ate","eat","tea"]]
 *     說明："eat"、"tea"、"ate" 使用相同字母；"tan"、"nat" 也是一組。
 *   範例 2：
 *     輸入：strs = [""]
 *     輸出：[[""]]
 *   範例 3：
 *     輸入：strs = ["a"]
 *     輸出：[["a"]]
 *
 * [中文] 限制
 *   - 1 <= strs.length <= 10^4。
 *   - 0 <= strs[i].length <= 100。
 *   - strs[i] 只包含小寫英文字母。
 *
 * LeetCode official C stub (函式簽名):
 *   char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
 *   }
 *
 * [中文] 直觀解題思路
 *   1. 把每個字串的字母排序成 key；異位詞一定會得到相同 key。
 *   2. 將 (key, 原字串) 記錄依 key 排序，使相同 key 的記錄連續出現。
 *   3. 掃描排序後記錄；每遇到新 key 就建立新組，否則加入目前組。
 *   若最長字串長度為 k，時間複雜度 O(n * k log k + n log n)，輸出外空間 O(n * k)。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ---------- LeetCode submission / 提交區 ---------- */
static int cmpch(const void *a, const void *b) { return *(const char *)a - *(const char *)b; }

typedef struct {
    char *key;
    char *word;
} AnagramItem;

static int cmpItem(const void *a, const void *b) {
    const AnagramItem *x = (const AnagramItem *)a;
    const AnagramItem *y = (const AnagramItem *)b;
    return strcmp(x->key, y->key);
}

char ***groupAnagrams(char **strs, int strsSize, int *returnSize, int **returnColumnSizes) {
    AnagramItem *items = (AnagramItem *)malloc((size_t)strsSize * sizeof(AnagramItem));
    char ***out;
    int *cols;
    int i, groups = 0;

    for (i = 0; i < strsSize; ++i) {
        size_t len = strlen(strs[i]);
        items[i].key = (char *)malloc(len + 1);
        memcpy(items[i].key, strs[i], len + 1);
        qsort(items[i].key, len, sizeof(char), cmpch);
        items[i].word = strs[i];
    }
    qsort(items, (size_t)strsSize, sizeof(AnagramItem), cmpItem);

    /* 第一趟先計算群組數，才能配置 LeetCode 要求的回傳陣列。 */
    for (i = 0; i < strsSize; ++i) {
        if (i == 0 || strcmp(items[i].key, items[i - 1].key) != 0) groups++;
    }

    out = (char ***)malloc((size_t)groups * sizeof(char **));
    cols = (int *)calloc((size_t)groups, sizeof(int));
    groups = 0;
    for (i = 0; i < strsSize; ) {
        int start = i, j;
        while (i < strsSize && strcmp(items[i].key, items[start].key) == 0) i++;
        cols[groups] = i - start;
        out[groups] = (char **)malloc((size_t)cols[groups] * sizeof(char *));
        for (j = start; j < i; ++j) out[groups][j - start] = items[j].word;
        groups++;
    }

    for (i = 0; i < strsSize; ++i) free(items[i].key);
    free(items);
    *returnSize = groups;
    *returnColumnSizes = cols;
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
