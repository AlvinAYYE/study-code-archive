/*
 * LeetCode 2788. Split Strings by Separator
 * Title-CN: 依分隔符切割字串
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/split-strings-by-separator/
 *
 * [中文] 題目說明
 *     給定字串陣列 words 和單一字元 separator，將每個字串依分隔字元切開，
 *     把所有切出的片段依原本順序串成新陣列。切割產生的空字串要忽略。
 *
 * [中文] 範例
 *     1. words = [one.two.three,four.five,six]、separator = '.'，
 *        輸出 [one,two,three,four,five,six]。
 *     2. words = [$easy$,$problem$]、separator = '$'，輸出 [easy,problem]。
 *     3. words = [|||]、separator = '|'，輸出空陣列 []。
 *
 * [中文] 限制
 *     - 1 <= words.length <= 100；每個字串長度為 1 到 20。
 *     - 字元為小寫英文字母或 . , | $ # @；separator 也是其中之一。
 *
 * [中文] 解題步驟
 *     1. 逐字掃描每個輸入字串，把 separator 與字串結尾都視為片段邊界。
 *     2. 邊界之間有內容才配置新字串並複製；空片段直接略過。
 *     3. 回傳字串指標陣列及片段數。若輸入總字元數為 L，時間 O(L)，
 *        回傳內容所需額外空間 O(L)。
 *
 * LeetCode C 函式簽名：
 *     char** splitWordsBySeparator(char** words, int wordsSize,
 *                                  char separator, int* returnSize)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **splitWordsBySeparator(char **words, int wordsSize, char separator, int *returnSize) {
    int totalLength = 0, wordIndex, resultCount = 0;
    char **result;
    for (wordIndex = 0; wordIndex < wordsSize; ++wordIndex) {
        totalLength += (int)strlen(words[wordIndex]);
    }
    result = (char **)malloc((size_t)totalLength * sizeof(char *));
    for (wordIndex = 0; wordIndex < wordsSize; ++wordIndex) {
        int start = 0, position = 0;
        while (1) {
            if (words[wordIndex][position] == separator || words[wordIndex][position] == '\0') {
                int length = position - start;
                if (length > 0) {
                    char *part = (char *)malloc((size_t)length + 1);
                    memcpy(part, words[wordIndex] + start, (size_t)length);
                    part[length] = '\0';
                    result[resultCount++] = part;
                }
                if (words[wordIndex][position] == '\0') break;
                start = position + 1;
            }
            ++position;
        }
    }
    *returnSize = resultCount;
    return result;
}

static int matches(char **actual, int actualSize, const char **expected, int expectedSize) {
    int i;
    if (actualSize != expectedSize) return 0;
    for (i = 0; i < expectedSize; ++i) {
        if (strcmp(actual[i], expected[i]) != 0) return 0;
    }
    return 1;
}

static void freeWords(char **words, int size) {
    int i;
    for (i = 0; i < size; ++i) free(words[i]);
    free(words);
}

int main(void) {
    int ok = 1, size;
    char *input1[] = {"one.two.three", "four.five", "six"};
    const char *expected1[] = {"one", "two", "three", "four", "five", "six"};
    char *input2[] = {"$easy$", "$problem$"};
    const char *expected2[] = {"easy", "problem"};
    char *input3[] = {"|||"};
    char **answer = splitWordsBySeparator(input1, 3, '.', &size);
    ok = ok && matches(answer, size, expected1, 6);
    freeWords(answer, size);
    answer = splitWordsBySeparator(input2, 2, '$', &size);
    ok = ok && matches(answer, size, expected2, 2);
    freeWords(answer, size);
    answer = splitWordsBySeparator(input3, 1, '|', &size);
    ok = ok && size == 0;
    freeWords(answer, size);
    printf("%s: 2788 split-strings-by-separator\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
