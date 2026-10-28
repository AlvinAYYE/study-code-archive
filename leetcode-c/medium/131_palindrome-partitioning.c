/*
 * LeetCode 131. Palindrome Partitioning／回文分割
 * 題目：將字串 s 切成多個連續子字串，要求每一段都是回文；回傳所有可能切法。
 *
 * 範例 1：s="aab" -> [["a","a","b"],["aa","b"]]。
 * 範例 2：s="a" -> [["a"]]。
 * 限制：1 <= s.length <= 16；s 只包含小寫英文字母。
 *
 * 解題步驟：
 *   1. 先用動態規劃預算每個 s[left..right] 是否為回文。
 *   2. 從字串開頭回溯，逐一嘗試所有以目前位置開頭的回文片段。
 *   3. 把片段加入目前切法，再遞迴處理片段後面的字元；返回時撤銷選擇。
 *   4. 走到字串尾端時，複製目前切法並加入答案。
 *   若有 P 種切法、字串長 n，預處理 O(n^2)，列舉與輸出 O(P*n)；
 *   回溯狀態 O(n)，回傳答案本身需 O(P*n) 空間。
 *
 * LeetCode 會接收配置完成的 char*** 與每列長度陣列；本檔 main 會逐一釋放。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LENGTH 16
#define MAX_PARTITIONS (1 << (MAX_TEXT_LENGTH - 1))

typedef struct {
    const char *text;
    int length;
    int palindrome[MAX_TEXT_LENGTH][MAX_TEXT_LENGTH];
    int starts[MAX_TEXT_LENGTH];
    int ends[MAX_TEXT_LENGTH];
    int pathLength;
    char ***answers;
    int *columnSizes;
    int answerCount;
    int failed;
} PartitionContext;

static char *copyRange(const char *text, int start, int end) {
    int length = end - start + 1;
    char *copy = (char *)malloc((size_t)length + 1);
    if (copy == NULL) return NULL;
    memcpy(copy, text + start, (size_t)length);
    copy[length] = '\0';
    return copy;
}

static void searchPartitions(PartitionContext *context, int start) {
    if (context->failed) return;
    if (start == context->length) {
        int pathLength = context->pathLength;
        char **row = (char **)malloc((size_t)pathLength * sizeof *row);
        if (row == NULL) {
            context->failed = 1;
            return;
        }
        for (int i = 0; i < pathLength; ++i) {
            row[i] = copyRange(context->text,
                               context->starts[i], context->ends[i]);
            if (row[i] == NULL) {
                while (i > 0) free(row[--i]);
                free(row);
                context->failed = 1;
                return;
            }
        }
        context->answers[context->answerCount] = row;
        context->columnSizes[context->answerCount] = pathLength;
        ++context->answerCount;
        return;
    }

    /* 只選回文片段，剩下的字元交給下一層遞迴切分。 */
    for (int end = start; end < context->length; ++end) {
        if (context->palindrome[start][end]) {
            context->starts[context->pathLength] = start;
            context->ends[context->pathLength] = end;
            ++context->pathLength;
            searchPartitions(context, end + 1);
            --context->pathLength;
            if (context->failed) return;
        }
    }
}

static void freeAnswers(char ***answers, int *columnSizes, int count) {
    if (answers != NULL) {
        for (int i = 0; i < count; ++i) {
            for (int j = 0; j < columnSizes[i]; ++j) free(answers[i][j]);
            free(answers[i]);
        }
    }
    free(answers);
    free(columnSizes);
}

/* ---------- LeetCode submission / 提交區 ---------- */
char ***partition(char *s, int *returnSize, int **returnColumnSizes) {
    PartitionContext context = {0};
    int capacity;

    *returnSize = 0;
    *returnColumnSizes = NULL;
    if (s == NULL || s[0] == '\0') return NULL;

    context.text = s;
    context.length = (int)strlen(s);
    if (context.length > MAX_TEXT_LENGTH) return NULL;

    /* 長度 1 的字串一定是回文；較長字串使用兩端相等與內層狀態判斷。 */
    for (int left = context.length - 1; left >= 0; --left) {
        for (int right = left; right < context.length; ++right) {
            context.palindrome[left][right] =
                s[left] == s[right] &&
                (right - left < 2 || context.palindrome[left + 1][right - 1]);
        }
    }

    capacity = 1 << (context.length - 1);
    context.answers = (char ***)malloc((size_t)capacity * sizeof *context.answers);
    context.columnSizes = (int *)malloc((size_t)capacity * sizeof *context.columnSizes);
    if (context.answers == NULL || context.columnSizes == NULL) {
        free(context.answers);
        free(context.columnSizes);
        return NULL;
    }

    searchPartitions(&context, 0);
    if (context.failed) {
        freeAnswers(context.answers, context.columnSizes, context.answerCount);
        return NULL;
    }

    *returnSize = context.answerCount;
    *returnColumnSizes = context.columnSizes;
    return context.answers;
}
/* ---------- end submission ---------- */

static int rowEquals(char **row, int size, const char *const expected[]) {
    for (int i = 0; i < size; ++i) {
        if (strcmp(row[i], expected[i]) != 0) return 0;
    }
    return 1;
}

static int containsPartition(char ***answers, int *columnSizes, int count,
                             const char *const expected[], int expectedSize) {
    for (int i = 0; i < count; ++i) {
        if (columnSizes[i] == expectedSize &&
            rowEquals(answers[i], expectedSize, expected)) {
            return 1;
        }
    }
    return 0;
}

int main(void) {
    char text1[] = "aab";
    char text2[] = "a";
    int count1 = 0, count2 = 0;
    int *columns1 = NULL, *columns2 = NULL;
    char ***answers1 = partition(text1, &count1, &columns1);
    char ***answers2 = partition(text2, &count2, &columns2);
    const char *partitionA[] = {"a", "a", "b"};
    const char *partitionB[] = {"aa", "b"};
    const char *partitionSingle[] = {"a"};
    int passed = answers1 != NULL && count1 == 2 &&
                 containsPartition(answers1, columns1, count1, partitionA, 3) &&
                 containsPartition(answers1, columns1, count1, partitionB, 2) &&
                 answers2 != NULL && count2 == 1 &&
                 rowEquals(answers2[0], columns2[0], partitionSingle);

    freeAnswers(answers1, columns1, count1);
    freeAnswers(answers2, columns2, count2);
    puts(passed ? "PASS: 131 palindrome-partitioning"
                : "FAIL: 131 palindrome-partitioning");
    return passed ? 0 : 1;
}
