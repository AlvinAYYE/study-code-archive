/*
 * LeetCode 0819. Most Common Word《最常見的單字》
 * 難度：Easy；標籤：字串、雜湊表、計數
 * 題目連結：https://leetcode.com/problems/most-common-word/
 *
 * 題目說明：
 * 給定一段英文 paragraph 和禁用字陣列 banned，回傳 paragraph 中出現次數最多、
 * 且不在 banned 裡的單字。大小寫不敏感，回傳答案一律使用小寫。標點符號不屬於
 * 單字；題目保證至少有一個未被禁用的單字，而且答案唯一。
 *
 * 範例：
 * 1. paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
 *    banned = ["hit"]，回傳 "ball"。hit 出現三次但被禁用；ball 忽略大小寫後出現兩次。
 * 2. paragraph = "a."，banned = []，回傳 "a"。
 *
 * 限制：
 * - 1 <= paragraph.length <= 1000。
 * - paragraph 只包含英文字母、空格，以及 ! ? ' , ; . 這些標點符號。
 * - 0 <= banned.length <= 100；每個 banned 單字長度介於 1 到 10，且只含小寫字母。
 *
 * 解題思路：
 * 1. 從左到右讀取 paragraph；英文字母轉成小寫並組成目前單字，遇到空格或標點
 *    就代表單字結束。
 * 2. 若單字不在 banned 中，查找計數表：出現過就加一，否則新增一筆並設為 1。
 * 3. 所有單字處理完後，找出計數最大的單字並複製到新配置的字串回傳。
 * 4. 暫存的計數表與單字都釋放；回傳字串由呼叫端使用完後釋放。
 *
 * 複雜度：令 P 為 paragraph 長度、U 為不同單字數、B 為禁用字數。此簡單
 * 計數表的時間為 O(P * (U + B))，最壞 O(P^2 + P*B)；額外空間 O(P)。
 */
#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *word;
    int count;
} WordCount;

static int isBannedWord(const char *word, char **banned, int bannedSize) {
    int i;
    for (i = 0; i < bannedSize; ++i) {
        if (strcmp(word, banned[i]) == 0) return 1;
    }
    return 0;
}

char* mostCommonWord(char* paragraph, char** banned, int bannedSize) {
    int paragraphSize = (int)strlen(paragraph);
    char **words = (char**)calloc((size_t)paragraphSize + 1, sizeof(char*));
    int *counts = (int*)calloc((size_t)paragraphSize + 1, sizeof(int));
    char token[1001];
    int tokenSize = 0;
    int uniqueCount = 0;
    int i;
    int best = 0;
    char *answer;

    /* 非字母字元是分隔符；轉小寫後比較可忽略大小寫差異。 */
    for (i = 0; i <= paragraphSize; ++i) {
        unsigned char ch = (unsigned char)paragraph[i];
        if (isalpha(ch)) {
            token[tokenSize++] = (char)tolower(ch);
        } else if (tokenSize > 0) {
            int j;
            token[tokenSize] = '\0';
            if (!isBannedWord(token, banned, bannedSize)) {
                for (j = 0; j < uniqueCount; ++j) {
                    if (strcmp(words[j], token) == 0) break;
                }
                if (j < uniqueCount) {
                    counts[j]++;
                } else {
                    words[uniqueCount] = (char*)malloc((size_t)tokenSize + 1);
                    strcpy(words[uniqueCount], token);
                    counts[uniqueCount] = 1;
                    uniqueCount++;
                }
            }
            tokenSize = 0;
        }
    }

    for (i = 1; i < uniqueCount; ++i) {
        if (counts[i] > counts[best]) best = i;
    }
    answer = (char*)malloc(strlen(words[best]) + 1);
    strcpy(answer, words[best]);

    for (i = 0; i < uniqueCount; ++i) free(words[i]);
    free(words);
    free(counts);
    return answer;
}

int main(void) {
    char paragraph1[] = "Bob hit a ball, the hit BALL flew far after it was hit.";
    char *banned1[] = {"hit"};
    char paragraph2[] = "a.";
    char *answer;

    answer = mostCommonWord(paragraph1, banned1, 1);
    assert(strcmp(answer, "ball") == 0);
    free(answer);

    answer = mostCommonWord(paragraph2, NULL, 0);
    assert(strcmp(answer, "a") == 0);
    free(answer);

    puts("PASS 0819 mostCommonWord");
    return 0;
}
