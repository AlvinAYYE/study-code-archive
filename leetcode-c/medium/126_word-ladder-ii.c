/*
 * LeetCode 126. Word Ladder II／單字接龍 II
 *
 * 題目（繁體中文）
 *   給定起始單字 beginWord、目標單字 endWord 和字典 wordList。每一步只能
 *   改變一個字母，而且改完的單字必須在字典中。請回傳從 beginWord 到
 *   endWord 的所有最短轉換序列；若無法到達，回傳空集合。序列中包含起點
 *   與終點，答案順序不限。
 *
 * 範例 1：beginWord="hit"，endWord="cog"，
 *   wordList=["hot","dot","dog","lot","log","cog"]
 *   輸出：[hit,hot,dot,dog,cog] 與 [hit,hot,lot,log,cog]
 *   兩條路徑都只需要 4 次字母替換。
 * 範例 2：wordList=["hot","dot","dog","lot","log"]，缺少 "cog"，輸出 []。
 * 限制：單字長度 1..5；字典有 1..500 個互不重複的小寫單字；
 *   beginWord 與 endWord 長度相同且不相同；最短答案總數不超過 10^5。
 *
 * 解題步驟：
 *   1. 把字典中的單字看成圖上的節點；兩字只差一個字母時，就能互相轉換。
 *   2. 從 beginWord 做 BFS，記下每個單字第一次到達的步數。
 *   3. 若另一條邊也能以相同步數到達某字，就把這個前一個單字也記起來；
 *      這樣保留了所有最短路徑，而不是只保留其中一條。
 *   4. 從 endWord 沿著「最短路徑前一站」往回走，列出全部路徑。
 *   BFS 時間 O(N^2 L)，其中 N 是字典單字數、L 是單字長度；列舉另需
 *   O(輸出中單字總數 × L) 時間。前驅圖 O(N^2)，輸出空間依答案大小而定。
 *
 * LeetCode C API：函式回傳已配置的路徑陣列，欄數放在
 * returnColumnSizes；本檔也複製每個單字字串，呼叫端可逐層釋放。
 * struct 與 main 僅供本機測試。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *items;
    int size;
    int capacity;
} IntList;

typedef struct {
    char **words;
    IntList *parents;
    int *path;
    int start;
    char ***results;
    int *columnSizes;
    int resultSize;
    int resultCapacity;
    int failed;
} LadderContext;

static char *copyString(const char *source) {
    size_t length = strlen(source) + 1;
    char *copy = (char *)malloc(length);
    if (copy != NULL) memcpy(copy, source, length);
    return copy;
}

static int appendInt(IntList *list, int value) {
    if (list->size == list->capacity) {
        int newCapacity = list->capacity == 0 ? 4 : list->capacity * 2;
        int *grown = (int *)realloc(list->items,
                                    (size_t)newCapacity * sizeof *grown);
        if (grown == NULL) return 0;
        list->items = grown;
        list->capacity = newCapacity;
    }
    list->items[list->size++] = value;
    return 1;
}

static void freeResults(char ***results, int *columnSizes, int count) {
    if (results != NULL) {
        for (int i = 0; i < count; ++i) {
            if (results[i] != NULL) {
                for (int j = 0; j < columnSizes[i]; ++j) free(results[i][j]);
                free(results[i]);
            }
        }
    }
    free(results);
    free(columnSizes);
}

static int reserveResultSlot(LadderContext *context) {
    if (context->resultSize < context->resultCapacity) return 1;

    int newCapacity = context->resultCapacity == 0 ? 8 : context->resultCapacity * 2;
    char ***newResults = (char ***)malloc(
        (size_t)newCapacity * sizeof *newResults);
    int *newColumns = (int *)malloc((size_t)newCapacity * sizeof *newColumns);
    if (newResults == NULL || newColumns == NULL) {
        free(newResults);
        free(newColumns);
        return 0;
    }
    if (context->resultSize > 0) {
        memcpy(newResults, context->results,
               (size_t)context->resultSize * sizeof *newResults);
        memcpy(newColumns, context->columnSizes,
               (size_t)context->resultSize * sizeof *newColumns);
    }
    free(context->results);
    free(context->columnSizes);
    context->results = newResults;
    context->columnSizes = newColumns;
    context->resultCapacity = newCapacity;
    return 1;
}

static void saveCurrentPath(LadderContext *context, int depth) {
    int length = depth + 1;
    char **row = (char **)malloc((size_t)length * sizeof *row);
    if (row == NULL) {
        context->failed = 1;
        return;
    }

    /* path 從終點往起點存，輸出時反向複製成起點到終點。 */
    int copied = 0;
    for (; copied < length; ++copied) {
        row[copied] = copyString(context->words[context->path[depth - copied]]);
        if (row[copied] == NULL) break;
    }
    if (copied != length) {
        for (int i = 0; i < copied; ++i) free(row[i]);
        free(row);
        context->failed = 1;
        return;
    }
    if (!reserveResultSlot(context)) {
        for (int i = 0; i < length; ++i) free(row[i]);
        free(row);
        context->failed = 1;
        return;
    }
    context->results[context->resultSize] = row;
    context->columnSizes[context->resultSize] = length;
    ++context->resultSize;
}

