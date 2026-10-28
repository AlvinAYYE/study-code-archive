/*
 * LeetCode 745. Prefix and Suffix Search
 * 題意（繁體中文）：設計 WordFilter，建立時收到一組單字；查詢給定前綴 pref
 * 與後綴 suff，回傳同時符合兩者的單字索引中最大者，沒有符合者回傳 -1。
 *
 * 範例：建立 words=["apple"]；查詢 f("a","e") -> 0。
 * 限制：單字最多 10000 個；每個單字、前綴與後綴長度最多 7，且只含小寫字母；
 *       查詢最多 10000 次。
 * 解法：建立雜湊表，對每個單字枚舉所有非空前綴和非空後綴，
 *       把「前綴#後綴」當作鍵，儲存該鍵最大的單字索引。查詢時組出同一個鍵，
 *       在雜湊表中找出索引即可。建立時由小索引往大索引寫入，自然保留最大值。
 * 複雜度：建立時間 O(單字數 * L^2)，每次查詢平均 O(L)，空間 O(單字數 * L^2)，L<=7。
 * LeetCode C API：wordFilterCreate、wordFilterF、wordFilterFree。
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char key[16];
    int index;
    unsigned char used;
} PairEntry;

typedef struct {
    PairEntry *entries;
    size_t capacity;
} WordFilter;

static uint64_t hashKey(const char *key) {
    uint64_t hash = UINT64_C(1469598103934665603);
    for (int i = 0; key[i] != '\0'; ++i) {
        hash ^= (unsigned char)key[i];
        hash *= UINT64_C(1099511628211);
    }
    return hash;
}

static void makeKey(char *key, const char *prefix, int prefixLength,
                    const char *word, int suffixLength) {
    int at = 0;
    memcpy(key + at, prefix, (size_t)prefixLength);
    at += prefixLength;
    key[at++] = '#';
    memcpy(key + at, word + strlen(word) - suffixLength, (size_t)suffixLength);
    at += suffixLength;
    key[at] = '\0';
}

WordFilter* wordFilterCreate(char** words, int wordsSize) {
    WordFilter *obj = (WordFilter *)calloc(1, sizeof *obj);
    if (obj == NULL) return NULL;
    size_t maxPairs = 0;
    for (int i = 0; i < wordsSize; ++i) {
        size_t length = strlen(words[i]);
        maxPairs += length * length;
    }
    obj->capacity = 16;
    while (obj->capacity < maxPairs * 2 + 1) obj->capacity *= 2;
    obj->entries = (PairEntry *)calloc(obj->capacity, sizeof *obj->entries);
    if (obj->entries == NULL) {
        free(obj);
        return NULL;
    }

    for (int wordIndex = 0; wordIndex < wordsSize; ++wordIndex) {
        int length = (int)strlen(words[wordIndex]);
        for (int prefixLength = 1; prefixLength <= length; ++prefixLength) {
            for (int suffixLength = 1; suffixLength <= length; ++suffixLength) {
                char key[16];
                makeKey(key, words[wordIndex], prefixLength,
                        words[wordIndex], suffixLength);
                size_t slot = (size_t)hashKey(key) & (obj->capacity - 1);
                while (obj->entries[slot].used &&
                       strcmp(obj->entries[slot].key, key) != 0)
                    slot = (slot + 1) & (obj->capacity - 1);
                if (!obj->entries[slot].used) {
                    obj->entries[slot].used = 1;
                    strcpy(obj->entries[slot].key, key);
                }
                obj->entries[slot].index = wordIndex;
            }
        }
    }
    return obj;
}

int wordFilterF(WordFilter* obj, char* pref, char* suff) {
    if (obj == NULL || pref == NULL || suff == NULL) return -1;
    char key[16];
    int prefixLength = (int)strlen(pref);
    int suffixLength = (int)strlen(suff);
    int at = 0;
    memcpy(key + at, pref, (size_t)prefixLength);
    at += prefixLength;
    key[at++] = '#';
    memcpy(key + at, suff, (size_t)suffixLength);
    at += suffixLength;
    key[at] = '\0';

    size_t slot = (size_t)hashKey(key) & (obj->capacity - 1);
    while (obj->entries[slot].used) {
        if (strcmp(obj->entries[slot].key, key) == 0)
            return obj->entries[slot].index;
        slot = (slot + 1) & (obj->capacity - 1);
    }
    return -1;
}

void wordFilterFree(WordFilter* obj) {
    if (obj == NULL) return;
    free(obj->entries);
    free(obj);
}

int main(void) {
    char *words[] = {"apple", "apply", "maple"};
    WordFilter *filter = wordFilterCreate(words, 3);
    if (filter == NULL) return 1;
    int passed = wordFilterF(filter, "a", "e") == 0 &&
                 wordFilterF(filter, "app", "ly") == 1 &&
                 wordFilterF(filter, "map", "le") == 2 &&
                 wordFilterF(filter, "b", "e") == -1;
    wordFilterFree(filter);
    puts(passed ? "PASS: 745 prefix-and-suffix-search"
                : "FAIL: 745 prefix-and-suffix-search");
    return passed ? 0 : 1;
}
