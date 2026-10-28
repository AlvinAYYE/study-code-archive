/*
 * LeetCode 472. Concatenated Words
 * 題意（繁體中文）：給定一組不重複的小寫英文單字，找出所有能由字典中
 * 至少兩個較短單字接在一起組成的單字。同一個單字可在組合中重複使用。
 *
 * 範例：
 *   ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses",
 *    "rat","ratcatdogcat"] -> ["catsdogcats","dogcatsdog","ratcatdogcat"]
 *   ["cat","dog","catdog"] -> ["catdog"]
 *
 * 限制：單字數最多 10000；每字長度最多 30；總字元數最多 100000；只含小寫字母。
 * 解法：依字長由短到長處理。檢查一個字時，Trie 只放入先前較短的字；
 *       用 dp[i] 記錄前 i 個字元最少能切成幾個字典單字。dp[字長] 至少為 2
 *       就是答案。檢查完再把目前單字加入 Trie，避免單字把自己算成答案。
 * 複雜度：令 N 為單字數、L 為最大字長，時間 O(NL^2)，空間 O(總字元數)。
 * LeetCode C API：char** findAllConcatenatedWordsInADict(char** words,
 *                       int wordsSize, int* returnSize)
 */
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int child[26];
    unsigned char terminal;
} TrieNode;

typedef struct {
    char *word;
    int length;
} WordRef;

static int compareWords(const void *left, const void *right) {
    const WordRef *a = (const WordRef *)left;
    const WordRef *b = (const WordRef *)right;
    return (a->length > b->length) - (a->length < b->length);
}

static void initializeNode(TrieNode *nodes, int index) {
    for (int i = 0; i < 26; ++i) nodes[index].child[i] = -1;
    nodes[index].terminal = 0;
}

static void insertWord(TrieNode *nodes, int *nodeCount, const char *word) {
    int node = 0;
    for (int i = 0; word[i] != '\0'; ++i) {
        int letter = word[i] - 'a';
        if (nodes[node].child[letter] == -1) {
            int created = (*nodeCount)++;
            initializeNode(nodes, created);
            nodes[node].child[letter] = created;
        }
        node = nodes[node].child[letter];
    }
    nodes[node].terminal = 1;
}

static int canSplitIntoAtLeastTwo(const TrieNode *nodes, const char *word, int length) {
    int pieces[31];
    for (int i = 0; i <= length; ++i) pieces[i] = INT_MAX;
    pieces[0] = 0;
    for (int start = 0; start < length; ++start) {
        if (pieces[start] == INT_MAX) continue;
        int node = 0;
        for (int end = start; end < length; ++end) {
            int letter = word[end] - 'a';
            node = nodes[node].child[letter];
            if (node == -1) break;
            if (nodes[node].terminal && pieces[end + 1] > pieces[start] + 1)
                pieces[end + 1] = pieces[start] + 1;
        }
    }
    return pieces[length] >= 2 && pieces[length] != INT_MAX;
}

char** findAllConcatenatedWordsInADict(char** words, int wordsSize, int* returnSize) {
    *returnSize = 0;
    if (wordsSize <= 0) return NULL;

    size_t totalLength = 0;
    WordRef *sorted = (WordRef *)malloc((size_t)wordsSize * sizeof *sorted);
    char **answer = (char **)malloc((size_t)wordsSize * sizeof *answer);
    if (sorted == NULL || answer == NULL) {
        free(sorted);
        free(answer);
        return NULL;
    }
    for (int i = 0; i < wordsSize; ++i) {
        sorted[i] = (WordRef){words[i], (int)strlen(words[i])};
        totalLength += (size_t)sorted[i].length;
    }
    qsort(sorted, (size_t)wordsSize, sizeof *sorted, compareWords);

    TrieNode *nodes = (TrieNode *)malloc((totalLength + 1) * sizeof *nodes);
    if (nodes == NULL) {
        free(sorted);
        free(answer);
        return NULL;
    }
    initializeNode(nodes, 0);
    int nodeCount = 1;
    for (int i = 0; i < wordsSize; ++i) {
        if (canSplitIntoAtLeastTwo(nodes, sorted[i].word, sorted[i].length))
            answer[(*returnSize)++] = sorted[i].word;
        insertWord(nodes, &nodeCount, sorted[i].word);
    }
    free(nodes);
    free(sorted);
    return answer;
}

static int containsWord(char **words, int count, const char *target) {
    for (int i = 0; i < count; ++i)
        if (strcmp(words[i], target) == 0) return 1;
    return 0;
}

int main(void) {
    char *example1[] = {"cat", "cats", "catsdogcats", "dog", "dogcatsdog",
                        "hippopotamuses", "rat", "ratcatdogcat"};
    int count1 = 0;
    char **answer1 = findAllConcatenatedWordsInADict(example1, 8, &count1);
    int passed = answer1 != NULL && count1 == 3 &&
                 containsWord(answer1, count1, "catsdogcats") &&
                 containsWord(answer1, count1, "dogcatsdog") &&
                 containsWord(answer1, count1, "ratcatdogcat");
    free(answer1);

    char *example2[] = {"cat", "dog", "catdog"};
    int count2 = 0;
    char **answer2 = findAllConcatenatedWordsInADict(example2, 3, &count2);
    passed = passed && answer2 != NULL && count2 == 1 &&
             strcmp(answer2[0], "catdog") == 0;
    free(answer2);
    puts(passed ? "PASS: 472 concatenated-words" : "FAIL: 472 concatenated-words");
    return passed ? 0 : 1;
}
