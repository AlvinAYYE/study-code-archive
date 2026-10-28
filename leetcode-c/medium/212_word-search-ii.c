/*
 * LeetCode 212. Word Search II／單字搜尋 II
 *
 * 題目（繁體中文）
 *   給定由小寫英文字母組成的 m×n 棋盤，以及一份單字清單，請找出清單中
 *   所有能在棋盤上拼出的單字。每次只能走到上下左右相鄰的格子；同一條
 *   單字路徑不能重複使用同一格。答案順序不限，每個單字只回傳一次。
 *
 * 範例 1：board=[[o,a,a,n],[e,t,a,e],[i,h,k,r],[i,f,l,v]]，
 *   words=["oath","pea","eat","rain"]，輸出 ["eat","oath"]。
 * 範例 2：board=[[a,b],[c,d]]，words=["abcb"]，輸出 []；拼到第二個 b
 *   時必須回到已使用過的格子，因此這個單字不能成立。
 * 限制：1 <= m,n <= 12；1 <= words.length <= 3×10^4；
 *   每個單字長度 1..10；棋盤和單字只含小寫英文字母，清單內單字不重複。
 *
 * 解題步驟：
 *   1. 先把所有單字放進 Trie（前綴樹），共享相同開頭的單字也共享前綴節點。
 *   2. 從棋盤每一格開始 DFS；每走一步就沿 Trie 的對應字母往下走。
 *   3. 若 Trie 沒有目前前綴，就立刻停止這條路，不再嘗試無用路徑。
 *   4. 暫時把走過的格子標記，回溯時還原；找到單字後清除終點標記，避免重複。
 *   5. Trie 分支已沒有待找單字時就刪除，減少後續搜尋工作。
 *   建 Trie 時間 O(所有字元數)；搜尋最壞 O(mn×3^L)，L 為單字最大長度，
 *   實際會由 Trie 前綴剪枝大幅減少。Trie 空間 O(所有字元數)，另有 O(L)
 *   DFS 堆疊及 O(答案字元數) 的回傳空間。
 *
 * LeetCode C API：char** findWords(char** board, int boardSize,
 * int* boardColSize, char** words, int wordsSize, int* returnSize)。回傳字串
 * 與陣列皆由本函式配置；本機測試中的 main 與型別定義不屬於提交所需內容。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TrieNode {
    struct TrieNode *children[26];
    char *word;
} TrieNode;

typedef struct {
    char **results;
    int resultSize;
    int failed;
} SearchContext;

static TrieNode *newTrieNode(void) {
    return (TrieNode *)calloc(1, sizeof(TrieNode));
}

static void freeTrie(TrieNode *node) {
    if (node == NULL) return;
    for (int i = 0; i < 26; ++i) freeTrie(node->children[i]);
    free(node);
}

static int insertWord(TrieNode *root, char *word) {
    TrieNode *node = root;
    for (const char *p = word; *p != '\0'; ++p) {
        int index = *p - 'a';
        if (node->children[index] == NULL) {
            node->children[index] = newTrieNode();
            if (node->children[index] == NULL) return 0;
        }
        node = node->children[index];
    }
    node->word = word;
    return 1;
}

static char *copyString(const char *source) {
    size_t length = strlen(source) + 1;
    char *copy = (char *)malloc(length);
    if (copy != NULL) memcpy(copy, source, length);
    return copy;
}

static int isEmptyTrieNode(const TrieNode *node) {
    if (node->word != NULL) return 0;
    for (int i = 0; i < 26; ++i) {
        if (node->children[i] != NULL) return 0;
    }
    return 1;
}

static void searchFrom(char **board, int *boardColSize, int rows,
                       int row, int column, TrieNode *parent,
                       SearchContext *context) {
    if (context->failed || row < 0 || row >= rows || column < 0 ||
        column >= boardColSize[row] || board[row][column] == '#') return;

    char letter = board[row][column];
    int index = letter - 'a';
    TrieNode *node = parent->children[index];
    if (node == NULL) return;

    if (node->word != NULL) {
        char *found = copyString(node->word);
        if (found == NULL) {
            context->failed = 1;
            return;
        }
        context->results[context->resultSize++] = found;
        node->word = NULL; /* 單字已回傳，不讓其他路徑重複加入。 */
    }

    board[row][column] = '#';
    searchFrom(board, boardColSize, rows, row - 1, column, node, context);
    searchFrom(board, boardColSize, rows, row + 1, column, node, context);
    searchFrom(board, boardColSize, rows, row, column - 1, node, context);
    searchFrom(board, boardColSize, rows, row, column + 1, node, context);
    board[row][column] = letter; /* 回溯後恢復棋盤，供其他路徑使用。 */

    if (!context->failed && isEmptyTrieNode(node)) {
        free(node);
        parent->children[index] = NULL;
    }
}

