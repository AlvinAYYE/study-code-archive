/*
 * ==========================================================================
 * UVa 10029 - Edit Step Ladders
 * Title-CN: 編輯距離階梯
 * Difficulty: UVa Star 3
 * Tags: dynamic-programming, string
 * URL: https://onlinejudge.org/external/100/10029.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find longest sequence of words where each word is formed from the previous by 1 edit operation
 *     and words are in lexicographical order.
 *
 * [中文] 題目說明:
 *     求最長單字階梯長度。階梯中後一個單字比前一個單字字典序大，且編輯距離恰為 1（增、刪、改單一字元）。
 *
 * [EN] Approach: DP with hash table or binary search lookup on preceding words.
 * [中文] 思路: 動態規劃。對當前單字枚舉其前驅可能的變形單字，查詢歷史最大 DP 值轉移。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

static inline int max_val(int a, int b) { return a > b ? a : b; }

#define MAX_WORDS 25000
#define MAX_WORD_LENGTH 16
#define HASH_BUCKETS 65537

typedef struct {
    char word[MAX_WORD_LENGTH + 1];
    int ladder_length;
    int next;
} WordEntry;

typedef struct {
    WordEntry entries[MAX_WORDS];
    int buckets[HASH_BUCKETS];
    int count;
} Dictionary;

static uint32_t hash_word(const char *word) {
    uint32_t hash = 2166136261U;

    while (*word != '\0') {
        hash ^= (unsigned char)*word++;
        hash *= 16777619U;
    }
    return hash;
}

static int find_word(const Dictionary *dictionary, const char *word) {
    unsigned int bucket = hash_word(word) % HASH_BUCKETS;

    for (int index = dictionary->buckets[bucket]; index >= 0;
         index = dictionary->entries[index].next) {
        if (strcmp(dictionary->entries[index].word, word) == 0) {
            return dictionary->entries[index].ladder_length;
        }
    }
    return 0;
}

static void insert_word(Dictionary *dictionary, const char *word, int length) {
    int index = dictionary->count++;
    unsigned int bucket = hash_word(word) % HASH_BUCKETS;

    strcpy(dictionary->entries[index].word, word);
    dictionary->entries[index].ladder_length = length;
    dictionary->entries[index].next = dictionary->buckets[bucket];
    dictionary->buckets[bucket] = index;
}

int solve_uva10029(FILE *input) {
    Dictionary *dictionary = malloc(sizeof(*dictionary));
    char word[MAX_WORD_LENGTH + 3];
    int answer = 0;

    if (dictionary == NULL) {
        return 0;
    }
    dictionary->count = 0;
    for (int i = 0; i < HASH_BUCKETS; ++i) {
        dictionary->buckets[i] = -1;
    }

    while (fgets(word, sizeof(word), input) != NULL) {
        size_t length = strcspn(word, "\r\n");
        char candidate[MAX_WORD_LENGTH + 2];
        int best = 1;

        word[length] = '\0';
        if (length == 0) {
            continue;
        }

        for (size_t position = 0; position < length; ++position) {
            memcpy(candidate, word, position);
            strcpy(candidate + position, word + position + 1);
            best = max_val(best, find_word(dictionary, candidate) + 1);
        }

        strcpy(candidate, word);
        for (size_t position = 0; position < length; ++position) {
            char original = candidate[position];

            for (char letter = 'a'; letter <= 'z'; ++letter) {
                if (letter != original) {
                    candidate[position] = letter;
                    best = max_val(best, find_word(dictionary, candidate) + 1);
                }
            }
            candidate[position] = original;
        }

        for (size_t position = 0; position <= length; ++position) {
            memcpy(candidate, word, position);
            strcpy(candidate + position + 1, word + position);
            for (char letter = 'a'; letter <= 'z'; ++letter) {
                candidate[position] = letter;
                best = max_val(best, find_word(dictionary, candidate) + 1);
            }
        }

        if (dictionary->count < MAX_WORDS) {
            insert_word(dictionary, word, best);
        }
        answer = max_val(answer, best);
    }

    free(dictionary);
    return answer;
}

int main(void) {
    printf("%d\n", solve_uva10029(stdin));
    return 0;
}
