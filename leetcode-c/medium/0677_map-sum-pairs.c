/*
 * Title-CN: 字串映射求和
 * LeetCode 677. Map Sum Pairs
 *
 * 題意翻譯：設計一個資料結構，支援將字串 key 設成整數 value，以及查詢所有
 * 以指定 prefix 開頭的 key，其 value 總和。若重新插入同一個 key，要用新值取代舊值。
 *
 * 範例：插入 ("apple",3) 後，sum("ap")=3；再插入 ("app",2)，sum("ap")=5。
 *
 * 限制：key 與 prefix 只含小寫英文字母，長度不超過 50；value 為 0 到 1000。
 *
 * 解題思路：使用 Trie。每個節點保存所有經過該節點的 value 總和。插入 key 時，
 * 先找到終點舊值，計算差額，再把差額加到根節點與整條路徑上；查詢 prefix 時，
 * 走到 prefix 對應節點，該節點的總和就是答案。
 *
 * 複雜度：插入與查詢皆 O(L)，L 為字串長度；空間 O(所有不同前綴數)。
 * LeetCode 介面：保留 MapSum 操作與 mapSumFree；main() 僅供本機測試。
 */

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct TrieNode {
    struct TrieNode *children[26];
    int sum;
    int value;
    bool hasValue;
} TrieNode;

typedef struct {
    TrieNode *root;
} MapSum;

static TrieNode *newTrieNode(void) {
    return calloc(1, sizeof(TrieNode));
}

MapSum *mapSumCreate(void) {
    MapSum *map = malloc(sizeof(*map));
    if (map == NULL) return NULL;
    map->root = newTrieNode();
    if (map->root == NULL) {
        free(map);
        return NULL;
    }
    return map;
}

void mapSumInsert(MapSum *obj, char *key, int value) {
    TrieNode *path[51];
    int length = 0;
    TrieNode *node = obj->root;
    path[length++] = node;
    for (char *p = key; *p != '\0'; ++p) {
        int index = *p - 'a';
        if (node->children[index] == NULL) {
            node->children[index] = newTrieNode();
            if (node->children[index] == NULL) return;
        }
        node = node->children[index];
        path[length++] = node;
    }

    int oldValue = node->hasValue ? node->value : 0;
    int difference = value - oldValue;
    for (int i = 0; i < length; ++i) path[i]->sum += difference;
    node->value = value;
    node->hasValue = true;
}

int mapSumSum(MapSum *obj, char *prefix) {
    TrieNode *node = obj->root;
    for (char *p = prefix; *p != '\0'; ++p) {
        node = node->children[*p - 'a'];
        if (node == NULL) return 0;
    }
    return node->sum;
}

static void freeTrie(TrieNode *node) {
    if (node == NULL) return;
    for (int i = 0; i < 26; ++i) freeTrie(node->children[i]);
    free(node);
}

void mapSumFree(MapSum *obj) {
    if (obj == NULL) return;
    freeTrie(obj->root);
    free(obj);
}

int main(void) {
    MapSum *map = mapSumCreate();
    assert(map != NULL);
    char apple[] = "apple";
    char app[] = "app";
    char ap[] = "ap";
    char missing[] = "banana";
    mapSumInsert(map, apple, 3);
    assert(mapSumSum(map, ap) == 3);
    mapSumInsert(map, app, 2);
    assert(mapSumSum(map, ap) == 5);
    mapSumInsert(map, apple, 2);
    assert(mapSumSum(map, ap) == 4);
    assert(mapSumSum(map, missing) == 0);
    mapSumFree(map);
    return 0;
}
