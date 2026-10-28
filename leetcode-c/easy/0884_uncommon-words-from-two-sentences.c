/*
 * LeetCode 0884. Uncommon Words from Two Sentences《兩句話中的不常見單字》
 * 難度：Easy；標籤：雜湊表、字串
 * 題目連結：https://leetcode.com/problems/uncommon-words-from-two-sentences/
 *
 * 題目說明：
 * 句子由小寫英文單字組成，單字之間以一個空格隔開。若某個單字在兩句合併後
 * 恰好只出現一次，它就是不常見單字。給定 s1 和 s2，回傳所有不常見單字；
 * 回傳順序不限。回傳的字串陣列及其中每個字串都由 malloc 配置，呼叫端負責釋放。
 *
 * 範例：
 * 1. s1 = "this apple is sweet"，s2 = "this apple is sour"，回傳 ["sweet","sour"]。
 *    this 和 apple 都出現兩次；sweet 與 sour 各出現一次。
 * 2. s1 = "apple apple"，s2 = "banana"，回傳 ["banana"]。
 *
 * 限制：
 * - 1 <= s1.length, s2.length <= 200。
 * - 句子只含小寫英文字母和空格，沒有開頭或結尾空格。
 * - 所有單字之間恰好有一個空格。
 *
 * 解題思路：
 * 1. 依空格拆出兩句中的每個單字，放入同一份計數表。
 * 2. 每看到一個單字，就在表中找到它並增加次數；若尚未出現就新增一筆。
 * 3. 掃描計數表，只複製出現次數恰好為 1 的單字到答案陣列。
 * 4. 釋放計數表暫存；答案字串交由呼叫端釋放。
 *
 * 複雜度：令 L 為兩句總長度、U 為不同單字數。簡單計數表時間 O(L * U)，
 * 最壞 O(L^2)；額外空間 O(L)，不含回傳結果。
 */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *word;
    int count;
} WordCount;

static int findWord(WordCount *table, int size, const char *word) {
    int i;
    for (i = 0; i < size; ++i) {
        if (strcmp(table[i].word, word) == 0) return i;
    }
    return -1;
}

static void countSentenceWords(const char *sentence, WordCount *table, int *size) {
    const char *start = sentence;
    const char *cursor = sentence;

    while (1) {
        if (*cursor == ' ' || *cursor == '\0') {
            size_t length = (size_t)(cursor - start);
            char *word = (char*)malloc(length + 1);
            int index;

            memcpy(word, start, length);
            word[length] = '\0';
            index = findWord(table, *size, word);
            if (index >= 0) {
                table[index].count++;
                free(word);
            } else {
                table[*size].word = word;
                table[*size].count = 1;
                (*size)++;
            }

            if (*cursor == '\0') break;
            start = cursor + 1;
        }
        cursor++;
    }
}

static char *copyWord(const char *word) {
    size_t length = strlen(word);
    char *copy = (char*)malloc(length + 1);
    memcpy(copy, word, length + 1);
    return copy;
}

char** uncommonFromSentences(char* s1, char* s2, int* returnSize) {
    int capacity = (int)strlen(s1) + (int)strlen(s2) + 2;
    WordCount *table = (WordCount*)calloc((size_t)capacity, sizeof(WordCount));
    char **result;
    int tableSize = 0;
    int resultCount = 0;
    int i;

    countSentenceWords(s1, table, &tableSize);
    countSentenceWords(s2, table, &tableSize);

    result = (char**)malloc(sizeof(char*) * (size_t)(tableSize > 0 ? tableSize : 1));
    for (i = 0; i < tableSize; ++i) {
        if (table[i].count == 1) result[resultCount++] = copyWord(table[i].word);
        free(table[i].word);
    }
    free(table);
    *returnSize = resultCount;
    return result;
}

static int containsWord(char **words, int size, const char *target) {
    int i;
    for (i = 0; i < size; ++i) {
        if (strcmp(words[i], target) == 0) return 1;
    }
    return 0;
}

static void freeWords(char **words, int size) {
    int i;
    for (i = 0; i < size; ++i) free(words[i]);
    free(words);
}

int main(void) {
    char sentence1[] = "this apple is sweet";
    char sentence2[] = "this apple is sour";
    char sentence3[] = "apple apple";
    char sentence4[] = "banana";
    char **answer;
    int answerSize;

    answer = uncommonFromSentences(sentence1, sentence2, &answerSize);
    assert(answerSize == 2);
    assert(containsWord(answer, answerSize, "sweet"));
    assert(containsWord(answer, answerSize, "sour"));
    freeWords(answer, answerSize);

    answer = uncommonFromSentences(sentence3, sentence4, &answerSize);
    assert(answerSize == 1 && strcmp(answer[0], "banana") == 0);
    freeWords(answer, answerSize);

    puts("PASS 0884 uncommonFromSentences");
    return 0;
}
