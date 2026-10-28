/*
 * LeetCode 380. Insert Delete GetRandom O(1)
 * Title-CN: 常數時間插入、刪除與隨機取值
 *
 * 題目翻譯：實作 RandomizedSet，支援插入整數、刪除整數及隨機取出目前集合中的一個值。
 * 插入時若值已存在就回傳 false，否則加入並回傳 true；刪除時若值不存在就回傳 false，
 * 否則移除並回傳 true。getRandom 必須讓集合中每個值被選中的機率相同。
 * 三種操作平均都要 O(1) 時間。
 *
 * 操作範例：insert(1)->true，remove(2)->false，insert(2)->true；
 * getRandom() 可回傳 1 或 2；remove(1)->true，insert(2)->false，最後 getRandom()->2。
 *
 * 限制：-2^31 <= val <= 2^31-1；insert、remove、getRandom 總呼叫次數最多 2*10^5；
 * 呼叫 getRandom 時保證集合非空。
 *
 * 解題思路：用動態陣列存所有值，並用雜湊表記錄「值 -> 陣列索引」。
 * 1. 插入：雜湊表查重，沒有重複時把值放到陣列尾端，並記錄它的索引。
 * 2. 刪除：找到該值索引後，把陣列最後一個值搬到空位，更新搬動值的索引，再縮短陣列。
 *    這樣不必在陣列中間搬動大量元素。
 * 3. 隨機取值：在陣列索引範圍內均勻抽一個位置。陣列每格只放一個集合元素，因此每個值等機率。
 *
 * 複雜度：insert、remove、getRandom 平均 O(1)；雜湊表可能碰撞，插入與查找為平均時間。
 * 空間 O(n)，n 為集合元素數。
 *
 * LeetCode C API：
 * RandomizedSet *randomizedSetCreate(void);
 * bool randomizedSetInsert(RandomizedSet *obj, int val);
 * bool randomizedSetRemove(RandomizedSet *obj, int val);
 * int randomizedSetGetRandom(RandomizedSet *obj);
 * void randomizedSetFree(RandomizedSet *obj);
 */
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int key;
    size_t index;
    unsigned char state; /* 0=空格、1=使用中、2=刪除標記 */
} HashEntry;

typedef struct {
    int *values;
    size_t size;
    size_t valueCapacity;
    HashEntry *table;
    size_t tableCapacity;
    size_t usedCount;
    size_t tombstoneCount;
    uint32_t randomState;
} RandomizedSet;

static uint32_t hashInteger(int value) {
    uint32_t x = (uint32_t)value;
    x ^= x >> 16;
    x *= UINT32_C(0x7feb352d);
    x ^= x >> 15;
    x *= UINT32_C(0x846ca68b);
    x ^= x >> 16;
    return x;
}

static HashEntry *findEntry(RandomizedSet *obj, int key) {
    size_t slot = (size_t)hashInteger(key) & (obj->tableCapacity - 1);
    while (obj->table[slot].state != 0) {
        if (obj->table[slot].state == 1 && obj->table[slot].key == key) {
            return &obj->table[slot];
        }
        slot = (slot + 1) & (obj->tableCapacity - 1);
    }
    return NULL;
}

static HashEntry *findInsertSlot(RandomizedSet *obj, int key) {
    size_t slot = (size_t)hashInteger(key) & (obj->tableCapacity - 1);
    HashEntry *firstTombstone = NULL;

    while (obj->table[slot].state != 0) {
        if (obj->table[slot].state == 2 && firstTombstone == NULL) {
            firstTombstone = &obj->table[slot];
        }
        slot = (slot + 1) & (obj->tableCapacity - 1);
    }
    return firstTombstone != NULL ? firstTombstone : &obj->table[slot];
}

static int rebuildTable(RandomizedSet *obj, size_t newCapacity) {
    HashEntry *newTable = (HashEntry *)calloc(newCapacity, sizeof *newTable);
    if (newTable == NULL) return 0;

    for (size_t i = 0; i < obj->tableCapacity; ++i) {
        HashEntry old = obj->table[i];
        if (old.state != 1) continue;

        size_t slot = (size_t)hashInteger(old.key) & (newCapacity - 1);
        while (newTable[slot].state == 1) slot = (slot + 1) & (newCapacity - 1);
        newTable[slot] = old;
    }

    free(obj->table);
    obj->table = newTable;
    obj->tableCapacity = newCapacity;
    obj->tombstoneCount = 0;
    return 1;
}

static int ensureValueCapacity(RandomizedSet *obj, size_t needed) {
    if (obj->valueCapacity >= needed) return 1;

    size_t newCapacity = obj->valueCapacity == 0 ? 16 : obj->valueCapacity * 2;
    while (newCapacity < needed) newCapacity *= 2;
    int *newValues = (int *)realloc(obj->values, newCapacity * sizeof *newValues);
    if (newValues == NULL) return 0;
    obj->values = newValues;
    obj->valueCapacity = newCapacity;
    return 1;
}