static void collectShortestPaths(LadderContext *context, int current, int depth) {
    if (context->failed) return;
    context->path[depth] = current;
    if (current == context->start) {
        saveCurrentPath(context, depth);
        return;
    }
    for (int i = 0; i < context->parents[current].size; ++i) {
        collectShortestPaths(context, context->parents[current].items[i], depth + 1);
        if (context->failed) return;
    }
}

static int differsByOne(const char *first, const char *second, int length) {
    int differences = 0;
    for (int i = 0; i < length; ++i) {
        if (first[i] != second[i] && ++differences > 1) return 0;
    }
    return differences == 1;
}

/* ---------- LeetCode submission / 提交區 ---------- */
char ***findLadders(char *beginWord, char *endWord, char **wordList,
                    int wordListSize, int *returnSize,
                    int **returnColumnSizes) {
    if (returnSize == NULL || returnColumnSizes == NULL) return NULL;
    *returnSize = 0;
    *returnColumnSizes = NULL;
    if (beginWord == NULL || endWord == NULL || wordList == NULL ||
        wordListSize <= 0) return NULL;

    int start = -1, end = -1;
    for (int i = 0; i < wordListSize; ++i) {
        if (strcmp(wordList[i], beginWord) == 0) start = i;
        if (strcmp(wordList[i], endWord) == 0) end = i;
    }
    /* 依題意，終點必須在字典中；起點則可以不在字典中。 */
    if (end < 0) return NULL;

    int nodeCount = wordListSize + (start < 0 ? 1 : 0);
    if (start < 0) start = wordListSize;
    size_t wordLength = strlen(beginWord);
    char **words = (char **)malloc((size_t)nodeCount * sizeof *words);
    IntList *parents = (IntList *)calloc((size_t)nodeCount, sizeof *parents);
    int *distance = (int *)malloc((size_t)nodeCount * sizeof *distance);
    int *queue = (int *)malloc((size_t)nodeCount * sizeof *queue);
    int *path = (int *)malloc((size_t)nodeCount * sizeof *path);
    if (words == NULL || parents == NULL || distance == NULL || queue == NULL ||
        path == NULL) {
        free(words); free(parents); free(distance); free(queue); free(path);
        return NULL;
    }
    for (int i = 0; i < wordListSize; ++i) words[i] = wordList[i];
    if (start == wordListSize) words[start] = beginWord;
    for (int i = 0; i < nodeCount; ++i) distance[i] = -1;

    int head = 0, tail = 0;
    distance[start] = 0;
    queue[tail++] = start;
    int failed = 0;
    while (head < tail && !failed) {
        int current = queue[head++];
        for (int next = 0; next < nodeCount; ++next) {
            if (!differsByOne(words[current], words[next], (int)wordLength)) continue;
            if (distance[next] == -1) {
                distance[next] = distance[current] + 1;
                queue[tail++] = next;
            }
            if (distance[next] == distance[current] + 1 &&
                !appendInt(&parents[next], current)) {
                failed = 1;
                break;
            }
        }
    }

    LadderContext context = {0};
    context.words = words;
    context.parents = parents;
    context.path = path;
    context.start = start;
    if (!failed && distance[end] >= 0) {
        collectShortestPaths(&context, end, 0);
    }

    for (int i = 0; i < nodeCount; ++i) free(parents[i].items);
    free(parents);
    free(distance);
    free(queue);
    free(path);
    free(words);

    if (failed || context.failed) {
        freeResults(context.results, context.columnSizes, context.resultSize);
        return NULL;
    }
    *returnSize = context.resultSize;
    *returnColumnSizes = context.columnSizes;
    return context.results;
}
/* ---------- end submission ---------- */

static void releaseReturnedPaths(char ***paths, int *columns, int count) {
    freeResults(paths, columns, count);
}

static int isExpectedPath(char **path, int length, const char *const *expected,
                          int expectedLength) {
    if (length != expectedLength) return 0;
    for (int i = 0; i < length; ++i) {
        if (strcmp(path[i], expected[i]) != 0) return 0;
    }
    return 1;
}

int main(void) {
    char *words[] = {"hot", "dot", "dog", "lot", "log", "cog"};
    const char *const expected1[] = {"hit", "hot", "dot", "dog", "cog"};
    const char *const expected2[] = {"hit", "hot", "lot", "log", "cog"};
    int resultSize = 0;
    int *columns = NULL;
    char ***paths = findLadders("hit", "cog", words, 6, &resultSize, &columns);
    int found1 = 0, found2 = 0;
    for (int i = 0; i < resultSize; ++i) {
        found1 |= isExpectedPath(paths[i], columns[i], expected1, 5);
        found2 |= isExpectedPath(paths[i], columns[i], expected2, 5);
    }
    int passed = resultSize == 2 && found1 && found2;
    releaseReturnedPaths(paths, columns, resultSize);

    char *missingEnd[] = {"hot", "dot", "dog"};
    paths = findLadders("hit", "cog", missingEnd, 3, &resultSize, &columns);
    passed = passed && paths == NULL && resultSize == 0 && columns == NULL;

    puts(passed ? "PASS: 126 word-ladder-ii" : "FAIL: 126 word-ladder-ii");
    return passed ? 0 : 1;
}
