/*
 * LeetCode 68. Text Justification／文字左右對齊
 * 題目（繁體中文）
 *   給定單字陣列 words 與行寬 maxWidth，將文字排成每行恰好 maxWidth 個字元。
 *   每行先盡量放入最多單字；一般行的空格平均分配在單字間，若無法平均，
 *   左側空格槽要比右側多。最後一行靠左對齊，單字間只放一個空格，行尾補空格。
 *   若某行只有一個單字，也靠左對齊並在行尾補空格。單字長度不超過行寬。
 *   words 最多 300 個；單字長 1～20 字元；maxWidth 為 1～100。
 *
 * 例子（maxWidth = 16）
 *   ["This","is","an","example","of","text","justification."] 會排成：
 *   "This    is    an"
 *   "example  of text"
 *   "justification.  "
 *   最後一行只在行尾補空格；中間行將多出的空格優先放在左側空格槽。
 *
 * 解題思路
 *   1. 從目前尚未排版的第一個單字開始，盡可能把下一個單字放進本行。
 *      計算時先把單字間最少的一格空白算進去。
 *   2. 若是最後一行或本行只有一個單字，用單一空格連接，剩餘空間補在行尾。
 *   3. 其他行先算每個空格槽至少要放幾格，再把剩餘格數依序加到左側槽。
 *   4. 本行完成後繼續處理下一行。每個字元只寫入一次，時間 O(輸出總字元數)，
 *      輸出空間 O(輸出總字元數)，不計輸出時額外空間 O(1)。
 *
 * LeetCode 提交時保留 stdlib.h、string.h 與「提交區」即可。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ---------- LeetCode submission / 提交區 ---------- */
char **fullJustify(char **words, int wordsSize, int maxWidth, int *returnSize) {
    char **lines = (char **)malloc((size_t)wordsSize * sizeof *lines);
    int lineCount = 0;
    int start = 0;

    *returnSize = 0;
    if (lines == NULL) return NULL;

    while (start < wordsSize) {
        int end = start;
        int letters = 0;

        /* 先決定這一行可以放到哪個單字，不含實際空格分布。 */
        while (end < wordsSize) {
            int length = (int)strlen(words[end]);
            int minimumWidth = letters + length + (end - start);
            if (minimumWidth > maxWidth) break;
            letters += length;
            end++;
        }

        int wordCount = end - start;
        int slots = wordCount - 1;
        int spaces = maxWidth - letters;
        char *line = (char *)malloc((size_t)maxWidth + 1);
        int output = 0;
        if (line == NULL) {
            for (int i = 0; i < lineCount; i++) free(lines[i]);
            free(lines);
            return NULL;
        }

        for (int i = start; i < end; i++) {
            int length = (int)strlen(words[i]);
            memcpy(line + output, words[i], (size_t)length);
            output += length;

            if (i == end - 1) continue;
            if (end == wordsSize || slots == 0) {
                line[output++] = ' ';   /* 最後一行／單字行：每槽一格 */
            } else {
                int gap = spaces / slots;
                int extra = spaces % slots;
                int slot = i - start;
                for (int count = 0; count < gap + (slot < extra); count++) {
                    line[output++] = ' ';
                }
            }
        }
        while (output < maxWidth) line[output++] = ' ';
        line[output] = '\0';
        lines[lineCount++] = line;
        start = end;
    }

    *returnSize = lineCount;
    return lines;
}
/* ---------- end submission ---------- */

static int checkLines(char **words, int wordCount, int width,
                      const char **expected, int expectedCount) {
    int count = 0;
    char **actual = fullJustify(words, wordCount, width, &count);
    int ok = actual != NULL && count == expectedCount;
    for (int i = 0; ok && i < count; i++) {
        ok = strlen(actual[i]) == (size_t)width && strcmp(actual[i], expected[i]) == 0;
    }
    if (actual != NULL) {
        for (int i = 0; i < count; i++) free(actual[i]);
        free(actual);
    }
    return ok;
}

int main(void) {
    char *words1[] = {"This", "is", "an", "example", "of", "text", "justification."};
    const char *expected1[] = {"This    is    an", "example  of text", "justification.  "};
    char *words2[] = {"What", "must", "be", "acknowledgment", "shall", "be"};
    const char *expected2[] = {"What   must   be", "acknowledgment  ", "shall be        "};
    char *words3[] = {"a"};
    const char *expected3[] = {"a    "};

    if (!checkLines(words1, 7, 16, expected1, 3) ||
        !checkLines(words2, 6, 16, expected2, 3) ||
        !checkLines(words3, 1, 5, expected3, 1)) {
        puts("FAIL: 068 text-justification");
        return 1;
    }
    puts("PASS: 068 text-justification");
    return 0;
}
