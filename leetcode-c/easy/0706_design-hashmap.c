/*
 * Title-CN: 設計雜湊映射
 * LeetCode 706. Design HashMap
 *
 * 題意翻譯：設計不重複 key 的映射，支援新增或更新 key-value、查詢 key、刪除 key。
 * 查詢不存在的 key 時回傳 -1。
 *
 * 範例：put(1,10)、put(2,20) 後 get(1)=10；再 put(1,15) 後 get(1)=15；
 * 移除 2 後 get(2)=-1。
 *
 * 限制：key 介於 0 到 10^6；value 介於 0 到 10^6；操作次數不超過 10^4。
 *
 * 解題思路：用兩個直接定址陣列：一個存 value，另一個標記該 key 是否存在。
 * put 覆寫 value 並設為存在；remove 清除存在標記；get 先檢查標記再回傳值。
 * 獨立的存在陣列可正確處理 value 本身為 0 的情況。
 *
 * 複雜度：每個操作 O(1)，空間 O(10^6)。
 * LeetCode 介面：保留 MyHashMap 操作與 myHashMapFree；main() 僅供本機測試。
 */

#include <assert.h>
#include <stdlib.h>

#define KEY_LIMIT 1000000

typedef struct {
    int *values;
    unsigned char *present;
} MyHashMap;

MyHashMap *myHashMapCreate(void) {
    MyHashMap *map = malloc(sizeof(*map));
    if (map == NULL) return NULL;
    map->values = malloc(((size_t)KEY_LIMIT + 1) * sizeof(*map->values));
    map->present = calloc((size_t)KEY_LIMIT + 1, sizeof(*map->present));
    if (map->values == NULL || map->present == NULL) {
        free(map->values);
        free(map->present);
        free(map);
        return NULL;
    }
    return map;
}

void myHashMapPut(MyHashMap *obj, int key, int value) {
    obj->values[key] = value;
    obj->present[key] = 1;
}

int myHashMapGet(MyHashMap *obj, int key) {
    return obj->present[key] ? obj->values[key] : -1;
}

void myHashMapRemove(MyHashMap *obj, int key) {
    obj->present[key] = 0;
}

void myHashMapFree(MyHashMap *obj) {
    if (obj == NULL) return;
    free(obj->values);
    free(obj->present);
    free(obj);
}

int main(void) {
    MyHashMap *map = myHashMapCreate();
    assert(map != NULL);
    myHashMapPut(map, 1, 10);
    myHashMapPut(map, 2, 20);
    assert(myHashMapGet(map, 1) == 10 && myHashMapGet(map, 3) == -1);
    myHashMapPut(map, 1, 15);
    assert(myHashMapGet(map, 1) == 15);
    myHashMapRemove(map, 2);
    assert(myHashMapGet(map, 2) == -1);
    myHashMapPut(map, 0, 0);
    assert(myHashMapGet(map, 0) == 0);
    myHashMapFree(map);
    return 0;
}