/* ---------- LeetCode submission / 提交區 ---------- */
char **findWords(char **board, int boardSize, int *boardColSize,
                 char **words, int wordsSize, int *returnSize) {
    if (returnSize == NULL) return NULL;
    *returnSize = 0;
    if (board == NULL || boardColSize == NULL || words == NULL ||
        boardSize <= 0 || wordsSize <= 0) return NULL;

    TrieNode *root = newTrieNode();
    char **results = (char **)malloc((size_t)wordsSize * sizeof *results);
    if (root == NULL || results == NULL) {
        freeTrie(root);
        free(results);
        return NULL;
    }
    int built = 1;
    for (int i = 0; i < wordsSize; ++i) {
        if (!insertWord(root, words[i])) {
            built = 0;
            break;
        }
    }
    if (!built) {
        freeTrie(root);
        free(results);
        return NULL;
    }

    SearchContext context = {results, 0, 0};
    for (int row = 0; row < boardSize && !context.failed; ++row) {
        for (int column = 0; column < boardColSize[row] && !context.failed;
             ++column) {
            searchFrom(board, boardColSize, boardSize, row, column,
                       root, &context);
        }
    }
    freeTrie(root);

    if (context.failed) {
        for (int i = 0; i < context.resultSize; ++i) free(results[i]);
        free(results);
        return NULL;
    }
    if (context.resultSize == 0) {
        free(results);
        return NULL;
    }
    *returnSize = context.resultSize;
    return results;
}
/* ---------- end submission ---------- */

static int containsWord(char **results, int resultSize, const char *word) {
    for (int i = 0; i < resultSize; ++i) {
        if (strcmp(results[i], word) == 0) return 1;
    }
    return 0;
}

static void releaseWords(char **results, int resultSize) {
    for (int i = 0; i < resultSize; ++i) free(results[i]);
    free(results);
}

int main(void) {
    char row0[] = "oaan", row1[] = "etae", row2[] = "ihkr", row3[] = "iflv";
    char *board[] = {row0, row1, row2, row3};
    int columns[] = {4, 4, 4, 4};
    char *words[] = {"oath", "pea", "eat", "rain"};
    int resultSize = 0;
    char **found = findWords(board, 4, columns, words, 4, &resultSize);
    int passed = resultSize == 2 && containsWord(found, resultSize, "eat") &&
                 containsWord(found, resultSize, "oath") &&
                 strcmp(row0, "oaan") == 0 && strcmp(row1, "etae") == 0 &&
                 strcmp(row2, "ihkr") == 0 && strcmp(row3, "iflv") == 0;
    releaseWords(found, resultSize);

    char small0[] = "ab", small1[] = "cd";
    char *smallBoard[] = {small0, small1};
    int smallColumns[] = {2, 2};
    char *impossible[] = {"abcb"};
    found = findWords(smallBoard, 2, smallColumns, impossible, 1, &resultSize);
    passed = passed && found == NULL && resultSize == 0;

    puts(passed ? "PASS: 212 word-search-ii" : "FAIL: 212 word-search-ii");
    return passed ? 0 : 1;
}
