/*
 * Title-CN: 移除註解
 * LeetCode 722. Remove Comments
 *
 * 題意翻譯：給定程式碼的逐行字串，移除雙斜線單行註解與斜線星號區塊註解。
 * 若多行註解跨越數行，註解前後的程式碼會接在同一行。回傳刪除註解與空行後的結果。
 *
 * 範例：若區塊註解從第一行的 a 之後開始，到第三行的 b 之前結束，結果會接成 "ab"。
 *
 * 限制：行數不超過 100；每行長度不超過 80；輸入為合法程式碼字元。
 *
 * 解題思路：逐字掃描並維護「目前是否在區塊註解內」。在區塊註解內只找結束標記；
 * 不在註解時遇到雙斜線就丟掉該行剩餘文字，遇到區塊註解起始標記就開始跳過內容。每行結束時，
 * 若區塊註解已關閉且累積文字非空，就把這段文字加入輸出；跨行註解中的文字會繼續累積。
 *
 * 複雜度：時間 O(C)，C 為輸入總字元數；額外空間 O(C)。
 * LeetCode 介面：保留 removeComments；main() 僅供本機測試。
 */

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

static char *copyPrefix(const char *text, size_t length) {
    char *copy = malloc(length + 1);
    if (copy == NULL) return NULL;
    memcpy(copy, text, length);
    copy[length] = '\0';
    return copy;
}

char **removeComments(char **source, int sourceSize, int *returnSize) {
    *returnSize = 0;
    size_t totalLength = 1;
    for (int i = 0; i < sourceSize; ++i) totalLength += strlen(source[i]);
    char **answer = sourceSize == 0 ? NULL : malloc((size_t)sourceSize * sizeof(*answer));
    char *current = malloc(totalLength);
    if ((sourceSize > 0 && answer == NULL) || current == NULL) {
        free(answer);
        free(current);
        return NULL;
    }

    bool inBlock = false;
    size_t used = 0;
    for (int line = 0; line < sourceSize; ++line) {
        const char *text = source[line];
        for (size_t i = 0; text[i] != '\0'; ++i) {
            if (inBlock) {
                if (text[i] == '*' && text[i + 1] == '/') {
                    inBlock = false;
                    ++i;
                }
            } else if (text[i] == '/' && text[i + 1] == '/') {
                break;
            } else if (text[i] == '/' && text[i + 1] == '*') {
                inBlock = true;
                ++i;
            } else {
                current[used++] = text[i];
            }
        }

        if (!inBlock && used > 0) {
            answer[*returnSize] = copyPrefix(current, used);
            if (answer[*returnSize] == NULL) {
                for (int i = 0; i < *returnSize; ++i) free(answer[i]);
                free(answer);
                free(current);
                *returnSize = 0;
                return NULL;
            }
            ++*returnSize;
            used = 0;
        }
    }
    free(current);
    return answer;
}

int main(void) {
    char l0[] = "/*Test program */";
    char l1[] = "int main()";
    char l2[] = " { ";
    char l3[] = "  // variable declaration ";
    char l4[] = "int a, b, c;";
    char l5[] = "/* This is a test";
    char l6[] = "   multiline ";
    char l7[] = "   comment for";
    char l8[] = "   testing */";
    char l9[] = "a = b + c;";
    char l10[] = "}";
    char *source[] = {l0, l1, l2, l3, l4, l5, l6, l7, l8, l9, l10};
    char **answer;
    int count = 0;
    answer = removeComments(source, 11, &count);
    const char *expected[] = {"int main()", " { ", "  ", "int a, b, c;", "a = b + c;", "}"};
    assert(count == 6);
    for (int i = 0; i < count; ++i) {
        assert(strcmp(answer[i], expected[i]) == 0);
        free(answer[i]);
    }
    free(answer);

    char c0[] = "a/*comment";
    char c1[] = "line";
    char c2[] = "more_comment*/b";
    char *combined[] = {c0, c1, c2};
    answer = removeComments(combined, 3, &count);
    assert(count == 1 && strcmp(answer[0], "ab") == 0);
    free(answer[0]);
    free(answer);
    return 0;
}
