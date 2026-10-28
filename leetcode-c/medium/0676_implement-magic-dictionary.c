/*
 * Title-CN: 實作魔法字典
 * LeetCode 676. Implement Magic Dictionary
 *
 * 題意翻譯：設計字典，可先加入一批單字，再查詢某個單字是否能只替換一個字母，
 * 變成字典中的任一單字。必須剛好替換一個字母；完全相同不算。
 *
 * 範例：字典含 "hello" 時，查詢 "hhllo" 回傳 true；查詢 "hello" 回傳 false。
 *
 * 限制：字典單字數不超過 100；每個單字長度不超過 100；只含小寫英文字母。
 *
 * 解題思路：保存字典單字。查詢時只比較長度相同的單字，逐字計算不同位置數；
 * 若恰好有一個位置不同，就找到符合條件的單字。比較時超過一個差異即可停止。
 *
 * 複雜度：建字典 O(W)；每次查詢 O(D*L)，D 為單字數、L 為單字長度；空間 O(W)。
 * LeetCode 介面：保留 MagicDictionary 操作與 magicDictionaryFree；main() 僅供本機測試。
 */

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **words;
    int count;
} MagicDictionary;

MagicDictionary *magicDictionaryCreate(void) {
    return calloc(1, sizeof(MagicDictionary));
}

static char *duplicateString(const char *source) {
    size_t length = strlen(source);
    char *copy = malloc(length + 1);
    if (copy != NULL) memcpy(copy, source, length + 1);
    return copy;
}

void magicDictionaryBuildDict(MagicDictionary *obj, char **dictionary, int dictionarySize) {
    for (int i = 0; i < obj->count; ++i) free(obj->words[i]);
    free(obj->words);
    obj->words = dictionarySize == 0 ? NULL : malloc((size_t)dictionarySize * sizeof(*obj->words));
    obj->count = 0;
    if (dictionarySize > 0 && obj->words == NULL) return;

    for (int i = 0; i < dictionarySize; ++i) {
        obj->words[i] = duplicateString(dictionary[i]);
        if (obj->words[i] == NULL) {
            obj->count = i;
            for (int j = 0; j < obj->count; ++j) free(obj->words[j]);
            free(obj->words);
            obj->words = NULL;
            obj->count = 0;
            return;
        }
        ++obj->count;
    }
}

bool magicDictionarySearch(MagicDictionary *obj, char *searchWord) {
    size_t searchLength = strlen(searchWord);
    for (int i = 0; i < obj->count; ++i) {
        if (strlen(obj->words[i]) != searchLength) continue;
        int differences = 0;
        for (size_t j = 0; j < searchLength; ++j) {
            if (obj->words[i][j] != searchWord[j] && ++differences > 1) break;
        }
        if (differences == 1) return true;
    }
    return false;
}

void magicDictionaryFree(MagicDictionary *obj) {
    if (obj == NULL) return;
    for (int i = 0; i < obj->count; ++i) free(obj->words[i]);
    free(obj->words);
    free(obj);
}

int main(void) {
    MagicDictionary *dictionary = magicDictionaryCreate();
    assert(dictionary != NULL);
    char hello[] = "hello";
    char leetcode[] = "leetcode";
    char *words[] = {hello, leetcode};
    magicDictionaryBuildDict(dictionary, words, 2);
    char hhllo[] = "hhllo";
    char exact[] = "hello";
    char shortWord[] = "hell";
    assert(magicDictionarySearch(dictionary, hhllo));
    assert(!magicDictionarySearch(dictionary, exact));
    assert(!magicDictionarySearch(dictionary, shortWord));
    magicDictionaryFree(dictionary);
    return 0;
}