static uint32_t nextRandom(RandomizedSet *obj) {
    uint32_t x = obj->randomState;
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    obj->randomState = x;
    return x;
}

/* xorshift32 會循環走訪所有非零 32 位狀態；拒絕尾端餘數，避免取模造成偏差。 */
static uint32_t randomBelow(RandomizedSet *obj, uint32_t bound) {
    uint32_t range = UINT32_MAX;
    uint32_t limit = range - range % bound;
    uint32_t value;
    do {
        value = nextRandom(obj) - 1;
    } while (value >= limit);
    return value % bound;
}

RandomizedSet *randomizedSetCreate(void) {
    RandomizedSet *obj = (RandomizedSet *)calloc(1, sizeof *obj);
    if (obj == NULL) return NULL;

    if (!rebuildTable(obj, 32)) {
        free(obj);
        return NULL;
    }
    obj->randomState = (uint32_t)time(NULL) ^ (uint32_t)(uintptr_t)obj ^ UINT32_C(0x9e3779b9);
    if (obj->randomState == 0) obj->randomState = UINT32_C(0x6d2b79f5);
    return obj;
}

bool randomizedSetInsert(RandomizedSet *obj, int val) {
    if (obj == NULL || findEntry(obj, val) != NULL) return false;

    if (!ensureValueCapacity(obj, obj->size + 1)) return false;

    size_t projectedUsed = obj->usedCount + 1;
    size_t projectedOccupied = obj->usedCount + obj->tombstoneCount + 1;
    if (projectedOccupied * 10 >= obj->tableCapacity * 7) {
        size_t newCapacity = obj->tableCapacity;
        if (projectedUsed * 10 >= obj->tableCapacity * 7) newCapacity *= 2;
        if (!rebuildTable(obj, newCapacity)) return false;
    }

    size_t index = obj->size;
    obj->values[obj->size++] = val;
    HashEntry *entry = findInsertSlot(obj, val);
    if (entry->state == 2) --obj->tombstoneCount;
    entry->key = val;
    entry->index = index;
    entry->state = 1;
    ++obj->usedCount;
    return true;
}

bool randomizedSetRemove(RandomizedSet *obj, int val) {
    if (obj == NULL) return false;

    HashEntry *entry = findEntry(obj, val);
    if (entry == NULL) return false;

    size_t removedIndex = entry->index;
    size_t lastIndex = obj->size - 1;
    if (removedIndex != lastIndex) {
        int movedValue = obj->values[lastIndex];
        obj->values[removedIndex] = movedValue;
        HashEntry *movedEntry = findEntry(obj, movedValue);
        movedEntry->index = removedIndex;
    }

    entry->state = 2;
    --obj->usedCount;
    ++obj->tombstoneCount;
    --obj->size;
    return true;
}

int randomizedSetGetRandom(RandomizedSet *obj) {
    if (obj == NULL || obj->size == 0) return 0;
    size_t index = (size_t)randomBelow(obj, (uint32_t)obj->size);
    return obj->values[index];
}

void randomizedSetFree(RandomizedSet *obj) {
    if (obj == NULL) return;
    free(obj->values);
    free(obj->table);
    free(obj);
}

int main(void) {
    RandomizedSet *set = randomizedSetCreate();
    if (set == NULL) return 1;

    int passed = randomizedSetInsert(set, 1);
    passed = !randomizedSetRemove(set, 2) && passed;
    passed = randomizedSetInsert(set, 2) && passed;
    int randomValue = randomizedSetGetRandom(set);
    passed = (randomValue == 1 || randomValue == 2) && passed;
    passed = randomizedSetRemove(set, 1) && passed;
    passed = !randomizedSetInsert(set, 2) && passed;
    passed = randomizedSetGetRandom(set) == 2 && passed;

    passed = randomizedSetInsert(set, 10) && passed;
    passed = randomizedSetInsert(set, 20) && passed;
    passed = randomizedSetInsert(set, 30) && passed;
    passed = randomizedSetRemove(set, 20) && passed;
    passed = !randomizedSetRemove(set, 20) && passed;
    for (int i = 0; i < 20; ++i) {
        randomValue = randomizedSetGetRandom(set);
        if (randomValue != 2 && randomValue != 10 && randomValue != 30) passed = 0;
    }

    randomizedSetFree(set);
    puts(passed ? "PASS: 380 insert-delete-getrandom-o1"
                : "FAIL: 380 insert-delete-getrandom-o1");
    return passed ? 0 : 1;
}
