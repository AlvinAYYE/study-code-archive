/*
 * LeetCode 208. Implement Trie (Prefix Tree)
 * Title-CN: 實作 Trie（前綴樹）
 *
 * 題目翻譯：實作 Trie，支援建立空 Trie、插入單字、查詢完整單字是否曾插入，
 * 以及查詢是否有已插入的單字以指定 prefix 開頭。前綴存在不代表完整單字存在。
 *
 * 操作範例：
 * 建立 Trie；insert("apple")；search("apple") -> true；search("app") -> false；
 * startsWith("app") -> true；insert("app")；search("app") -> true。
 *
 * 限制：word、prefix 長度 1 到 2000；只含小寫英文字母；insert、search、startsWith
 * 的總呼叫次數最多 3 * 10^4。
 *
 * 解題思路：每個 Trie 節點有 26 個子節點，分別代表 a 到 z，並用 isWord 標記單字是否在此結束。
 * 1. 插入時逐字母往下走；缺少的子節點就建立，最後將節點標成完整單字結尾。
 * 2. 搜尋與前綴查詢都沿著字母路徑前進；途中缺少子節點就代表不存在。
 * 3. search 最後還要確認 isWord；startsWith 只要整條前綴路徑存在即可。
 *
 * 複雜度：令 L 為字串長度，三種操作各需 O(L) 時間；空間 O(所有字串的不同前綴總數)。
 *
 * LeetCode C API：
 * Trie *trieCreate(void);
 * void trieInsert(Trie *obj, char *word);
 * bool trieSearch(Trie *obj, char *word);
 * bool trieStartsWith(Trie *obj, char *prefix);
 * void trieFree(Trie *obj);
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct TrieNode {
    struct TrieNode *children[26];
    bool isWord;
} TrieNode;

typedef struct {
    TrieNode *root;
} Trie;

static TrieNode *createTrieNode(void) {
    return (TrieNode *)calloc(1, sizeof(TrieNode));
}

Trie *trieCreate(void) {
    Trie *obj = (Trie *)malloc(sizeof *obj);
    if (obj == NULL) return NULL;

    obj->root = createTrieNode();
    if (obj->root == NULL) {
        free(obj);
        return NULL;
    }
    return obj;
}

void trieInsert(Trie *obj, char *word) {
    if (obj == NULL || obj->root == NULL || word == NULL) return;

    TrieNode *node = obj->root;
    for (const char *letter = word; *letter != '\0'; ++letter) {
        int index = *letter - 'a';
        if (node->children[index] == NULL) {
            node->children[index] = createTrieNode();
            if (node->children[index] == NULL) return;
        }
        node = node->children[index];
    }
    node->isWord = true;
}

static TrieNode *findTrieNode(Trie *obj, const char *text) {
    if (obj == NULL || obj->root == NULL || text == NULL) return NULL;

    TrieNode *node = obj->root;
    for (const char *letter = text; *letter != '\0'; ++letter) {
        int index = *letter - 'a';
        node = node->children[index];
        if (node == NULL) return NULL;
    }
    return node;
}

bool trieSearch(Trie *obj, char *word) {
    TrieNode *node = findTrieNode(obj, word);
    return node != NULL && node->isWord;
}

bool trieStartsWith(Trie *obj, char *prefix) {
    return findTrieNode(obj, prefix) != NULL;
}

static void freeTrieNode(TrieNode *node) {
    if (node == NULL) return;
    for (int i = 0; i < 26; ++i) freeTrieNode(node->children[i]);
    free(node);
}

void trieFree(Trie *obj) {
    if (obj == NULL) return;
    freeTrieNode(obj->root);
    free(obj);
}

int main(void) {
    Trie *trie = trieCreate();
    if (trie == NULL) return 1;

    trieInsert(trie, "apple");
    int passed = trieSearch(trie, "apple") &&
                 !trieSearch(trie, "app") &&
                 trieStartsWith(trie, "app") &&
                 !trieStartsWith(trie, "apz");
    trieInsert(trie, "app");
    passed = passed && trieSearch(trie, "app");

    trieFree(trie);
    puts(passed ? "PASS: 208 implement-trie-prefix-tree"
                : "FAIL: 208 implement-trie-prefix-tree");
    return passed ? 0 : 1;
}
