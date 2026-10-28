/*
 * Title-CN: 設計雜湊集合
 * LeetCode 705. Design HashSet
 *
 * 題意翻譯：設計不允許重複值的集合，支援新增 key、刪除 key，以及查詢 key 是否存在。
 *
 * 範例：新增 1、2 後，contains(1) 為 true、contains(3) 為 false；刪除 2 後，
 * contains(2) 為 false。
 *
 * 限制：key 介於 0 到 10^6；操作次數不超過 10^4。
 *
 * 解題思路：題目的 key 範圍固定且不大，直接用索引等於 key 的布林陣列記錄是否存在。
 * 新增設為 true，刪除設為 false，查詢直接讀取陣列。
 *
 * 複雜度：每個操作 O(1)，空間 O(10^6)。
 * LeetCode 介面：保留 MyHashSet 操作與 myHashSetFree；main() 僅供本機測試。
 */

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#define KEY_LIMIT 1000000

typedef struct {
    unsigned char *present;
} MyHashSet;

MyHashSet *myHashSetCreate(void) {
    MyHashSet *set = malloc(sizeof(*set));
    if (set == NULL) return NULL;
    set->present = calloc((size_t)KEY_LIMIT + 1, sizeof(*set->present));
    if (set->present == NULL) {
        free(set);
        return NULL;
    }
    return set;
}

void myHashSetAdd(MyHashSet *obj, int key) {
    obj->present[key] = 1;
}

void myHashSetRemove(MyHashSet *obj, int key) {
    obj->present[key] = 0;
}

bool myHashSetContains(MyHashSet *obj, int key) {
    return obj->present[key] != 0;
}

void myHashSetFree(MyHashSet *obj) {
    if (obj == NULL) return;
    free(obj->present);
    free(obj);
}

int main(void) {
    MyHashSet *set = myHashSetCreate();
    assert(set != NULL);
    myHashSetAdd(set, 1);
    myHashSetAdd(set, 2);
    assert(myHashSetContains(set, 1));
    assert(!myHashSetContains(set, 3));
    myHashSetAdd(set, 2);
    myHashSetRemove(set, 2);
    assert(!myHashSetContains(set, 2));
    myHashSetFree(set);
    return 0;
}
