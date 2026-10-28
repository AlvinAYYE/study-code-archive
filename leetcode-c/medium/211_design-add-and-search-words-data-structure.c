/*
 * LeetCode 211. Design Add and Search Words Data Structure
 * Title-CN: 設計加入與搜尋單字的資料結構
 *
 * 題目翻譯：設計 WordDictionary，支援加入小寫英文字，以及查詢某個字串是否能匹配已加入的單字。
 * 查詢中的 '.' 可以代替任意一個英文字母；其他字母必須完全相同。
 *
 * 操作範例：加入 "bad"、"dad"、"mad" 後：search("pad") -> false；
 * search("bad") -> true；search(".ad") -> true；search("b..") -> true。
 *
 * 限制：加入的 word 長度 1 到 25，且只含小寫英文字母；查詢字串只含小寫字母與 '.'，
 * 每次查詢最多 2 個 '.'；addWord 與 search 的呼叫總數最多 10^4。
 *
 * 解題思路：用 Trie 儲存單字。一般字母只沿對應子節點走；遇到 '.' 時，嘗試目前節點所有存在的
 * 子節點，只要有任一條路徑能走完整個查詢字串並停在單字結尾，就算匹配成功。
 * 1. addWord 逐字母建立節點，並在單字最後標記 isWord。
 * 2. search 遞迴檢查字串位置：普通字母走單一路徑，'.' 分支嘗試最多 26 種字母。
 * 3. 字串用完時，只有 isWord 為 true 才能回傳成功，避免把較長單字誤認成相符。
 *
 * 複雜度：令 L 為字串長度、d 為查詢中的點數；加入 O(L)，查詢最壞 O(26^d * L)，
 * 而題目限制 d <= 2；空間 O(所有已加入單字的不同前綴總數)。
 *
 * LeetCode C API：
 * WordDictionary *wordDictionaryCreate(void);
 * void wordDictionaryAddWord(WordDictionary *obj, char *word);
 * bool wordDictionarySearch(WordDictionary *obj, char *word);
 * void wordDictionaryFree(WordDictionary *obj);
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct WordTrieNode {
    struct WordTrieNode *children[26];
    bool isWord;
} WordTrieNode;

typedef struct {
    WordTrieNode *root;
} WordDictionary;

static WordTrieNode *createWordTrieNode(void) {
    return (WordTrieNode *)calloc(1, sizeof(WordTrieNode));
}

WordDictionary *wordDictionaryCreate(void) {
    WordDictionary *obj = (WordDictionary *)malloc(sizeof *obj);
    if (obj == NULL) return NULL;

    obj->root = createWordTrieNode();
    if (obj->root == NULL) {
        free(obj);
        return NULL;
    }
    return obj;
}

void wordDictionaryAddWord(WordDictionary *obj, char *word) {
    if (obj == NULL || obj->root == NULL || word == NULL) return;

    WordTrieNode *node = obj->root;
    for (const char *letter = word; *letter != '\0'; ++letter) {
        int index = *letter - 'a';
        if (node->children[index] == NULL) {
            node->children[index] = createWordTrieNode();
            if (node->children[index] == NULL) return;
        }
        node = node->children[index];
    }
    node->isWord = true;
}

static bool searchWordFrom(WordTrieNode *node, const char *word) {
    if (node == NULL) return false;
    if (*word == '\0') return node->isWord;

    if (*word != '.') {
        return searchWordFrom(node->children[*word - 'a'], word + 1);
    }

    for (int i = 0; i < 26; ++i) {
        if (node->children[i] != NULL && searchWordFrom(node->children[i], word + 1)) {
            return true;
        }
    }
    return false;
}

bool wordDictionarySearch(WordDictionary *obj, char *word) {
    return obj != NULL && obj->root != NULL && word != NULL &&
           searchWordFrom(obj->root, word);
}

static void freeWordTrieNode(WordTrieNode *node) {
    if (node == NULL) return;
    for (int i = 0; i < 26; ++i) freeWordTrieNode(node->children[i]);
    free(node);
}

void wordDictionaryFree(WordDictionary *obj) {
    if (obj == NULL) return;
    freeWordTrieNode(obj->root);
    free(obj);
}

int main(void) {
    WordDictionary *dictionary = wordDictionaryCreate();
    if (dictionary == NULL) return 1;

    wordDictionaryAddWord(dictionary, "bad");
    wordDictionaryAddWord(dictionary, "dad");
    wordDictionaryAddWord(dictionary, "mad");

    int passed = !wordDictionarySearch(dictionary, "pad") &&
                 wordDictionarySearch(dictionary, "bad") &&
                 wordDictionarySearch(dictionary, ".ad") &&
                 wordDictionarySearch(dictionary, "b..") &&
                 !wordDictionarySearch(dictionary, "..") &&
                 !wordDictionarySearch(dictionary, "b...");

    wordDictionaryFree(dictionary);
    puts(passed ? "PASS: 211 design-add-and-search-words-data-structure"
                : "FAIL: 211 design-add-and-search-words-data-structure");
    return passed ? 0 : 1;
}
